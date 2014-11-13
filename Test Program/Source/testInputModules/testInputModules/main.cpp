
#include "WmraTypes.h"
#include "WMRA_module.h"
//#include "omni_lib.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

void main(){
	// Initialize WMRA
	WMRA::WMRA_module wmra;
	
	//Initialize Variables
	int currentMotor;
	char keypress;


	cout << "\t~~~~~ Welcome to the Mr.Fix-It Program ~~~~~\n" << endl;
	cout << "Press h for help or move joint 1" << endl;

	while (1)
    {
		keypress = ' ';
		// Check for keyboard input.
		if (_kbhit())
			keypress = _getch();
		keypress = toupper(keypress);

		if (keypress == 'H')
		{
			// #DEBUG - add help menu
			cout << "\t ~~~~~ Help Menu ~~~~~" << endl;
		}
		else if(keypress == '1')
		{
			currentMotor = 0;
			cout << "Joint 1 Selected" << endl;
		}
		else if(keypress == '2')
		{
			currentMotor = 1;
			cout << "Joint 2 Selected" << endl;
		}
		else if(keypress == '3')
		{
			currentMotor = 2;
			cout << "Joint 3 Selected" << endl;
		}
		else if(keypress == '4')
		{
			currentMotor = 3;
			cout << "Joint 4 Selected" << endl;
		}
		else if(keypress == '5')
		{
			currentMotor = 4;
			cout << "Joint 5 Selected" << endl;
		}
		else if(keypress == '6')
		{
			currentMotor = 5;
			cout << "Joint 6 Selected" << endl;
		}
		else if(keypress == '7')
		{
			currentMotor = 6;
			cout << "Joint 7 Selected" << endl;
		}
		else if(keypress == '8')
		{
			currentMotor = 7;
			cout << "Joint 8 Selected" << endl;
		}
		else if(keypress == 'W')
		{
			wmra.moveJoint(currentMotor,0.03,1);
		}
		else if(keypress == 'S')
		{
			wmra.moveJoint(currentMotor,0.03,1);
		}
		else if(keypress == 'D')
		{
			wmra.stop();
		}
		else if(keypress == 'Q')
		{
			return;
		}
		else if(keypress == 'P')
		{
			WMRA::JointValueSet joints = wmra.getJointAngles();
			WMRA::Pose currentPose = wmra.getPose();

			cout << "\t-------------------------------------" << endl;
			cout << "\t ~~~~~ Current Joint Positions ~~~~~" << endl;
			cout << "Joint 1: " << joints.Joint[0] << endl;
			cout << "Joint 2: " << joints.Joint[1] << endl;
			cout << "Joint 3: " << joints.Joint[2] << endl;
			cout << "Joint 4: " << joints.Joint[3] << endl;
			cout << "Joint 5: " << joints.Joint[4] << endl;
			cout << "Joint 6: " << joints.Joint[5] << endl;
			cout << "Joint 7: " << joints.Joint[6] << endl;
			cout << "Joint 8: " << joints.Joint[7] << endl;
			
			cout << "\t ~~~~~ Current Arm Pose ~~~~~" << endl;
			cout << "X: " << currentPose.x << endl;
			cout << "Y: " << currentPose.y << endl;
			cout << "Z: " << currentPose.z << endl;
			cout << "Roll: " << currentPose.roll << endl;
			cout << "Pitch: " << currentPose.pitch << endl;
			cout << "Yaw: " << currentPose.yaw << endl;
			cout << "\t-------------------------------------" << endl;
		}
		else if(keypress == ' ')
		{
			// do nothing
		}
		else
		{
			// display key value if an unused key is pressed
			cout << keypress << endl;
		}
	}

}
//
//int main()
//{
//	float gain = 1.2;
//	const double deg2rad = 0.0174532925;
//	double dt = 10;
//	int count = 0;
//	
//	WMRA::Pose curPos, deltaPos;
////	WMRA::WMRA_module wmraArm;
//
//	WMRA::omni o;
//
//	cout << "Starting in 5...\n\n" << endl;
//	Sleep(5000);
//	cout << "Moving!\n\n" << endl;
//	
//	while(count < 100)
//	{
//		Sleep(100);
//		deltaPos = o.getDeltaPose();
//		cout << "Omni Pose: x=" << deltaPos.x << "\ty=" << deltaPos.y << "\tz=" << deltaPos.z << endl; 
//		if(deltaPos.x != 0 || deltaPos.y != 0 || deltaPos.z != 0)
//		{
//			count++;
//			deltaPos.x = (deltaPos.x*gain);
//			deltaPos.y = (deltaPos.y*gain);
//			deltaPos.z = (deltaPos.z*gain);
////			wmraArm.teleoperation(deltaPos,dt);
//		}
//		else
//		{
//			deltaPos.clear();
////			wmraArm.teleoperation(deltaPos,dt);
//		}
//	}
////	wmraArm.toReady(); // moves arm to ready position
//	cout << "Sleeping for 20 seconds.." << endl;
//	Sleep(20000); // wait 20 seconds
//	return 0;
//}
//
//
//int teleoperationWithOmni()
//{
//	float gain = 1.2;
//	const double deg2rad = 0.0174532925;
//	double dt = 10;
//	int count = 0;
//	
//	WMRA::Pose curPos, deltaPos;
//	WMRA::WMRA_module wmraArm;
//
//	WMRA::omni o;
//
//	cout << "Starting in 5...\n\n" << endl;
//	Sleep(5000);
//	cout << "Moving!\n\n" << endl;
//	
//	while(count < 200)
//	{
//		Sleep(300);
//		deltaPos = o.getDeltaPose();
//		if(deltaPos.x != 0 || deltaPos.y != 0 || deltaPos.z != 0)
//		{
//			count++;
//			deltaPos.x = (deltaPos.x*gain);
//			deltaPos.y = (deltaPos.y*gain);
//			deltaPos.z = (deltaPos.z*gain);
//			wmraArm.teleoperation(deltaPos,dt);
//		}
//		else
//		{
//			deltaPos.clear();
//			wmraArm.teleoperation(deltaPos,dt);
//		}
//	}
//	wmraArm.toReady(); // moves arm to ready position
//	cout << "Sleeping for 20 seconds.." << endl;
//	Sleep(20000); // wait 20 seconds
//	return 0;
//}

//
//int circleWithTeleoperation()
//{
//	const double deg2rad = 0.0174532925;
//	double dt = 10;
//	int radius = 150;
//	
//	WMRA::Pose curPos, deltaPos;
//	WMRA::WMRA_module wmraArm;
//
//	cout << "Starting in 5...\n\n" << endl;
//	Sleep(5000);
//	cout << "Moving!\n\n" << endl;
//
//	curPos = wmraArm.getPose();
//	deltaPos.clear();
//	deltaPos.x = radius*cos(0.0);
//	deltaPos.y = radius*sin(0.0);
//
//	for(int count = 0; count < 360; count++)
//	{
//		Sleep(300);
//		deltaPos.x = radius*cos(double(count*deg2rad));
//		deltaPos.y = radius*sin(double(count*deg2rad));
//		wmraArm.teleoperation(deltaPos,dt);
//	}		
//	wmraArm.toReady(); // moves arm to ready position
//	cout << "Sleeping for 20 seconds.." << endl;
//	Sleep(20000); // wait 20 seconds
//	return 0;
//}

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

