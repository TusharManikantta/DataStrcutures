#include<stdio.h>
void merge(int a[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;

    int A1[n1], A2[n2],i;
    for (i = 0; i < n1;i++)
    A1[i] = a[l+i];
    for (i = 0; i < n2; i++)
    A2[i] = a[m + 1 + i];
    int j = 0, k = l;
    i = 0;

    while (i<n1 && j<n2)
        {
            if (A1[i]<=A2[j])
                {
                    a[k]=A1[i];
                        i++;

                }
    else
            {
                a[k] = A2[j];

                j++;
            }

        k++;
}
        while (i<n1)
        {

            a[k] = A1[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            a[k] = A2[j];
            j++;
            k++;
        }

}
        void mergeSort(int a[], int l, int h)
        {
            if (l<h)
                {
                    int m = l + (h - l) / 2;

                    mergeSort(a, l, m);
                    mergeSort(a, m+1, h);
                    merge(a, l, m, h);
                }
        }

        
int main()
{
    int a[100], n, i;
    printf("Enter the size=");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
}
