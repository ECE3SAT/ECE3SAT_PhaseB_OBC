#ifndef __PRINTTYPESASASN1_H__
#define __PRINTTYPESASASN1_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h" // Generated by ASN1SCC

void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData);
void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData);
void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData);
void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData);
void PrintASN1OBC_profileTCS(const char *paramName, const asn1SccOBC_profileTCS *pData);
void PrintASN1TASTE_Boolean(const char *paramName, const asn1SccTASTE_Boolean *pData);
void PrintASN1ADCS_is_stable(const char *paramName, const asn1SccADCS_is_stable *pData);
void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData);
void PrintASN1OBC_orientation_mode_command(const char *paramName, const asn1SccOBC_orientation_mode_command *pData);

#ifdef __cplusplus
}
#endif

#endif
