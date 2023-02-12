/*  File: major1.c
    Descripton: This file contains the menu system for the program.
*/
#include "major1.h"
#include "parity.c"
//#include "rotate.c"

int main()
{
    int choice = -1;

    while (choice != 5) // This while loop contains the menu for the program
    {
        int num; // the 32-bit number that is operated on
        int num2;// second 32-bit number needed for option 3
        printMenu(); // function to print the menu options
        printf("--> "); 
        scanf("%d", &choice); // reads in user choice

        switch (choice) // This switch statement checks the user choice and executes the appropriate functionality
        {
            case 1: // Count Leading Zeroes Caahc0082@cse01:~/major1$ cd major-1
//ahc0082@cse01:~/major1$ cd major-1

                
                printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): "); //prompt user to enter first number
                scanf("%d", &num);
                
                while (num < 1) // if user enters invalid number, continue to prompt them for a valid number
                {
                    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                    scanf("%d", &num);
                }
                
                break;

            case 2: // Endian Swap Case
                
                printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): "); //prompt user to enter first number
                scanf("%d", &num);
                
                while (num < 1) // if user enters invalid number, continue to prompt them for a valid number
                {
                    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                    scanf("%d", &num);
                }

                break;

            case 3: // Rotate-right case
                
                printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): "); //prompt user to enter first number
                scanf("%d", &num);
                
                while (num < 1) // if user enters invalid number, continue to prompt them for a valid number
                {
                    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                    scanf("%d", &num);
                }
                
                printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): "); //prompt user to enter second number
                scanf("%d", &num2);
                
                while (num2 < 0 || num2 > 31) // if user enters invalid number, continue to prompt them for a valid number
                {
                    printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
                    scanf("%d", &num2);
                }
                

                break;

            case 4: // Parity case
                  printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively):");
                   scanf("%d", &num);
                       printf("Parity of %d is %d\n", num, parity(num));
		while (!(num >= 1 && num  <= 4294967295))
               {
                   printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively):");
                   scanf("%d", &num);
               }
			      
		break;

            case 5:
                printf("Program terminating. Goodbye...\n");
                break;

            default:
                printf("Error: Invalid option. Please try again.\n");
                break;
        }
	}

    return 0;
}

void printMenu()
{
    printf("Enter the menu option for the operation to perform: \n");
    printf("(1) Count Leading Zeroes\n");
    printf("(2) Endian Swap\n");
    printf("(3) Rotate-right\n");
    printf("(4) Parity\n");
    printf("(5) EXIT\n");
}
