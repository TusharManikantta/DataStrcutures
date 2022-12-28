#include<stdio.h>
int main()
{
    int a[100],i,j,n,temp=0,min;
    printf("enter the no of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
    min=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
    }
    temp=a[i];
    a[i]=a[min];
    a[min]=temp;
    }
    printf("the sorted arrary elements are");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

}