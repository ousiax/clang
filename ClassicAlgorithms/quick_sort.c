#include <stdio.h> 
#define SIZE 8 

static void print(int[] , int );
static void qsort(int[], int, int);
static void quick_sort(int[], int);
static int partition(int[], int, int);
static void swap(int*, int*);

int main()
{
    int arr[SIZE] ;
    int i, j, k;
    printf("Enter %d number:\n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf(".\n");

    quick_sort(arr, SIZE);

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

static void quick_sort(int list[], int len)
{
    qsort(list, 0, len - 1);
}

static void qsort(int list[], int low, int high)
{
    if (low < high)
    {
        int p = partition(list, low, high);
        qsort(list, low, p);
        qsort(list, p + 1, high);
    }
}

static int partition(int list[], int low, int high)
{
    int p = (low + high) / 2;
    int pivot = list[p];
    int l = low - 1;
    int h = high + 1;
    while (1)
    {
        do
        {
            l++;
        }
        while (list[l] < pivot);

        do
        {
            h--;
        }
        while (list[h] > pivot);

        if (l >= h)
        {
            return h;
        }
        swap(&list[l], &list[h]);
    }
}

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
