// nixietube_encoder_serial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void digitalWrite(int pin, int value) {
	//dummy function doesn't do anything because this isn't an adrunio

	printf("pin: %d state: %d\n", pin, value);

	return;
}




void pulsePinByAmount(int intArray[], int size) {
	/*Tube Pin mappings
	D   C    B   A				ClockFeeds
	Tube1	2   3    4   5	s		26
	Tube2	6   7    8   9  s		27
	Tube3	10	11	12	13	m		28
	Tube4	14	15	16	17	m		29
	Tube5	18	19	20	21	h		30
	Tube6	22	23	24	25	h		31



	DCBA
	0000 - 0
	0001 - 1
	0010 - 2
	0011 - 3
	0100 - 4
	0101 - 5
	0110 - 6
	0111 - 7
	1000 - 8
	1001 - 9
	*/

	int pinSelector = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < intArray[i]; j++) {
			switch (i) {
			case 0:
				pinSelector = 26;
				break;
			case 1:
				pinSelector = 27;
				break;
			case 2:
				pinSelector = 28;
				break;
			case 3:
				pinSelector = 29;
				break;
			case 4:
				pinSelector = 30;
				break;
			case 5:
				pinSelector = 31;
				break;
			}
			digitalWrite(pinSelector, 1);
			digitalWrite(pinSelector, 0);
		}
	}



}




int main()
{
	int intArray[6] = {1,1,1,1,1,1};
	pulsePinByAmount(intArray, 6);
	

    return 0;
}

