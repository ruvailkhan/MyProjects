// Name : Ruvail Shahzad
// EUID :rs0737
#include <stdio.h>
int main(void) {
	unsigned char input;
	int i;

// for getting AXCHII character from user
printf("Enter an ASCII character : ");
scanf("%c",&input);
printf("The ASCII value of %c is:\n",input);


// for decimal access specifier = %d
printf("\t dec -- %d\n",input);


// for hexadecimal access specifier = %X
printf("\t hex -- %X\n",input);


// for binary loop is use
printf("\t bin -- ");
for(i=7;i>=0;i--)
{
int temp=input>>i;
printf("%d",temp&1);
}

printf("\n");
return 0;
}
