#include<stdio.h>

int main()
{    
     float x, sum=1, t=1;
	 int i, a;
      
     printf(" Enter value of x : ");
     scanf("%f",&x);
     printf(" Enter value of a : ");
     scanf("%d",&a);
     x=x*3.14159/180;
     
    for(i=1;i<=a;i++)
    {
        t=t*(-1)*x*x/(2*i*(2*i-1));
        sum=sum+t;
  }
    printf(" The value of Cos(%f) is : %.4f\n", x, sum);
    system("pause");
    return 0;
}
