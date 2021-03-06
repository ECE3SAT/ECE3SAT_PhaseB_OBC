/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "dataview-uniq.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccTASTE_Boolean_Initialize(asn1SccTASTE_Boolean* pVal)
{
    *pVal = (asn1SccTASTE_Boolean) FALSE;
}
#endif

 
flag asn1SccTASTE_Boolean_IsConstraintValid(const asn1SccTASTE_Boolean* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = TRUE; *pErrCode = 0;

	return ret;
}

flag asn1SccTASTE_Boolean_Encode(const asn1SccTASTE_Boolean* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccTASTE_Boolean_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_AppendBit(pBitStrm,*pVal);
    }

	return ret;
}

flag asn1SccTASTE_Boolean_Decode(asn1SccTASTE_Boolean* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_ReadBit(pBitStrm, pVal);
	*pErrCode = ret ? 0 : 268435457;

	return ret;
}

flag asn1SccTASTE_Boolean_ACN_Encode(const asn1SccTASTE_Boolean* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccTASTE_Boolean_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    {
	    	static byte true_data[] = {0x80};
	    	static byte false_data[] = {0x7F};
	        byte* tmp = *pVal ? true_data : false_data; 
	        BitStream_AppendBits(pBitStrm, tmp, 1);
	    }
    }

	return ret;
}

flag asn1SccTASTE_Boolean_ACN_Decode(asn1SccTASTE_Boolean* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    {
    	static byte tmp[] = {0x80};
    	ret = BitStream_ReadBitPattern(pBitStrm, tmp, 1, pVal);
        *pErrCode = ret ? 0 : 268435458;
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccADCS_is_stable_Initialize(asn1SccADCS_is_stable* pVal)
{
    *pVal = (asn1SccADCS_is_stable) FALSE;
}
#endif

 
flag asn1SccADCS_is_stable_IsConstraintValid(const asn1SccADCS_is_stable* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = TRUE; *pErrCode = 0;

	return ret;
}

flag asn1SccADCS_is_stable_Encode(const asn1SccADCS_is_stable* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccADCS_is_stable_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_AppendBit(pBitStrm,*pVal);
    }

	return ret;
}

flag asn1SccADCS_is_stable_Decode(asn1SccADCS_is_stable* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_ReadBit(pBitStrm, pVal);
	*pErrCode = ret ? 0 : 268435459;

	return ret;
}

flag asn1SccADCS_is_stable_ACN_Encode(const asn1SccADCS_is_stable* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccADCS_is_stable_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    {
	    	static byte true_data[] = {0x80};
	    	static byte false_data[] = {0x7F};
	        byte* tmp = *pVal ? true_data : false_data; 
	        BitStream_AppendBits(pBitStrm, tmp, 1);
	    }
    }

	return ret;
}

flag asn1SccADCS_is_stable_ACN_Decode(asn1SccADCS_is_stable* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    {
    	static byte tmp[] = {0x80};
    	ret = BitStream_ReadBitPattern(pBitStrm, tmp, 1, pVal);
        *pErrCode = ret ? 0 : 268435460;
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccOBC_orientation_mode_command_Initialize(asn1SccOBC_orientation_mode_command* pVal)
{
    *pVal = (asn1SccOBC_orientation_mode_command) asn1Sccdetumbling;
}
#endif

 
flag asn1SccOBC_orientation_mode_command_IsConstraintValid(const asn1SccOBC_orientation_mode_command* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = ((((((*pVal == asn1Sccdetumbling) || (*pVal == asn1Sccnadir_pointing)) || (*pVal == asn1Scctarget_tracking)) || (*pVal == asn1Sccpower_maximisation)) || (*pVal == asn1Sccboot)) || (*pVal == asn1Sccshutdown));
	*pErrCode = ret ? 0 : ERR_asn1SccOBC_orientation_mode_command;

	return ret;
}

flag asn1SccOBC_orientation_mode_command_Encode(const asn1SccOBC_orientation_mode_command* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccOBC_orientation_mode_command_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case asn1Sccdetumbling:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 5);
	        	break;
	        case asn1Sccnadir_pointing:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 5);
	        	break;
	        case asn1Scctarget_tracking:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 5);
	        	break;
	        case asn1Sccpower_maximisation:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 3, 0, 5);
	        	break;
	        case asn1Sccboot:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 4, 0, 5);
	        	break;
	        case asn1Sccshutdown:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 5, 0, 5);
	        	break;
	        default:
	    	    *pErrCode = 1073741825; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag asn1SccOBC_orientation_mode_command_Decode(asn1SccOBC_orientation_mode_command* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 5);
	*pErrCode = ret ? 0 : 268435461;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = asn1Sccdetumbling;
	            break;
	        case 1: 
	            *pVal = asn1Sccnadir_pointing;
	            break;
	        case 2: 
	            *pVal = asn1Scctarget_tracking;
	            break;
	        case 3: 
	            *pVal = asn1Sccpower_maximisation;
	            break;
	        case 4: 
	            *pVal = asn1Sccboot;
	            break;
	        case 5: 
	            *pVal = asn1Sccshutdown;
	            break;
	        default:
		        *pErrCode = 1073741826;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}

