#include<stdio.h>
int main()
{
 int i,j,n;
 printf("Enter the size=");
 scanf("%d",&n);
 int a[n];
 printf("Enter the elements:\n");
 for (i=0;i<n;i++)
 scanf("%d",&a[i]);
 for (i = 0; i < n - 1;i++)
 {
 int s= i;
 for (j = i + 1; j < n;j++)
 {
 if (a[s]>a[j])
 s=j;
 }
 int t=a[s];
a[s]=a[i];
a[i]=t;
 }
 printf("Sorted Array:\n");
 for (i = 0; i < n;i++)
 {
 printf("%d ",a[i]);
 }
}