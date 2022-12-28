#include<stdio.h>
int div(int a[],int l,int h)
{
    int pi = a[h],i=l-1,j;
    for ( j = l; j < h;j++)
    {
        if (a[j]<=pi)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j] = temp;
        }        
    }
    int temp = a[i + 1];
    a[i + 1] = a[h];
    a[h] = temp;
    return (i + 1);
}
void quickSort(int a[], int l, int h)
{
    if (l<h)
    {
        int p=div(a,l,h);
        quickSort(a, l, p - 1);
        quickSort(a, p+1, h);
    }
}
void main()
{
    int a[100], n, i;
    printf("Enter the size=");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a,0,n-1);
    for (i = 0; i < n;i++)
        printf("%d ", a[i]);
}
