/* User code: This file will not be overwritten by TASTE. */

#include "obc.h"

//#include "classobc.h"


void obc_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void obc_PI_receiveAdcsStable(const asn1SccADCS_is_stable *IN_ai_isStable)
{
    //pc.printf("obc_PI_receiveAdcsStable(): data=%d\t", IN_ai_isStable);
}

void obc_PI_sendOrientationMode(const asn1SccOBC_orientation_mode_command *IN_ai_mode)
{
    /* Write your code here! */
}

void obc_PI_sendTcsProfile(const asn1SccOBC_profileTCS *IN_ai_profile)
{
    /* Write your code here! */
}
