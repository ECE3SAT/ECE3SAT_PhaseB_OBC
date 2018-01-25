

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

void read_callback();

void transmitted_callback();

void errorwarning_callback();

void do_callback();

void wakeup_callback();

void errorpassive_callback();

void al_callback();

void be_callback();

void send_adcsstable();

void send_obcorientationmode();



#endif