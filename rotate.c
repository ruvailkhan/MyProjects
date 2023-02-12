#include <stdio.h>
#define BITS 32
int rotate(int number,unsigned int bit_positions)
{ //here we know, in number>>bit_positions the first bit_positions bits are 0. BITS-bit_positions gives the last digits and hence bitwise between number>>bit_positions) and number<<(BITS-bit_positions) will rotate the number right by bit_positions digits 
    return (number>>bit_positions)|(number<<(BITS-bit_positions));
}
int main()
{
    int number,bit_positions;
    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
    scanf("%d",&number);
    printf("\nEnter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
    scanf("%d",&bit_positions);
    printf("\n%d rotated by %d position gives: %d",number,bit_positions,rotate(number,bit_positions));
    return 0;
}
