
//#include "omni_lib.h"
#include "WmraTypes.h"
#include "WMRA_module.h"

#include <Windows.h>

using namespace std;


int moveSquare()
{
	WMRA::Pose curPos;
	WMRA::WMRA_module wmraArm;
	wmraArm.initialize();
	Sleep(5000);

	curPos = wmraArm.getPose();

	int length;
	cout << "Length? " << endl;
	cin >> length;

	int loopCount;
	cout << "Number of loops? " << endl;
	cin >> loopCount;

	int choice = 0;
	cout << "Begin Square Test? 1=Yes 0=No" << endl;
	cin >> choice;

	WMRA::Pose dest1,dest2,dest3,dest4;
	dest1 = dest2 = dest3 = dest4 = curPos;	

	dest2.x = dest1.x;
	dest2.y = dest1.y+length;

	dest3.x = dest2.x+length;
	dest3.y = dest2.y;

	dest4.x = dest3.x;
	dest4.y = dest3.y-length;
		

	// Move arm to starting position (dest1)
	wmraArm.autonomous(dest1, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
	Sleep(5000); // wait 5 seconds before starting

	while(loopCount > 0 && choice==1)
	{
		cout << "Loop: " << loopCount << endl;
		wmraArm.autonomous(dest2, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
		wmraArm.autonomous(dest3, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
		wmraArm.autonomous(dest4, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
		wmraArm.autonomous(dest1, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
		loopCount--;
	}

	Sleep(2000); // wait 2 seconds

	wmraArm.toReady(); // moves arm to ready position

	return 1;
}



int main()
{
	WMRA::Pose curPos;
	WMRA::WMRA_module wmraArm;
	wmraArm.initialize();
	Sleep(5000);

	curPos = wmraArm.getPose();

	for(int i = 0; i<4; i++)
	{
		curPos.x = curPos.x+10;
		wmraArm.autonomous(curPos, WMRA::ARM_FRAME_PILOT_MODE); // Moves arm
	}
	for(int i = 0; i<4; i++)
	{
		curPos.y = curPos.y+10;
		wmraArm.autonomous(curPos, WMRA::ARM_FRAME_PILOT_MODE); // Moves arm
	}
	for(int i = 0; i<4; i++)
	{
		curPos.x = curPos.x-10;
		wmraArm.autonomous(curPos, WMRA::ARM_FRAME_PILOT_MODE); // Moves arm
	}
	for(int i = 0; i<4; i++)
	{
		curPos.y = curPos.y-10;
		wmraArm.autonomous(curPos, WMRA::ARM_FRAME_PILOT_MODE); // Moves arm
	}	
	Sleep(12000); // wait 2 seconds
	
	wmraArm.toReady(); // moves arm to ready position
	return 0;
}