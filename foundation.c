#include <stdio.h>
#include <ev3.h>

int findMinDistance();
void rotateMotor(int l);
void forward();
void touchSensor();
void dropBook();

int main() {

	InitEV3();
		/*
		 --!!!--- TESTA TOUCH-SENSOR SAMTIDIGT SOM FORWARD ---!!!---

		setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		int rightSensor = readSensor(IN_1);
		int leftSensor = readSensor(IN_3);



		while (rightSensor && leftSensor == 0) {
		    LcdPrintf(1, "Going Forward!\n");
		    OnRevSync(OUT_AB,30);

			if (rightSensor && leftSensor == 1) {
				Off(OUT_AB);
				LcdPrintf(1, "Båda touch sensor");
				Wait(SEC_1);
			}
			else if(rightSensor == 1) {
				Off(OUT_A);
				LcdPrintf(1, "Höger touch sensor");
				Wait(SEC_1);
			}
			else if (leftSensor == 1) {
				Off(OUT_B);
				LcdPrintf(1, "Vänster touch sensor");
				Wait(SEC_1);
			}
			else {
				LcdPrintf(1, "Ingen touch sensor");
				Wait(SEC_1);
			}
		}*/

    int indexTid = findMinDistance();
    int i;


    for(i = 0; i <= indexTid; i++) {
        rotateMotor(i);
    }
    Off(OUT_AB);
    Wait(SEC_2);

    touchSensor();

    forward(); // men 2,5 m

    //rotate90() beroende på mål

    dropBook();

	FreeEV3();
    return 0;
}


int findMinDistance () {
    int distance;
    int minDis;
    int arrayDis[8];
    int indexTidForMinDis;
    int j;
    int k;

    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);

    for(j = 0; j < 9; j++) {
        rotateMotor(j);
        distance = readSensor(IN_4);
        arrayDis[j] = distance;
        //LcdPrintf(1, "Avståndet Är: %d mm", arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(k = 1; k<8; k++)
    {
        if(minDis > arrayDis[k])
        {
            //minDis = arrayDis[k];
            indexTidForMinDis = k;
        }
    }

    return indexTidForMinDis;
}

void rotateMotor (int l) {
    LcdPrintf(1, "Turn Right! %d\n", l);
    OnFwdReg(OUT_A, 16);
    OnRevReg(OUT_B, 16);
    Wait(SEC_2 + MS_350);

}


void forward() {
    LcdPrintf(1, "Going Forward!\n");
    OnRevSync(OUT_AB,30);
}

void touchSensor() {
	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		int rightSensor = readSensor(IN_1);
		int leftSensor = readSensor(IN_3);

			if(rightSensor == 1){
				//Off(OUT_AB); behövs ja/nej??
				LcdPrintf(1,"Turn Right! \n");
				OnRevSync(OUT_B,23);
				Wait(SEC_7 + MS_500);

				if(rightSensor && leftSensor == 1){
					//Off(OUT_AB); behövs ja/nej??
					 LcdPrintf(1, "Going Backward! \n");
					    OnFwdSync(OUT_AB,75);
					    Wait(SEC_4);

					 LcdPrintf(1, "Turn 90 degrees! \n");
					    OnFwdReg(OUT_A, 44);
					    Wait(SEC_3 + MS_700 + MS_50);

					 forward();

					 dropBook();
				}
			}
			else if(leftSensor == 1){
				//Off(OUT_AB); behövs ja/nej??
					LcdPrintf(1,"Turn Left! \n");
					OnRevSync(OUT_A,23);
					Wait(SEC_7 + MS_500);

					if(rightSensor && leftSensor == 1){
						//Off(OUT_AB); behövs ja/nej??
						 LcdPrintf(1, "Going Backward! \n");
						   OnFwdSync(OUT_AB,75);
						   Wait(SEC_4);

						 LcdPrintf(1, "Turn 90 degrees! \n");
							OnFwdReg(OUT_A, 44);
							Wait(SEC_3 + MS_700 + MS_50);

				  		 forward();

				  		dropBook();
					}
			}

			if(rightSensor && leftSensor == 1)
				{
					//Off(OUT_AB); behövs ja/nej??
					 LcdPrintf(1, "Going Backward! \n");
					  OnFwdSync(OUT_AB,75);
					  Wait(SEC_4);

					 LcdPrintf(1, "Turn 90 degrees!");
					   OnFwdReg(OUT_A, 44);
					   Wait(SEC_3 + MS_700 + MS_50);

					   forward();

					   dropBook();

				}
			else {
				Off(OUT_AB);
				LcdPrintf(1, "No touch");
			}
}

dropBook () {
	 LcdPrintf(1,"Use the hand\n");
		 RotateMotor(OUT_C, 10, 90);
		 Wait(SEC_2);
		 RotateMotor(OUT_C, 10, -90);
}
