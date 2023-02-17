#include <stdio.h>
#include <stdlib.h>
void binary_search(int ar[], int n, int low, int up, int item)
{
    int flag = 0, mid;
    if (low > up)
    {
        printf("0\n");
    }
    else
    {
        mid = (low + up) / 2;
        if (ar[mid] == item)
        {
            printf("%d\n", item);
        }
        else if (ar[mid] < item)
        {
            binary_search(ar, n, mid + 1, up, item);
        }
        else if (ar[mid] > item)
        {
            binary_search(ar, n, low, mid - 1, item);
        }
    }
}
void main()
{
    int ar[100], i, n, item, c;
    printf("Enter size of the array");
    scanf("%d", &n);
    printf("Enter Element in the array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\t", ar[i]);
    }
    while (1)
    {
        printf("Enter 1:for Binary search Enter 2:for Exit");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter item to be searched");
            scanf("%d", &item);
            binary_search(ar, n, 0, n - 1, item);
            break;
        case 2:
            printf("Programm end");
            exit(0);
        default:
            printf("Wrong choice");
            break;
        }
    }
}