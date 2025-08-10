#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000

int compare(const void *p1, const void *p2)
{
    int x = *(int *)p1;
    int y = *(int *)p2;
    return (x > y) - (x < y);
}

void print_arr(int *a, int *even, int n, int len_even)
{
    int i, j;
    for (i = 0, j = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            printf("%d ", even[j]);
            j++;
        }
        else
            printf("%d ", a[i]);
    }
}

int main()
{
    int a[N];
    int even[N];
    int len_even = 0;
    int n;
    int count = 0;

    scanf("%d", &n);
    for (int i = 0, j = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)
        {
            even[j] = a[i];
            len_even += 1;
            j++;
        }
    }
    // print_arr(a, n);
    qsort(even, len_even, sizeof(even[0]), compare);
    
    print_arr(a, even, n, len_even);

    return 0;
}
