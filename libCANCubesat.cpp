#include "libCANCubesat.h"

int counter = 0;
Serial pc(USBTX, USBRX);
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);

void read_callback()
{
	pc.printf("read_callback()\r\n");
	CANMessage msg;

	if (can1.read(msg))
	{
		led1 = !led1;

		// 4 . Decode data
		if (msg.type == CANData)
		{
			dataframe_handler(msg);
		}
		else if (msg.type == CANRemote)
		{
			remoteframe_handler(msg);
		}
	}
}

void dataframe_handler(CANMessage msg)
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

void remoteframe_handler(CANMessage msg)
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
