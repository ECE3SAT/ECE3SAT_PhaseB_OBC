#include "main.h"
#include "mbed.h"
#include "libCANCubesat.h"

Ticker ticker;
RoleMC role;
int mode;

DigitalIn isadcs(A0);
DigitalIn istcs(A1);
DigitalIn isedt(A2);
DigitalIn modeflood(A3);

int main()
{
	pc.baud(115200);	//CAN baudrate setup
	set_time(1256729737);  // Set RTC time to Wed, 28 Oct 2009 11:35:37

	//detect which role this card has to play
	startup_roledetect();
	//detect if mode flood is activated
	startup_modedetect();

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

/**
 * Detecte le rôle de chaque carte au demarrage selon la pin alimentée
 */
void startup_roledetect()
{
	if (isadcs.read() == 1 && isedt.read() == 0 && istcs.read() == 0)
	{
		//ADCS activé
		role = ADCS;
		pc.printf("ADCS activé par defaut\r\n");
	}
	else if (isadcs.read() == 0 && isedt.read() == 1 && istcs.read() == 0)
	{
		//EDT activé
		role = EDT;
		pc.printf("EDT activé par defaut\r\n");
	}
	else if (isadcs.read() == 0 && isedt.read() == 0 && istcs.read() == 1)
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
 * le mode flood sert à activer l'emission de messages sur toutes les cartes afin de spammer le bus can.
 */
void startup_modedetect()
{
	if (modeflood.read() == 1 )
	{
		//mode flood activé
		mode = 1;
		pc.printf("FLOOD activé\r\n");
	}
	else
	{
		//mode flood désactivé
		mode = 0;
		pc.printf("FLOOD désactivé\r\n");
	}
}

/**
 * Initialise la carte pour qu'elle joue le role de l'obc.
 * Ajoutez ici les comportements specifiques à ce module.
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

	if(mode)
	{
		ticker.attach(&send_lowpriorityframe42, 2);
		can1.attach(0, CAN::RxIrq);		 // disable read callback in this mode to spam more
	}
}

/**
 * Initialise la carte pour qu'elle joue le role de l'adcs.
 * Ajoutez ici les comportements specifiques à ce module.
 */
void classadcs_init()
{
	ticker.attach(&send_adcsstable, 2);

	// when we use the attach function, deep sleep can't be enabled because the CAN device must be able to generate an interruption
	can1.attach(&ADCS_read_callback, CAN::RxIrq);		 // message received
	can1.attach(&transmitted_callback, CAN::TxIrq);  // message transmitted or aborted
	can1.attach(&errorwarning_callback, CAN::EwIrq); // error warning
	can1.attach(&do_callback, CAN::DoIrq);			 // data overrun
	can1.attach(&wakeup_callback, CAN::WuIrq);		 // wake-up
	can1.attach(&errorpassive_callback, CAN::EpIrq); // error passive
	can1.attach(&al_callback, CAN::AlIrq);			 // arbitration lost
	can1.attach(&be_callback, CAN::BeIrq);			 // bus error

	if(mode)
	{
		ticker.attach(&send_midpriorityframe20, 0.002);
		can1.attach(0, CAN::RxIrq);		 // disable read callback in this mode to spam more
	}
}

/**
 * Initialise la carte pour qu'elle joue le role de tcs.
 * Ajoutez ici les comportements specifiques à ce module.
 */
void classtcs_init()
{
	// when we use the attach function, deep sleep can't be enabled because the CAN device must be able to generate an interruption
	can1.attach(&TCS_read_callback, CAN::RxIrq);		 // message received
	can1.attach(&transmitted_callback, CAN::TxIrq);  // message transmitted or aborted
	can1.attach(&errorwarning_callback, CAN::EwIrq); // error warning
	can1.attach(&do_callback, CAN::DoIrq);			 // data overrun
	can1.attach(&wakeup_callback, CAN::WuIrq);		 // wake-up
	can1.attach(&errorpassive_callback, CAN::EpIrq); // error passive
	can1.attach(&al_callback, CAN::AlIrq);			 // arbitration lost
	can1.attach(&be_callback, CAN::BeIrq);			 // bus error

	if(mode)
	{
		ticker.attach(&send_highpriorityframe10, 1);
		can1.attach(0, CAN::RxIrq);		 // disable read callback in this mode to spam more
	}
}

/**
 * Initialise la carte pour qu'elle joue le role de l'edt.
 * Ajoutez ici les comportements specifiques à ce module.
 */
void classedt_init()
{
	// when we use the attach function, deep sleep can't be enabled because the CAN device must be able to generate an interruption
	can1.attach(&EDT_read_callback, CAN::RxIrq);		 // message received
	can1.attach(&transmitted_callback, CAN::TxIrq);  // message transmitted or aborted
	can1.attach(&errorwarning_callback, CAN::EwIrq); // error warning
	can1.attach(&do_callback, CAN::DoIrq);			 // data overrun
	can1.attach(&wakeup_callback, CAN::WuIrq);		 // wake-up
	can1.attach(&errorpassive_callback, CAN::EpIrq); // error passive
	can1.attach(&al_callback, CAN::AlIrq);			 // arbitration lost
	can1.attach(&be_callback, CAN::BeIrq);			 // bus error

	if(mode)
	{
		ticker.attach(&send_midpriorityframe30, 0.002);
		can1.attach(0, CAN::RxIrq);		 // disable read callback in this mode to spam more
	}
}