#include "main.h"
#include "mbed.h"
#include "libCANCubesat.h"

Ticker ticker;
RoleMC role;

DigitalIn isobc(A6);
DigitalIn isadcs(A5);
DigitalIn istcs(A6);
DigitalIn isedt(A6);

int main()
{
	//detect which role this card has to play
	startup_roledetect();

	switch (role)
	{
	case OBC:
		classobc_init();
		break;
	case ADCS:
		classadcs_init();
		break;
	case TCS:
		classtcs_init();
		break;
	case EDT:
		classedt_init();
		break;
	default:
		classobc_init();
		break;
	}

	

	while (1)
	{
		wait(10);
	}
}

void startup_roledetect()
{
	if (isobc.read() == 1 && isadcs.read() == 0 && isedt.read() == 0 && istcs.read() == 0)
	{
		//OBC activé
		role = OBC;
		pc.printf("OBC activé par defaut\r\n");
	}
	else if (isobc.read() == 0 && isadcs.read() == 1 && isedt.read() == 0 && istcs.read() == 0)
	{
		//ADCS activé
		role = ADCS;
		pc.printf("ADCS activé par defaut\r\n");
	}
	else if (isobc.read() == 0 && isadcs.read() == 0 && isedt.read() == 1 && istcs.read() == 0)
	{
		//EDT activé
		role = EDT;
		pc.printf("EDT activé par defaut\r\n");
	}
	else if (isobc.read() == 0 && isadcs.read() == 0 && isedt.read() == 0 && istcs.read() == 1)
	{
		//TCS activé
		role = TCS;
		pc.printf("TCS activé par defaut\r\n");
	}
	else
	{
		//OBC activé par defaut
		role = OBC;
		pc.printf("OBC activé par defaut\r\n");
	}
}

/**
 * TODO
 */
void classobc_init()
{

	pc.printf("classobc_init()\t");

	//int filter1 = can1.filter(0x100, 0x7FF, CANStandard);
	/*if (filter1 == 0) {
		pc.printf("ERROR setting filter1\n");
		return 0;
	    }*/

	//ticker.attach(&send_adcsstable, 2);
	//ticker.attach(&send_adcsstable_rtr, 2);

	// when we use the attach function, deep sleep can't be enabled because the CAN device must be able to generate an interruption
	can1.attach(&OBC_read_callback, CAN::RxIrq);		 // message received
	can1.attach(&transmitted_callback, CAN::TxIrq);  // message transmitted or aborted
	can1.attach(&errorwarning_callback, CAN::EwIrq); // error warning
	can1.attach(&do_callback, CAN::DoIrq);			 // data overrun
	can1.attach(&wakeup_callback, CAN::WuIrq);		 // wake-up
	can1.attach(&errorpassive_callback, CAN::EpIrq); // error passive
	can1.attach(&al_callback, CAN::AlIrq);			 // arbitration lost
	can1.attach(&be_callback, CAN::BeIrq);			 // bus error
}

/**
 * TODO
 */
void classadcs_init()
{
	pc.printf("ADCS case not implemented!");
}

/**
 * TODO
 */
void classtcs_init()
{
	pc.printf("TCS case not implemented!");
}

/**
 * TODO
 */
void classedt_init()
{
	pc.printf("EDT case not implemented!");
}