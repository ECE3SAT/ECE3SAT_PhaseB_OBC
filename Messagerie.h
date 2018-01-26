/*
 * Messagerie.h
 *
 *  Created on: 25 janv. 2018
 *      Author: root
 */

#ifndef MESSAGERIE_H_
#define MESSAGERIE_H_

#include "classobc.h"
#include "libCANCubesat.h"
#include "dataview-uniq.h"

class MessageBase
{
  public:
    // send a msg on the CAN bus.
    void send(void)
    {
        CANMessage msg;

        if (this->encode(&msg) == 0) // encode using the subclass method
        {
            can1.write(msg);  // send on the CAN bus
        }
    };

  private:
    virtual int encode(CANMessage *msg) = 0;
};

class MessageAdcsStable : public MessageBase
{
  private:
    asn1SccADCS_is_stable _data;

  public:
    MessageAdcsStable(bool is_stable)
    {
        _data = is_stable;
    };

    static void FromCanBus(unsigned char *buffer, int len)
    {
        BitStream bitStrm;
        BitStream_AttachBuffer(&bitStrm, buffer, len);

        int errCode;
        asn1SccADCS_is_stable _data;
        flag ret = asn1SccADCS_is_stable_Decode(&_data, &bitStrm, &errCode);

        if (ret)
            MessageAdcsStable(_data).handle_msg();
    };

  private:
    int encode(CANMessage *msg)
    {
        int errorCode;
        // 1 . Define a buffer where the uPER stream will be written to
        byte perBuffer[asn1SccADCS_is_stable_REQUIRED_BYTES_FOR_ENCODING];
        // 2 . Define a bit stream variable
        BitStream bitStrm;
        // 3 . Data to be encode ( assumed to be filled elsewhere )
        asn1SccADCS_is_stable value = _data;

        // 4. Initialize bit stream
        BitStream_Init(&bitStrm, perBuffer, asn1SccADCS_is_stable_REQUIRED_BYTES_FOR_ENCODING);
        // 5 . Encode
        if (!asn1SccADCS_is_stable_Encode(&value, &bitStrm, &errorCode, TRUE))
        {
            pc.printf(" Encode failed . Error code is %d \n ", errorCode);
            return 1;
        }
        else
        {
            CANMessage tmp(
                libCANCubesat::ADCS_is_stable, (char *)perBuffer, asn1SccADCS_is_stable_REQUIRED_BYTES_FOR_ENCODING
            );
            memcpy(msg, &tmp, sizeof(CANMessage));
            return 0;
        }
    }

    void handle_msg(void)
    {
        // Do something
        pc.printf("MessageAdcsStable::handle_msg(%d)\r\n", this->_data);
    }
};

#endif /* MESSAGERIE_H_ */