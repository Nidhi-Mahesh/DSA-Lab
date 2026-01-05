#include <stdio.h>
#include <stdlib.h>

/*
heapify
main
*/

void heapify(int a[], int n)
{
    int i, k, v, j, flag;

    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = a[k];
        flag = 0;

        while (!flag && 2 * k <= n)
        {
            j = 2 * k;

            if (j < n && a[j] < a[j + 1])
                j = j + 1;

            if (v >= a[j])
                flag = 1;
            else
            {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

int main()
{
    int n = 0, i, a[11], ch;

    for (;;)
    {
        printf("\n1. Create Heap");
        printf("\n2. Extract Max");
        printf("\n3. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);

                printf("Enter elements:\n");
                for (i = 1; i <= n; i++)
                    scanf("%d", &a[i]);

                heapify(a, n);

                printf("Heap elements:\n");
                for (i = 1; i <= n; i++)
                    printf("%d\t", a[i]);
                printf("\n");
                break;

            case 2:
                if (n < 1)
                {
                    printf("\nHeap is empty. Cannot delete.\n");
                }
                else
                {
                    printf("\nDeleted element: %d\n", a[1]);
                    a[1] = a[n];
                    n--;

                    heapify(a, n);

                    if (n > 0)
                    {
                        printf("Heap after deletion:\n");
                        for (i = 1; i <= n; i++)
                            printf("%d\t", a[i]);
                        printf("\n");
                    }
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
