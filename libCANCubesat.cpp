#include "libCANCubesat.h"

int counter = 0;
Serial pc(USBTX, USBRX);
Timeout timeout;
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);
DigitalOut receivedled(A4);
DigitalOut sendLED(A5);
DigitalOut errorLED(A6);

/**
 * La read_callback est executée à la reception d'une frame CAN valide, grâce à une interruption.
 */
void OBC_read_callback()
{
	receivedled = 1; //display we are using cpu
	pc.printf("OBC_rc()\r\n");
	CANMessage msg;

	//on lit le message CAN recu
	if (can1.read(msg))
	{
		led1 = !led1;

		/* il existe 2 types de frames CAN : les CANData et les CANRemote.
		 */
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

/**
 * Les frames CANData transportent des données. On traite les données recues.
 */
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

/**
 * Les CANRemote sont des demandes d'émissions : on répond à cette demande si on est responsable de la donnée.
 */
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
	pc.printf("ADCS_rc()\r\n");
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
	pc.printf("EDT_rc()\r\n");
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
	default:
		//nothing
		break;
	}
}
void TCS_read_callback()
{
	receivedled = 1; //display we are using cpu
	pc.printf("TCS_rc()\r\n");
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
	default:
		//nothing
		break;
	}
}

void transmitted_callback()
{
	pc.printf("tc()\r\n");
	errorLED = 0; //eteindre la LED d'erreur
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
	timeout.attach(&shutdown_sendLED, 0.2); //display we stopped to use cpu
}

void send_adcsstable_rtr()
{
	sendLED = 1; //display we are using cpu
	can1.write(CANMessage(1000, CANStandard));
	timeout.attach(&shutdown_sendLED, 0.5); //display we stopped to use cpu
}

void send_obcorientationmode()
{
	sendLED = 1; //display we are using cpu
	//TODO
	sendLED = 0; //display we stopped to use cpu
}

void send_highpriorityframe10()
{
	sendLED = 1; //display we are using cpu
	char data = 4;
	can1.write(CANMessage(10, &data, (char)8, CANData, CANStandard));
	timeout.attach(&shutdown_sendLED, 0.2); //display we stopped to use cpu
}
void send_midpriorityframe20()
{
	sendLED = 1; //display we are using cpu
	char data = 4;
	can1.write(CANMessage(20, &data, (char)8, CANData, CANStandard));
	timeout.attach(&shutdown_sendLED, 0.2); //display we stopped to use cpu
}
void send_midpriorityframe30()
{
	sendLED = 1; //display we are using cpu
	char data = 4;
	can1.write(CANMessage(30, &data, (char)8, CANData, CANStandard));
	timeout.attach(&shutdown_sendLED, 0.2); //display we stopped to use cpu
}
void send_lowpriorityframe42()
{
	sendLED = 1; //display we are using cpu
	char data = 4;
	can1.write(CANMessage(42, &data, (char)8, CANData, CANStandard));
	timeout.attach(&shutdown_sendLED, 0.2); //display we stopped to use cpu
}

void shutdown_sendLED()
{
	sendLED = 0; //display we stopped to use cpu
}
