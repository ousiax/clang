#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

static void print(int[] , int );

int main()
{
    int arr[SIZE] ;
    int i, j, k;
    printf("Enter %d number:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    printf("- - -\n");

    for (i = 0; i < SIZE; i++) {
        print(arr, SIZE);
        k = 0;
        for (j = 1; j < SIZE - i; j++) {
            if (arr[j - 1] - arr[j] > 0) {
                k++;
                arr[j - 1] = arr[j - 1] + arr[j];
                arr[j] = arr[j - 1] - arr[j];
                arr[j - 1] = arr[j - 1] - arr[j];
            }
        }
        if (k == 0) {
            break;
        }
    }
    print(arr, SIZE);

    exit(0);
}

static void print(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%-4d ", arr[i]);
    }
    printf("\n");
}