flag asn1SccOBC_orientation_mode_command_ACN_Encode(const asn1SccOBC_orientation_mode_command* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;

    ret = bCheckConstraints ? asn1SccOBC_orientation_mode_command_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) { 
	        case asn1Sccdetumbling:
	            intVal = 0;
	            break;
	        case asn1Sccnadir_pointing:
	            intVal = 1;
	            break;
	        case asn1Scctarget_tracking:
	            intVal = 2;
	            break;
	        case asn1Sccpower_maximisation:
	            intVal = 3;
	            break;
	        case asn1Sccboot:
	            intVal = 4;
	            break;
	        case asn1Sccshutdown:
	            intVal = 5;
	            break;
	        default:
	            ret = FALSE;                            //COVERAGE_IGNORE
	            *pErrCode = 1073741827;      //COVERAGE_IGNORE
	    }
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, intVal, 0, 5);
    }

	return ret;
}

flag asn1SccOBC_orientation_mode_command_ACN_Decode(asn1SccOBC_orientation_mode_command* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, &intVal, 0, 5);
    *pErrCode = ret ? 0 : 268435462;
    if (ret) {
        switch (intVal) {
            case 0:
                *pVal = asn1Sccdetumbling;
                break;
            case 1:
                *pVal = asn1Sccnadir_pointing;
                break;
            case 2:
                *pVal = asn1Scctarget_tracking;
                break;
            case 3:
                *pVal = asn1Sccpower_maximisation;
                break;
            case 4:
                *pVal = asn1Sccboot;
                break;
            case 5:
                *pVal = asn1Sccshutdown;
                break;
        default:
            ret = FALSE;                            //COVERAGE_IGNORE
            *pErrCode = 1073741828;      //COVERAGE_IGNORE
        };
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccOBC_profileTCS_Initialize(asn1SccOBC_profileTCS* pVal)
{
    *pVal = (asn1SccOBC_profileTCS) asn1Sccfull;
}
#endif

 
flag asn1SccOBC_profileTCS_IsConstraintValid(const asn1SccOBC_profileTCS* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = ((*pVal == asn1Sccfull) || (*pVal == asn1Scclowpower));
	*pErrCode = ret ? 0 : ERR_asn1SccOBC_profileTCS;

	return ret;
}

flag asn1SccOBC_profileTCS_Encode(const asn1SccOBC_profileTCS* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccOBC_profileTCS_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case asn1Sccfull:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 1);
	        	break;
	        case asn1Scclowpower:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 1);
	        	break;
	        default:
	    	    *pErrCode = 1073741829; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag asn1SccOBC_profileTCS_Decode(asn1SccOBC_profileTCS* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 1);
	*pErrCode = ret ? 0 : 268435463;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = asn1Sccfull;
	            break;
	        case 1: 
	            *pVal = asn1Scclowpower;
	            break;
	        default:
		        *pErrCode = 1073741830;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}

flag asn1SccOBC_profileTCS_ACN_Encode(const asn1SccOBC_profileTCS* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;

    ret = bCheckConstraints ? asn1SccOBC_profileTCS_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) { 
	        case asn1Sccfull:
	            intVal = 0;
	            break;
	        case asn1Scclowpower:
	            intVal = 1;
	            break;
	        default:
	            ret = FALSE;                            //COVERAGE_IGNORE
	            *pErrCode = 1073741831;      //COVERAGE_IGNORE
	    }
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, intVal, 0, 1);
    }

	return ret;
}

flag asn1SccOBC_profileTCS_ACN_Decode(asn1SccOBC_profileTCS* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, &intVal, 0, 1);
    *pErrCode = ret ? 0 : 268435464;
    if (ret) {
        switch (intVal) {
            case 0:
                *pVal = asn1Sccfull;
                break;
            case 1:
                *pVal = asn1Scclowpower;
                break;
        default:
            ret = FALSE;                            //COVERAGE_IGNORE
            *pErrCode = 1073741832;      //COVERAGE_IGNORE
        };
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccT_Int32_Initialize(asn1SccT_Int32* pVal)
{
    *pVal = (asn1SccT_Int32) -2147483648LL;
}
#endif

 
flag asn1SccT_Int32_IsConstraintValid(const asn1SccT_Int32* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (-2147483648LL <= *pVal && *pVal <= 2147483647LL);
	*pErrCode = ret ? 0 : ERR_asn1SccT_Int32;

	return ret;
}

flag asn1SccT_Int32_Encode(const asn1SccT_Int32* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccT_Int32_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, *pVal, -2147483648LL, 2147483647LL);
    }

	return ret;
}

