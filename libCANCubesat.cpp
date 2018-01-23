#include "libCANCubesat.h"

int counter = 0;
Serial pc(USBTX, USBRX);
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);

void read_callback()
{
	CANMessage msg;
	int errorCode;
	// 1.Declare a bit stream
	BitStream bitStrm;
	// 2.Declare the stuct where the decoded data will be written

	if (can1.read(msg))
	{
		// 3.Initialize bit stream
		BitStream_AttachBuffer(&bitStrm, msg.data, 8);

		led1 = !led1;

		// 4 . Decode data
		switch (msg.id)
		{
		case libCANCubesat::ADCS_is_stable:
			asn1SccADCS_is_stable value1;
			pc.printf("name : adcs_is_stable\t");
			if (!asn1SccADCS_is_stable_Decode(&value1, &bitStrm, &errorCode))
			{
				pc.printf(" Decoded failed . Error code is %d \n ", errorCode);
			}
			obc_PI_receiveAdcsStable(&value1);
			break;
		case libCANCubesat::OBC_orientation_mode_command:
			asn1SccOBC_orientation_mode_command value2;
			pc.printf("name : obc orientation\t");
			if (!asn1SccOBC_orientation_mode_command_Decode(&value2, &bitStrm, &errorCode))
			{
				pc.printf(" Decoded failed . Error code is %d \n ", errorCode);
			}
			pc.printf("read_callback(): id=%d, data=%d\t", msg.id, value2);
			break;
		case libCANCubesat::OBC_profileTCS:
			asn1SccOBC_profileTCS value3;
			pc.printf("name : obc profile TCS\t");
			if (!asn1SccOBC_profileTCS_Decode(&value3, &bitStrm, &errorCode))
			{
				pc.printf(" Decoded failed . Error code is %d \n ", errorCode);
			}
			pc.printf("read_callback(): id=%d, data=%d\t", msg.id, value3);
			break;
		}
	}
}

void transmitted_callback()
{
	led1 = !led1;
	pc.printf("transmitted_callback()\t");
}

void errorwarning_callback()
{
	led1 = !led1;
	pc.printf("errorwarning_callback()\t");
}

void do_callback()
{
	led1 = !led1;
	pc.printf("do_callback()\t");
}

void wakeup_callback()
{
	led1 = !led1;
	pc.printf("wakeup_callback()\t");
}

void errorpassive_callback()
{
	led1 = !led1;
	pc.printf("errorpassive_callback()\t");
}

void al_callback()
{
	led1 = !led1;
	pc.printf("al_callback()\t");
}

void be_callback()
{
	led1 = !led1;
	pc.printf("be_callback()\t");
}

void send_adcsstable()
{
	int errorCode;
	// 1 . Define a buffer where the uPER stream will be written to
	byte perBuffer[asn1SccADCS_is_stable_REQUIRED_BYTES_FOR_ENCODING];
	// 2 . Define a bit stream variable
	BitStream bitStrm;
	// 3 . Data to be encode ( assumed to be filled elsewhere )
	asn1SccADCS_is_stable value = TRUE;

	// 4. Initialize bit stream
	BitStream_Init(&bitStrm, perBuffer, asn1SccADCS_is_stable_REQUIRED_BYTES_FOR_ENCODING);
	// 5 . Encode
	if (!asn1SccADCS_is_stable_Encode(&value, &bitStrm, &errorCode, TRUE))
	{
		pc.printf(" Encode failed . Error code is %d \n ", errorCode);
	}
	else
	{
		if (can1.write(CANMessage(libCANCubesat::ADCS_is_stable, (char *)perBuffer, asn1SccADCS_is_stable_REQUIRED_BYTES_FOR_ENCODING)))
		{
			counter++;
			pc.printf("Message sent: %d\t", value);
		}
	}
}

void send_obcorientationmode()
{
	int errorCode;
	// 1 . Define a buffer where the uPER stream will be written to
	byte perBuffer[asn1SccOBC_orientation_mode_command_REQUIRED_BITS_FOR_ENCODING];
	// 2 . Define a bit stream variable
	BitStream bitStrm;
	// 3 . Data to be encode ( assumed to be filled elsewhere )
	asn1SccOBC_orientation_mode_command value = asn1Sccshutdown;

	// 4. Initialize bit stream
	BitStream_Init(&bitStrm, perBuffer, asn1SccOBC_orientation_mode_command_REQUIRED_BITS_FOR_ENCODING);
	// 5 . Encode
	if (!asn1SccOBC_orientation_mode_command_Encode(&value, &bitStrm, &errorCode, TRUE))
	{
		pc.printf(" Encode failed . Error code is %d \n ", errorCode);
	}
	else
	{
		if (can1.write(CANMessage(libCANCubesat::OBC_orientation_mode_command, (char *)perBuffer, asn1SccOBC_orientation_mode_command_REQUIRED_BITS_FOR_ENCODING)))
		{
			counter++;
			pc.printf("Message sent: %d\t", value);
		}
	}
}
