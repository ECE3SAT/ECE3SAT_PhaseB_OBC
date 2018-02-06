#include <stdio.h>

#include "PrintTypes.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintOBC_profileTCS(const char *paramName, const asn1SccOBC_profileTCS *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    printf("%s %d\n", paramName, (int)(*pData));
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintOBC_orientation_mode_command(const char *paramName, const asn1SccOBC_orientation_mode_command *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    printf("%s %d\n", paramName, (int)(*pData));
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintOBC_mission_phase(const char *paramName, const asn1SccOBC_mission_phase *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    printf("%s %d\n", paramName, (int)(*pData));
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintTASTE_Boolean(const char *paramName, const asn1SccTASTE_Boolean *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    printf("%s %d\n", paramName, (int)(*pData));
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    printf("%s %d\n", paramName, (int)(*pData));
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    #if WORD_SIZE==8
    printf("%s %lld\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    #if WORD_SIZE==8
    printf("%s %lld\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    #if WORD_SIZE==8
    printf("%s %lld\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    #if WORD_SIZE==8
    printf("%s %lld\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintADCS_is_stable(const char *paramName, const asn1SccADCS_is_stable *pData)
{
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
    printf("%s %d\n", paramName, (int)(*pData));
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

