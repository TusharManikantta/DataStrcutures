#include<stdio.h>
void main()
{
	int a[100],n,i,p;
	printf("Enter the size=");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
	int max1=a[0],b[n];
	for (i=0;i<n;i++)
	{
		if (max1<a[i])
			max1=a[i];
	}
	for (p=1;max1/p>0;p*=10)
	{
		int max2=(a[0]/p)%10;
		for (i=0;i<n;i++)
		{
			if (max2<((a[i]/p)%10))
				max2=(a[i]/p)%10;
		}
		int count[max2+1];
		for (i=0;i<max2+1;i++)
			count[i]=0;
		for (i=0;i<n;i++)
			count[(a[i]/p)%10]++;
		int k=0,j=0;
		while (k<max2+1)
		{
			if (count[k]>0)
			{
				for (i=0;i<n;i++)
				{
					if (k==((a[i]/p)%10))
					{
						b[j]=a[i];
						count[k]--;
						j++;
					}
				}
			}
			else
				k++;
		}
		for (i=0;i<n;i++)
			a[i]=b[i];
	}
	printf("Sorted array:\n");
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
}
