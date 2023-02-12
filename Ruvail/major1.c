/*	CSCE 3600 Major Project 1
	Authors: Ruvail Shahzad, Katherine Aquilone, Elizabeth Tan, Eric Teo
	Description: A program containing bitwise operations selected from a menu
*/
#include "major1.h"
#include "rotate.c"
#include "clz.c"

int main()
{
	int menu = 0;				//Holds menu choice input
	long long int hold = 0;		//Holds user input, used to detect negative numbers because unsigned int will underflow (*long is only 32-bit in Windows, use long long to be safe)
	unsigned int input = 0;		//Holds integer operand input, needs to be unsigned to accept numbers 2147483648 and higher within 32 bits
	int number;
	unsigned int bit_positions;
	while (menu != 5){
		printf("Enter the menu option for the operation to perform:\n");	//Print menu
		printf("(1) Count Leading Zeroes\n");
		printf("(2) Endian Swap\n");
		printf("(3) Rotate-right\n");
		printf("(4) Parity\n");
		printf("(5) EXIT\n");
		printf("--> ");
		scanf("%d", &menu);	//Read user input

		switch (menu){
			case 1:		//Selected Count Leading Zeroes
				do {																			//Loop until valid input is given
					printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");	//Prompt for input
					scanf("%lld", &hold);														//Read user input
				} while (hold < 1 || hold > 4294967295);										//Check input validity
				input = hold;																	//Convert validated long long int into unsigned int
				printf("The number of leading zeroes in %u is %u\n", input, clz(input));		//Call "clz" and output result
				
				break;
			case 2:	
		
				
				break;
			case 3:		//Selected Rotate-right
				//FIXME: Add rotate.c call
				
	printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
    scanf("%d",&number);
	while (number < 1) // check for wrong number
                {
                    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                    scanf("%d", &number);
                }
    
    
    printf("\nEnter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
    scanf("%d",&bit_positions);
    while (bit_positions < 0 || bit_positions > 31) // check for wrong bit positions
                {
                    printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
                    scanf("%d", &bit_positions);
                }
    
    printf("\n%d rotated by %d position gives: %d \n",number,bit_positions,rotate(number,bit_positions));
				
				break;
			case 4:		//Selected Parity
				//FIXME: Add parity.c call
				break;
			case 5:		//Selected EXIT, prints message and leaves loop after
				printf("Program terminating. Goodbye...\n");
				break;
			default:	//Invalid option, prints message and loops to menu after
				printf("Error: Invalid option. Please try again.\n");
		}
	}
	return 0;
}

//FIXME: Add comments
