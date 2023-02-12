#include <stdio.h>
#include <stdlib.h>

int main() 
{
	 int x, r;
	 
	 int v1[5]={1,3,5,7,9};
	 int v2[5]={0,2,4,6,8};
	 //finding dot product
	 for (x = 0, r = 0; x < 5; x ++) 
	 {
	  	r += v1[x] * v2[x];
	 }
	 
	 printf("Product: %d\n", r);
	 system("pause");
	 return 0;
}
