

#include "WmraTypes.h"
#include "WMRA_module.h"
//#include "omni_lib.h"

#include <Windows.h>

using namespace std;

//
//int moveSquare()
//{
//	WMRA::Pose curPos;
//	WMRA::WMRA_module wmraArm;
//	wmraArm.initialize();
//	Sleep(5000);
//
//	curPos = wmraArm.getPose();
//
//	int length;
//	cout << "Length? " << endl;
//	cin >> length;
//
//	int loopCount;
//	cout << "Number of loops? " << endl;
//	cin >> loopCount;
//
//	int choice = 0;
//	cout << "Begin Square Test? 1=Yes 0=No" << endl;
//	cin >> choice;
//
//	WMRA::Pose dest1,dest2,dest3,dest4;
//	dest1 = dest2 = dest3 = dest4 = curPos;	
//
//	dest2.x = dest1.x;
//	dest2.y = dest1.y+length;
//
//	dest3.x = dest2.x+length;
//	dest3.y = dest2.y;
//
//	dest4.x = dest3.x;
//	dest4.y = dest3.y-length;
//		
//
//	// Move arm to starting position (dest1)
//	wmraArm.autonomous(dest1, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
//	Sleep(5000); // wait 5 seconds before starting
//
//	while(loopCount > 0 && choice==1)
//	{
//		cout << "Loop: " << loopCount << endl;
//		wmraArm.autonomous(dest2, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
//		wmraArm.autonomous(dest3, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
//		wmraArm.autonomous(dest4, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
//		wmraArm.autonomous(dest1, WMRA::ARM_FRAME_PILOT_MODE,true); // Moves arm
//		loopCount--;
//	}
//
//	Sleep(2000); // wait 2 seconds
//
//	wmraArm.toReady(); // moves arm to ready position
//
//	return 1;
//}
//
//
//
//int squareUsingTeleoperation()
//{
//	float gain = 0.3;
//	WMRA::Pose curPos, deltaPos;
//	WMRA::WMRA_module wmraArm;
//	wmraArm.initialize();
//
//	omni o;
//
//	Sleep(5000);
//
//	curPos = wmraArm.getPose();
//	deltaPos = o.getDeltaPose();
//
//
//	int count = 0;
//	while(count <50)
//	{
//		curPos = wmraArm.getPose();
//		deltaPos = o.getDeltaPose();
//		if(deltaPos.x != 0 || deltaPos.y != 0 || deltaPos.z != 0)
//		{
//			cout << " MOVING:" << count << endl;
//			count++;
//			curPos.x = curPos.x+(deltaPos.x*gain);
//			curPos.y = curPos.y+(deltaPos.y*gain);
//			curPos.z = curPos.z+(deltaPos.z*gain);
//			wmraArm.autonomous(curPos, WMRA::ARM_FRAME_PILOT_MODE); // Moves arm
//		}
//	}	
//
//
//	Sleep(5000); // wait 5 seconds
//	
//	wmraArm.toReady(); // moves arm to ready position
//
////	cin >> count;
//	return 0;
//}

int main()
{
	const double deg2rad = 0.0174532925;
	int radius = 100;
	WMRA::Pose curPos, deltaPos;
	WMRA::WMRA_module wmraArm;
	wmraArm.initialize();

	Sleep(5000);

	curPos = wmraArm.getPose();
	deltaPos.clear();
	deltaPos.x = radius*cos(0.0);
	deltaPos.y = radius*sin(0.0);

	int count = 0;
	while(count < 360)
	{
		deltaPos.x = radius*cos(double(count*deg2rad));
		deltaPos.y = radius*sin(double(count*deg2rad));
		wmraArm.teleoperation(deltaPos,500);
		count++;
	}	
	Sleep(5000); // wait 5 seconds
	
	wmraArm.toReady(); // moves arm to ready position

	return 0;
}