#include<stdio.h>
int main()
{
	int nterms=10,nth,x;
	int arr[10];
	int n1=0, n2 = 1;
	int count = 0;
	
	// first two terms
	n1=3;
	n2=5;
	arr[0]=n1;
	arr[1]=n2;
	
	// generate fibonacci sequence
	printf("Fibonacci sequence:\n");
    while (count < nterms)
    {
       arr[count]=n1;
       nth = n1 + n2;
       n1 = n2;
       n2 = nth;
       count += 1;
	}
	//print the complete fibonacci sequence
	for(x=0;x<10;x++)
	{
		printf("%d\n",arr[x]);
	}
	system("pause");
	return 0;
}
