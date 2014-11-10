
#include "omni_lib.h"
#include "WmraTypes.h"
#include "Arm.h"

using namespace std;

int main()
{
	float gain = 0.03;
	omni Om;
	WMRA::Pose p, delta, tgt;
	Arm a;
	a.initialize();
	Sleep(5000);
	double pitch, roll, yaw;

	vector<double> tran(16);

	while(1)
	{
		Sleep(1000);
		delta = Om.getDeltaPose();
//		cout << "Omni Delta Pose: " << delta.x << ", " << delta.y << ", " << delta.z << ", " << delta.roll << ", " << delta.pitch << ", " << delta.yaw << endl;

		
		tran = Om.getKinematicPose();
		cout << "\n\n\t| " << tran[0] << "\t" << tran[4] << "\t" << tran[8] << "\t" << tran[12] << "\t|";
		cout << "\n\t| " << tran[1] << "\t" << tran[5] << "\t" << tran[9] << "\t" << tran[13] << "\t|";
		cout << "\n\t| " << tran[2] << "\t" << tran[6] << "\t" << tran[10] << "\t" << tran[14] << "\t|";
		cout << "\n\t| " << tran[3] << "\t\t" << tran[7] << "\t\t" << tran[11] << "\t\t" << tran[15] << "\t\t|\n\n";

		pitch = atan2((-1*tran[2]), sqrt((tran[0]*tran[0])+(tran[1]*tran[1])));
		roll = atan2((tran[1]/cos(pitch)), (tran[0]/cos(pitch)));
		yaw = atan2((tran[6]/cos(pitch)), (tran[10]/cos(pitch)));

		cout << "Pitch: " << pitch << "\t\tRoll: " << roll << "\t\tYaw: " << yaw << endl;

		p = a.getPose();
		//cout << "Arm Pose: " << p.x << ", " << p.y << ", " << p.z << ", " << p.roll << ", " << p.pitch << ", " << p.yaw << endl;

		if(delta.x != 0 || delta.y != 0 || delta.z != 0)
		{
			tgt.x = p.x + (delta.x*gain);
			tgt.y = p.y + (delta.y*gain);
			tgt.z = p.z + (delta.z*gain);

			tgt.pitch = p.pitch;// + delta.pitch;
			tgt.roll = p.roll;// + delta.roll;
			tgt.yaw = p.yaw;// + delta.yaw;
//			cout << "Arm Pose: " << p.x << ", " << p.y << ", " << p.z << ", " << p.roll << ", " << p.pitch << ", " << p.yaw << endl;
//			cout << "Sent Pose: " << tgt.x << ", " << tgt.y << ", " << tgt.z << ", " << tgt.roll << ", " << tgt.pitch << ", " << tgt.yaw << endl;

			a.teleoperation(tgt, WMRA::ARM_FRAME_PILOT_MODE);
		}
		
	}
	return 0;
}