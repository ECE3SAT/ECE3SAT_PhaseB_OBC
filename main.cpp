#include "main.h"
#include "libCANCubesat.h"

Ticker ticker;

/**
 * Main loop
 * 
 * Empty because we use interruption mecanisms
 */
int main()
{
	classobc_init();

	while (1)
	{
		wait(10);
	}
}

/**
 * OBC initialization function
 */
void classobc_init()
{
	pc.printf("classobc_init()\t");

	/* CAN INIT */

	//1 - CAN filters : can be used to ignore frames with id ranges
	/*int filter1 = can1.filter(0x100, 0x7FF, CANStandard);
	if (filter1 == 0) {
		pc.printf("ERROR setting filter1\n");
		return 0;
	    }*/

	//2 - CAN callbacks : interruption handling
	// when we use the attach function, deep sleep can't be enabled because the CAN device must be able to generate an interruption
	can1.attach(&read_callback, CAN::RxIrq);		 // message received
	can1.attach(&transmitted_callback, CAN::TxIrq);  // message transmitted or aborted
	can1.attach(&errorwarning_callback, CAN::EwIrq); // error warning
	can1.attach(&do_callback, CAN::DoIrq);			 // data overrun
	can1.attach(&wakeup_callback, CAN::WuIrq);		 // wake-up
	can1.attach(&errorpassive_callback, CAN::EpIrq); // error passive
	can1.attach(&al_callback, CAN::AlIrq);			 // arbitration lost
	can1.attach(&be_callback, CAN::BeIrq);			 // bus error

	/* BEHAVIOUR INIT */
	//send messages periodically on the can bus
	//ticker.attach(&send_adcsstable, 2);
	//ticker.attach(&send_adcsstable_rtr, 2);
}