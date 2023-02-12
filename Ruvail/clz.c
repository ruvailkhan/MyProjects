/*	Author: Eric Teo
	Description: A function that counts the number of leading zeroes in a 32-bit int,
	returning the number of binary leading zeroes from the unsigned input
*/

unsigned int clz(unsigned int input){	//Unsigned to avoid most significant bit error, no negative input
	unsigned int mask = 1 << 31; 		//Left shift 1 to most significant bit (32) to make a mask
	for (int i = 0; i < 32; i++){		//Repeat for all 32 bits
		if ((input & mask) != 0){		//AND input with the mask to check it the bit is 1
			return i;					//Return number of shifts needed to find the first "1" from the left
		}
		mask >>= 1;						//Right shift mask to check next most significant bit
	}
	return 32;							//If here, then input == 0 and has 32 leading zeroes
}