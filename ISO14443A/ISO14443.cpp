#include "CR95.h"
#include "mbed.h"
#include "helper.h"

/*Set the protocol to ISO 14443 A*/
void CR95::Select_ISO_IEC_14443_A_Protocol()
{
    unsigned short txrate = ISO14443A_TXVALUE_106K;
    unsigned short rxrate = ISO14443A_RXVALUE_106K;
    unsigned short parameters = ((txrate<<ISO14443A_OFFSET_TXDATARATE) & ISO14443A_MASK_TXDATARATE) |
                                ((rxrate<<ISO14443A_OFFSET_RXDATARATE) & ISO14443A_MASK_RXDATARATE);
    ProtocolSelect(ISO14443A_PROTOCOLSELECT_NBBYTE, PROTOCOL_TAG_ISO14443A, &parameters);
    
    _sdata[0] = 0x3A;
    _sdata[1] = 0;
    _sdata[2] = 0x58;
    _sdata[3] = 0x04;
    
    writeCmd(CMD_WRREG, 4);
    readCmd();
}

/*Checks if a tag using ISO 14443 A is present in field*/
void CR95::Check14443ATagPresent()
{
    static int counter = 0;
    unsigned short SAKByte = 0;
    /*Send REQA Command*/
    ISO14443A_REQA();

    counter++;
    if(_res == 0x80)
    {
        _tagPresent = true;
        counter = 0;
    }
    else
    {
        _tagPresent = false;
        counter = 6;
        return;
    }
    
    /*Send SELECT Sequence*/
    ISO14443A_SelectSequence(&SAKByte);  
    /*Get the UID of the tag*/
}


/*Sends the REQA command to a ISO 14443 Tag*/
void CR95::ISO14443A_REQA()
{
    _sdata[0] = 0x52;//ISO14443A_CMDCODE_REQA;
    _sdata[1] = ISO14443A_NBSIGNIFICANTBIT_7;
    writeCmd(CMD_SENDRECV, 2);
    _res = 0;
    readCmd();
}

void CR95::ISO14443A_WUPA()
{
    _sdata[0] = ISO14443A_CMDCODE_WUPA;
    _sdata[1] = ISO14443A_NBSIGNIFICANTBIT_7;
    writeCmd(CMD_SENDRECV,2);
    _res = 0;
    readCmd();
}

void CR95::ISO14443A_SelectSequence(unsigned short *SAKByte)
{
    *SAKByte = 0;
    ISO14443A_REQA();
    if(_res != 0x80)
    {
        ISO14443A_REQA();
        if(_res != 0x80)
        {   
            return;
        }
    }
        
    // === Select cascade level 1 ===
    _sdata[0] = ISO14443A_CMDCODE_SELECT_LVL1;
    _sdata[1] = ISO14443A_NVB_20;
    _sdata[2] = ISO14443A_NBSIGNIFICANTBIT_8;
    writeCmd(CMD_SENDRECV, 3);
    _res = 0;
    readCmd();
    if(_rdata[0] == 0x88)
    {
        UID[0] = _rdata[1];
        UID[1] = _rdata[2];
        UID[2] = _rdata[3];
    }
    else
    {
        UID[0] = _rdata[0];
        UID[1] = _rdata[1];
        UID[2] = _rdata[2];
    }
    //Select tag
    _sdata[0] = ISO14443A_CMDCODE_SELECT_LVL1;
    _sdata[1] = ISO14443A_NVB_70;
    _sdata[2] = _rdata[0];
    _sdata[3] = _rdata[1];
    _sdata[4] = _rdata[2];
    _sdata[5] = _rdata[3];
    _sdata[6] = _rdata[4];
    _sdata[7] = ISO14443A_NBSIGNIFICANTBIT_8 | ISO14443A_APPENDCRC;
    writeCmd(CMD_SENDRECV, 8);
    _res = 0;
    readCmd();
    _sdata[0] = ISO14443A_CMDCODE_SELECT_LVL2;
    _sdata[1] = ISO14443A_NVB_20;
    _sdata[2] = ISO14443A_NBSIGNIFICANTBIT_8;
    writeCmd(CMD_SENDRECV, 3);
    _res = 0;
    readCmd();
    UID[3] = _rdata[0];
    UID[4] = _rdata[1];
    UID[5] = _rdata[2];
    UID[6] = _rdata[3];
    UIDLength = 7;  
    
}

