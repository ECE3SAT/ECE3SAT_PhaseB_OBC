#include "libCANCubesat.h"

int counter = 0;
Serial pc(USBTX, USBRX);
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);
DigitalOut receivedled(A4);
DigitalOut sendLED(A5);
DigitalOut errorLED(A6);

void OBC_read_callback()
{
	receivedled = 1; //display we are using cpu
	pc.printf("OBC_read_callback()\r\n");
	CANMessage msg;

	if (can1.read(msg))
	{
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
	receivedled = 0; //display we stopped to use cpu
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
	receivedled = 1; //display we are using cpu
	pc.printf("ADCS_read_callback()\r\n");
	CANMessage msg;
	
	if (can1.read(msg))
	{
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
	receivedled = 0; //display we stopped to use cpu
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
	receivedled = 1; //display we are using cpu
	pc.printf("EDT_read_callback()\r\n");
	CANMessage msg;

	if (can1.read(msg))
	{
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
	receivedled = 0; //display we stopped to use cpu
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
	receivedled = 1; //display we are using cpu
	pc.printf("TCS_read_callback()\r\n");
	CANMessage msg;

	if (can1.read(msg))
	{
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
	receivedled = 0; //display we stopped to use cpu
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
	pc.printf("transmitted_callback()\r\n");
	errorLED = 0;	//eteindre la LED d'erreur
}

void errorwarning_callback()
{
	pc.printf("errorwarning_callback()\t tderror:%d \t rderror:%d\r\n", can1.tderror(), can1.rderror());
	errorLED = !errorLED;
}

void do_callback()
{
	pc.printf("do_callback()\r\n");
}

void wakeup_callback()
{
	pc.printf("wakeup_callback()\r\n");
}

void errorpassive_callback()
{
	pc.printf("errorpassive_callback()\t tderror:%d \t rderror:%d\r\n", can1.tderror(), can1.rderror());
	errorLED = !errorLED;
}

void al_callback()
{
	pc.printf("al_callback()\r\n");
}

void be_callback()
{
	pc.printf("be_callback()\r\n");
}

void send_adcsstable()
{
	sendLED = 1; //display we are using cpu
	asn1SccADCS_is_stable value = TRUE;
	MessageAdcsStable msg(value);
	msg.send();
	sendLED = 0; //display we stopped to use cpu
}

void send_adcsstable_rtr()
{
	sendLED = 1; //display we are using cpu
	can1.write(CANMessage(1000, CANStandard));
	sendLED = 0; //display we stopped to use cpu
}

void send_obcorientationmode()
{
	sendLED = 1; //display we are using cpu
	//TODO
	sendLED = 0; //display we stopped to use cpu
}
