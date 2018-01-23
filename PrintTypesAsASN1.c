#include <stdio.h>

#include "PrintTypesAsASN1.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s T-Int8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%lld", (*pData));
    #else
    printf("%d", (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s T-Int32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%lld", (*pData));
    #else
    printf("%d", (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s T-UInt8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%lld", (*pData));
    #else
    printf("%d", (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s T-UInt32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%lld", (*pData));
    #else
    printf("%d", (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1OBC_profileTCS(const char *paramName, const asn1SccOBC_profileTCS *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s OBC-profileTCS ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("full");
        break;
    case 1:
        printf("lowpower");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1TASTE_Boolean(const char *paramName, const asn1SccTASTE_Boolean *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s TASTE-Boolean ::= ", paramName);
    printf("%s ", paramName);
    printf("%s", (int)(*pData)?"TRUE":"FALSE");
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ADCS_is_stable(const char *paramName, const asn1SccADCS_is_stable *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s ADCS-is-stable ::= ", paramName);
    printf("%s ", paramName);
    printf("%s", (int)(*pData)?"TRUE":"FALSE");
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s T-Boolean ::= ", paramName);
    printf("%s ", paramName);
    printf("%s", (int)(*pData)?"TRUE":"FALSE");
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1OBC_orientation_mode_command(const char *paramName, const asn1SccOBC_orientation_mode_command *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    //printf("%s OBC-orientation-mode-command ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("detumbling");
        break;
    case 1:
        printf("nadir-pointing");
        break;
    case 2:
        printf("target-tracking");
        break;
    case 3:
        printf("power-maximisation");
        break;
    case 4:
        printf("boot");
        break;
    case 5:
        printf("shutdown");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

