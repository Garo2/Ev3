/*
 \file		test.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
*/

#include <ev3.h>

int main(void)
{
	//TODO Place here your variables

	InitEV3();

	//TODO Place here your code
	if(IN_1 == 1){
	LcdPrintf(1, "Hello World!\n");
	Wait(SEC_2);
	}

	FreeEV3();
	return 0;
}
