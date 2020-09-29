#include "PC_FileIO.c"
const float xMotorRadius=1;
const float xMotorConverter=1*PI*xMotorRadius/360;
const float yMotorRadius=2;
const float yMotorConverter=2*PI*yMotorRadius/360;

void tiltPen(int direction){
	if(direction==0){
		while (!SensorValue[S1])
		{
			motor[motorC]=-20;
		}
		motor[motorC]=-3;
		}else{
		nMotorEncoder[motorC]=0;
		motor[motorC]=10;
		wait1Msec(500);
		//while (nMotorEncoder[motorC] < 45){}
		motor[motorC]=0;
		//tilt down
	}
}

void moveX(int deltaX){
	nMotorEncoder[motorA]=0;
	if (deltaX>0){
		motor[motorA]=-25;
		while (nMotorEncoder[motorA]>-deltaX/xMotorConverter){}
		}else if (deltaX<0){
		motor[motorA]=25;
		while (nMotorEncoder[motorA]<-deltaX/xMotorConverter){}
	}
	motor[motorA] = 0;
}

void moveY(int deltaY){
	nMotorEncoder[motorB]=0;
	if (deltaY>0){
		motor[motorB]=10;
		while (nMotorEncoder[motorB]<deltaY/yMotorConverter){}
		}else if (deltaY<0){
		motor[motorB]=-10;
		while (nMotorEncoder[motorB]>deltaY/yMotorConverter){}
	}
	motor[motorB] = 0;
}

void writeCharacter(string character){
	if (character=="!"){
		displayString(3,"no solution");
		return;
	}
	if (SensorValue[S2]!=(int)colorWhite){
		displayString(3,"Error: paper missing");
	}
	while (SensorValue[S2]!=(int)colorWhite){};
	displayString(3,"                       ");
	int characterScale=0.5;
	if (character=="0"){
		//write 0
		tiltPen(0);
		moveX(characterScale);
		moveY(-characterScale);
		moveX(-characterScale);
		moveY(characterScale);
		//move to TR corner
		tiltPen(1);
		moveX(characterScale);
		moveX(characterScale);
	}

	if (character=="1"){
		//write 1
		tiltPen(0);
		moveY(-2*characterScale);
		//move to TR corner
		tiltPen(1);
		moveY(2*characterScale);
		moveX(characterScale);
	}

	if (character=="2"){
		// write 2
		tiltPen(0);
		moveX(characterScale);
		wait1Msec(1000);
		moveY(-characterScale);
		wait1Msec(1000);
		moveX(-characterScale);
		wait1Msec(1000);
		moveY(-characterScale);
		wait1Msec(1000);
		moveX(characterScale);
		wait1Msec(1000);
		//move to TR corner
		tiltPen(1);
		moveY(2*characterScale);
		moveX(characterScale);
	}

	if (character=="3"){
		//write 3
		tiltPen(0);
		moveX(characterScale);
		moveY(-characterScale);
		moveX(-characterScale);
		moveX(characterScale);
		moveY(-characterScale);
		moveX(-characterScale);
		//move to TR corner
		tiltPen(1);
		moveX(characterScale);
		moveY(2*characterScale);
		moveX(characterScale);
	}

	if (character=="4"){
		//write 4
		tiltPen(0);
		moveY(-characterScale);
		moveX(characterScale);
		moveY(-characterScale);
		moveY(2 * characterScale);
		//move to TR corner
		tiltPen(1);
		moveX(characterScale);
	}

	if (character=="5"){
		//write 5
		tiltPen(0);
		moveX(characterScale);
		moveX(-characterScale);
		moveY(-characterScale);
		moveX(characterScale);
		moveY(-characterScale);
		moveX(-characterScale);
		//move to TR corner
		tiltPen(1);
		moveX(characterScale);
		moveY(2*characterScale);
		moveX(characterScale);
	}

	if (character=="6"){
		//write 6
		tiltPen(0);
		moveX(characterScale);
		wait1Msec(1000);
		moveX(-characterScale*1.25);
		//adjusted to compensate for drag
		wait1Msec(1000);
		moveY(-2 * characterScale);
		wait1Msec(1000);
		moveX(characterScale);
		wait1Msec(1000);
		tiltPen(1);
		moveY(characterScale);
		tiltPen(0);
		moveX(-characterScale*1.25);
		wait1Msec(1000);
		moveX(characterScale);
		wait1Msec(1000);
		moveY(-characterScale);
		wait1Msec(2500);
		//move to TR corner
		tiltPen(1);
		moveX(characterScale);
		moveY(characterScale);
		moveX(characterScale);
	}

	if (character=="7"){
		//write 7
		tiltPen(0);
		moveX(characterScale);
		moveY(-2 * characterScale);
		//move to TR corner
		tiltPen(1);
		moveY(2 * characterScale);
		moveX(characterScale);
	}

	if (character=="8"){
		//write 8
		tiltPen(0);
		moveX(characterScale);
		moveY(-2 * characterScale);
		moveX(-characterScale);
		moveY(2*characterScale);
		moveY(-characterScale);
		moveX(characterScale);
		//move to TR corner
		tiltPen(1);
		moveY(characterScale);
		moveX(characterScale);
	}

	if (character=="9"){
		//write 9
		tiltPen(0);
		moveX(characterScale);
		moveX(-characterScale);
		moveY(-characterScale);
		moveX(characterScale);
		moveY(characterScale);
		moveY(-2*characterScale);
		moveX(-characterScale);
		//move to TR corner
		tiltPen(1);
		moveX(characterScale);
		moveY(2 * characterScale);
		moveX(characterScale);
	}

	if (character=="."){
		tiltPen(0);
		tiltPen(1);
	}


	if (character=="+"){
		tiltPen(0);
		moveX(2);
		moveX(-1);
		moveY(1);
		moveY(-2);
		tiltPen(1);
		moveX(characterScale);
	}

	if (character=="-"){
		tiltPen(0);
		moveX(2);
		tiltPen(1);
		moveX(characterScale);
	}

	if (character=="="){
		tiltPen(0);
		moveX(2);
		tiltPen(1);
		moveX(-2);
		moveY(-1);
		tiltPen(0);
		moveX(2);
		moveX(characterScale);
	}

	if (character=="x"){
		tiltPen(0);
		for(int i=0;i<10;i++){
			moveX(characterScale*0.1);
			moveY(-characterScale*0.1);
		}
		tiltPen(1);
		moveY(characterScale);
		tiltPen(0);
		for(int i=0;i<10;i++){
			moveX(-characterScale*0.1);
			moveY(-characterScale*0.1);
		}
		moveX(characterScale);
	}


	if (character=="i"){
		tiltPen(0);
		moveY(-0.5 * characterScale);
		tiltPen(1);
		moveY(-0.5 * characterScale);
		tiltPen(0);
		moveY(-characterScale);
		tiltPen(1);
		moveX(characterScale);
		moveY(characterScale);
		moveX(characterScale);
	}

}

