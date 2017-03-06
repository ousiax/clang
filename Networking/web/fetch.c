/* fetch.c -- print the index page from www.gnu.org and exit. */

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#define BSIZE 0x1000

static void fail(int test, const char *format, ...);
static void get_page(int fd, const char *host, const char *page);

int main(int argc, char *argv[])
{
    struct addrinfo hints, *res, *res0;
    int error;
    int sockfd;
    const char *host = "www.gnu.org";
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    error = getaddrinfo(host, "http", &hints, &res0);
    fail(error, gai_strerror(error));
    sockfd = -1;

    for(res = res0; res; res = res->ai_next) {
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        fail(sockfd < 0, "socket: %s\n", strerror(errno));

        if(connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
            fprintf(stderr, "connect: %s\n", strerror(errno));
            close(sockfd);
            exit(EXIT_SUCCESS);
        }

        break;
    }

    if(sockfd != -1) {
        get_page(sockfd, host, "/");
    }

    freeaddrinfo(res0);
    exit(EXIT_SUCCESS);
}

static void fail(int test, const char *format, ...)
{
    if(test) {
        va_list ap;
        va_start(ap, format);
        vfprintf(stderr, format, ap);
        va_end(ap);
        exit(EXIT_FAILURE);
    }
}

static void get_page(int fd, const char *host, const char *page)
{
    char *msg;
    const char *format =
        "GET %s HTTP/1.0\r\nHost: %s\r\nUser-Agent: fetch.c\r\n\r\n";
    int status;
    status = asprintf(&msg, format, page, host);
    printf("%s\n", msg);
    fail(status == -1 || !msg, "asprintf failed.\n");
    status = send(fd, msg, strlen(msg), 0);
    fail(status == -1, "send failed: %s\n", strerror(errno));

    while(true) {
        int bytes;
        char buf[BSIZE + 10];
        bytes = recvfrom(fd, buf, BSIZE, 0, 0, 0);

        if(bytes == 0) {
            break;
        }

        fail(bytes == -1, "%s\n", strerror(errno));
        buf[bytes] = '\0';
        printf("%s", buf);
    }

    free(msg);
}