flag asn1SccT_Int32_Decode(asn1SccT_Int32* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, pVal, -2147483648LL, 2147483647LL);
	*pErrCode = ret ? 0 : 268435465;

	return ret;
}

flag asn1SccT_Int32_ACN_Encode(const asn1SccT_Int32* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccT_Int32_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, *pVal, -2147483648LL, 2147483647LL);
    }

	return ret;
}

flag asn1SccT_Int32_ACN_Decode(asn1SccT_Int32* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, pVal, -2147483648LL, 2147483647LL);
    *pErrCode = ret ? 0 : 268435466;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccT_UInt32_Initialize(asn1SccT_UInt32* pVal)
{
    *pVal = (asn1SccT_UInt32) 0;
}
#endif

 
flag asn1SccT_UInt32_IsConstraintValid(const asn1SccT_UInt32* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 4294967295LL);
	*pErrCode = ret ? 0 : ERR_asn1SccT_UInt32;

	return ret;
}

flag asn1SccT_UInt32_Encode(const asn1SccT_UInt32* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccT_UInt32_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 4294967295LL);
    }

	return ret;
}

flag asn1SccT_UInt32_Decode(asn1SccT_UInt32* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : 268435467;

	return ret;
}

flag asn1SccT_UInt32_ACN_Encode(const asn1SccT_UInt32* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccT_UInt32_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 4294967295LL);
    }

	return ret;
}

flag asn1SccT_UInt32_ACN_Decode(asn1SccT_UInt32* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
    *pErrCode = ret ? 0 : 268435468;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccT_Int8_Initialize(asn1SccT_Int8* pVal)
{
    *pVal = (asn1SccT_Int8) -128;
}
#endif

 
flag asn1SccT_Int8_IsConstraintValid(const asn1SccT_Int8* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (-128 <= *pVal && *pVal <= 127);
	*pErrCode = ret ? 0 : ERR_asn1SccT_Int8;

	return ret;
}

flag asn1SccT_Int8_Encode(const asn1SccT_Int8* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccT_Int8_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, *pVal, -128, 127);
    }

	return ret;
}

flag asn1SccT_Int8_Decode(asn1SccT_Int8* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, pVal, -128, 127);
	*pErrCode = ret ? 0 : 268435469;

	return ret;
}

flag asn1SccT_Int8_ACN_Encode(const asn1SccT_Int8* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccT_Int8_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, *pVal, -128, 127);
    }

	return ret;
}

flag asn1SccT_Int8_ACN_Decode(asn1SccT_Int8* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, pVal, -128, 127);
    *pErrCode = ret ? 0 : 268435470;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccT_UInt8_Initialize(asn1SccT_UInt8* pVal)
{
    *pVal = (asn1SccT_UInt8) 0;
}
#endif

 
flag asn1SccT_UInt8_IsConstraintValid(const asn1SccT_UInt8* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 255);
	*pErrCode = ret ? 0 : ERR_asn1SccT_UInt8;

	return ret;
}

flag asn1SccT_UInt8_Encode(const asn1SccT_UInt8* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccT_UInt8_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 255);
    }

	return ret;
}

flag asn1SccT_UInt8_Decode(asn1SccT_UInt8* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
	*pErrCode = ret ? 0 : 268435471;

	return ret;
}

flag asn1SccT_UInt8_ACN_Encode(const asn1SccT_UInt8* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccT_UInt8_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 255);
    }

	return ret;
}

flag asn1SccT_UInt8_ACN_Decode(asn1SccT_UInt8* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
    *pErrCode = ret ? 0 : 268435472;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void asn1SccT_Boolean_Initialize(asn1SccT_Boolean* pVal)
{
    *pVal = (asn1SccT_Boolean) FALSE;
}
#endif

 
flag asn1SccT_Boolean_IsConstraintValid(const asn1SccT_Boolean* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = TRUE; *pErrCode = 0;

	return ret;
}

flag asn1SccT_Boolean_Encode(const asn1SccT_Boolean* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? asn1SccT_Boolean_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_AppendBit(pBitStrm,*pVal);
    }

	return ret;
}

flag asn1SccT_Boolean_Decode(asn1SccT_Boolean* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_ReadBit(pBitStrm, pVal);
	*pErrCode = ret ? 0 : 268435473;

	return ret;
}

flag asn1SccT_Boolean_ACN_Encode(const asn1SccT_Boolean* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? asn1SccT_Boolean_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    {
	    	static byte true_data[] = {0x80};
	    	static byte false_data[] = {0x7F};
	        byte* tmp = *pVal ? true_data : false_data; 
	        BitStream_AppendBits(pBitStrm, tmp, 1);
	    }
    }

	return ret;
}

flag asn1SccT_Boolean_ACN_Decode(asn1SccT_Boolean* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    {
    	static byte tmp[] = {0x80};
    	ret = BitStream_ReadBitPattern(pBitStrm, tmp, 1, pVal);
        *pErrCode = ret ? 0 : 268435474;
    }
    return ret;
}

