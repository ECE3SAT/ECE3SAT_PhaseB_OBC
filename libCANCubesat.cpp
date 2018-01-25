#include "libCANCubesat.h"

int counter = 0;
Serial pc(USBTX, USBRX);
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);

void read_callback()
{
	pc.printf("read_callback()\r\n");
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
			MessageAdcsStable::FromCanBus(msg.data, msg.len);
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
	asn1SccADCS_is_stable value = TRUE;
	MessageAdcsStable msg(value);
	msg.send();
}

void send_obcorientationmode()
{
	//TODO
}
