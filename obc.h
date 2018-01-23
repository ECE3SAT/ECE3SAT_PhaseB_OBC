/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_obc__
#define __USER_CODE_H_obc__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void obc_startup();

void obc_PI_receiveAdcsStable(const asn1SccADCS_is_stable *);

void obc_PI_sendOrientationMode(const asn1SccOBC_orientation_mode_command *);

void obc_PI_sendTcsProfile(const asn1SccOBC_profileTCS *);

#ifdef __cplusplus
}
#endif


#endif
