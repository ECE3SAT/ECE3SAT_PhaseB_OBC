/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_adcs__
#define __USER_CODE_H_adcs__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void adcs_startup();

void adcs_PI_receiveOrientationMode(const asn1SccOBC_orientation_mode_command *);

void adcs_PI_sendAdcsStable(const asn1SccADCS_is_stable *);

#ifdef __cplusplus
}
#endif


#endif
