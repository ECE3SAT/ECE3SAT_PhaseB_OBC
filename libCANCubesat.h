

#include <string>
#include "classobc.h"
#include "dataview-uniq.h"
#include "obc.h"
#include "Messagerie.h"

#ifndef __USER_CODE_H_libcan__
#define __USER_CODE_H_libcan__

class libCANCubesat
{
  public:
    virtual void encode();
    virtual void decode();

    enum MessageIds
    {
        ADCS_is_stable = 1000,
        OBC_orientation_mode_command = 1001,
        OBC_profileTCS = 1002
    };

    virtual ~libCANCubesat();
};

void OBC_read_callback();

void OBC_dataframe_handler(CANMessage msg);

void OBC_remoteframe_handler(CANMessage msg);

void ADCS_read_callback();

void ADCS_dataframe_handler(CANMessage msg);

void ADCS_remoteframe_handler(CANMessage msg);

void EDT_read_callback();

void EDT_dataframe_handler(CANMessage msg);

void EDT_remoteframe_handler(CANMessage msg);

void TCS_read_callback();

void TCS_dataframe_handler(CANMessage msg);

void TCS_remoteframe_handler(CANMessage msg);

void transmitted_callback();

void errorwarning_callback();

void do_callback();

void wakeup_callback();

void errorpassive_callback();

void al_callback();

void be_callback();

void send_adcsstable();

void send_adcsstable_rtr();

void send_obcorientationmode();

void shutdown_sendLED();


#endif