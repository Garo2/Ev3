#include <stdio.h>

int main() {
    int indexTid = findMinDistance();

    for(int i; i < indexTid; i++) {
        rotateMotor();
    }

    return 0;
}

void rotateMotor (int l) {
    LcdPrintf(1, "Turn Right! %dst \n", l);
    OnFwdReg(OUT_A, 23);
    Wait(SEC_3 + MS_700 + MS_50);

}

int findMinDistance () {
    int distance;
    int minDis;
    int arrayDis[8];
    int indexTidForMinDis;

    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
    for (int j = 0; j < 9; j++) {
        rotateMotor(j);
        distance = readSensor(IN_4);
        arrayDis[j] = distance;
        LcdPrintf(1, "Avståndet är: %d mm", arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(int k=1; k<8; k++)
    {
        if(minDis > arrayDis[k])
        {
            //minDis = arrayDis[k];
            indexTidForMinDis = k;
        }
    }

    return indexTidForMinDis;
}
