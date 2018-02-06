#ifndef __PRINTTYPES_H__
#define __PRINTTYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h" // Generated by ASN1SCC

void PrintOBC_profileTCS(const char *paramName, const asn1SccOBC_profileTCS *pData);
void PrintOBC_orientation_mode_command(const char *paramName, const asn1SccOBC_orientation_mode_command *pData);
void PrintOBC_mission_phase(const char *paramName, const asn1SccOBC_mission_phase *pData);
void PrintTASTE_Boolean(const char *paramName, const asn1SccTASTE_Boolean *pData);
void PrintT_Boolean(const char *paramName, const asn1SccT_Boolean *pData);
void PrintT_UInt32(const char *paramName, const asn1SccT_UInt32 *pData);
void PrintT_UInt8(const char *paramName, const asn1SccT_UInt8 *pData);
void PrintT_Int32(const char *paramName, const asn1SccT_Int32 *pData);
void PrintT_Int8(const char *paramName, const asn1SccT_Int8 *pData);
void PrintADCS_is_stable(const char *paramName, const asn1SccADCS_is_stable *pData);

#ifdef __cplusplus
}
#endif

#endif