void stringToChar(string & myString, string & temp) {
	temp = myString;
	stringDelete(myString, 0, 1);
	stringDelete(temp,1,19);
}

//we need to set our file so that there's a maximum # of characters each line, also no spaces
void writeSentence (string sol){
	for(int i = 0; i < 20; i++){
		string temp = "";
		stringToChar(sol, temp);
		writeCharacter(temp);
	}
}

task main(){
	SensorType[S1]= sensorEV3_Touch;
	SensorType[S2]= sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S2]=modeEV3Color_Color;
	int lineWrite = 0;

	TFileHandle fin;
	bool fileOkay =false;
	fileOkay = openReadPC(fin,"solution.txt");

	moveX(-20);

	if (!fileOkay)
		displayString(1,"ERROR");
	else
	{
		string sol="";
		while (readTextPC(fin,sol)){
			if (lineWrite == 0)
				displayString(lineWrite, "The Solution is: %s", sol);
			else
				displayString(lineWrite, "and %s", sol);
			lineWrite++;
			writeSentence(sol);
		}
	}

	displayString(5,"Did you get the question right?");
	displayString(6,"No - Left Button, Yes - Right Button");

	while (!getButtonPress(buttonLeft) && !getButtonPress(buttonRight)){};

	if (getButtonPress(buttonLeft)){
		displayString(7,"That's OK, try again!");
		}else if (getButtonPress(buttonRight)){
		displayString(7,"That's great, Good Job!");
	}
	displayString(9,"Press Enter to turn off");
	clearTimer(T1);

	while(!getButtonPress(buttonEnter) && time1[T1]<15000){};

}
