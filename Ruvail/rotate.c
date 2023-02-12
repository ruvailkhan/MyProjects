/*	Author: Ruvail Shahzad
	Description: THIS function rotate the the given number to the given times.
*/

#define BITS 32
int rotate(int number,unsigned int bit_positions)
{  
    return (number>>bit_positions)|(number<<(BITS-bit_positions));
}
