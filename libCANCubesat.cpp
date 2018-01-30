#include "libCANCubesat.h"

int counter = 0;
Serial pc(USBTX, USBRX);
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);

void OBC_read_callback()
{
	pc.printf("OBC_read_callback()\r\n");
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
		if (msg.type == CANData)
		{
			OBC_dataframe_handler(msg);
		}
		else if (msg.type == CANRemote)
		{
			OBC_remoteframe_handler(msg);
		}
	}
}

void OBC_dataframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
		case libCANCubesat::OBC_orientation_mode_command:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
	}
}

void OBC_remoteframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		send_adcsstable();
		break;
	case libCANCubesat::OBC_orientation_mode_command:
		send_obcorientationmode();
		break;
	}
}

void ADCS_read_callback()
{
	pc.printf("ADCS_read_callback()\r\n");
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
		if (msg.type == CANData)
		{
			ADCS_dataframe_handler(msg);
		}
		else if (msg.type == CANRemote)
		{
			ADCS_remoteframe_handler(msg);
		}
	}
}

void ADCS_dataframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
		case libCANCubesat::OBC_orientation_mode_command:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
	}
}

void ADCS_remoteframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		send_adcsstable();
		break;
	case libCANCubesat::OBC_orientation_mode_command:
		send_obcorientationmode();
		break;
	}
}
void EDT_read_callback()
{
	pc.printf("EDT_read_callback()\r\n");
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
		if (msg.type == CANData)
		{
			EDT_dataframe_handler(msg);
		}
		else if (msg.type == CANRemote)
		{
			EDT_remoteframe_handler(msg);
		}
	}
}

void EDT_dataframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
		case libCANCubesat::OBC_orientation_mode_command:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
	}
}

void EDT_remoteframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		send_adcsstable();
		break;
	case libCANCubesat::OBC_orientation_mode_command:
		send_obcorientationmode();
		break;
	}
}
void TCS_read_callback()
{
	pc.printf("TCS_read_callback()\r\n");
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
		if (msg.type == CANData)
		{
			TCS_dataframe_handler(msg);
		}
		else if (msg.type == CANRemote)
		{
			TCS_remoteframe_handler(msg);
		}
	}
}

void TCS_dataframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
		case libCANCubesat::OBC_orientation_mode_command:
		MessageAdcsStable::FromCanBus(msg.data, msg.len);
		break;
	}
}

void TCS_remoteframe_handler(CANMessage msg)
{
	switch (msg.id)
	{
	case libCANCubesat::ADCS_is_stable:
		send_adcsstable();
		break;
	case libCANCubesat::OBC_orientation_mode_command:
		send_obcorientationmode();
		break;
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
	asn1SccADCS_is_stable value = TRUE;
	MessageAdcsStable msg(value);
	msg.send();
}

void send_adcsstable_rtr()
{
	can1.write(CANMessage(1000, CANStandard));
}

void send_obcorientationmode()
{
	//TODO
}
