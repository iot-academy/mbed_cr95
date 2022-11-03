#ifndef __CR95_H__
#define __CR95_H__

#include "mbed.h"

// CR95HF Commands Definition
#define    CMD_IDN                    0x01
#define    CMD_PROTOCOLSELECT         0x02
#define    CMD_SENDRECV               0x04
#define    CMD_IDLE                   0x07
#define    CMD_RDREG                  0x08
#define    CMD_WRREG                  0x09
#define    CMD_BAUDRATE               0x0A
#define    CMD_ECHO                   0x55

#define CONTROL_SEND_CMD              0x00
#define CONTROL_POLL                  0x03
#define CONTROL_READ_CMD              0x02
#define CONTROL_RESET                 0x01

#define POLL_READ_MASK                0x08
#define POLL_WRITE_MASK               0x04

#define LENGTH_3                      0x03
#define LENGTH_4                      0x04

#define PROTOCOL_FIELD_OFF            0x00
#define PROTOCOL_15693                0x01
#define PROTOCOL_14443_A              0x02
#define PROTOCOL_14443_B              0x03
#define PROTOCOL_18092                0x04

/* Offset definitions for global buffers */
#define CR95HF_COMMAND_OFFSET                       0x00
#define CR95HF_LENGTH_OFFSET                        0x01
#define CR95HF_DATA_OFFSET                          0x02

//ISO 14443-3 Commands
#define ISO14443A_CMDCODE_REQA                          0x26
#define ISO14443A_CMDCODE_WUPA                          0x52
#define ISO14443A_CMDCODE_HLTA                          0x50
#define ISO14443A_CMDCODE_RATS                          0xE0
#define ISO14443A_CMDCODE_PPS                           0xD0
/* Anticollison levels (commands) */
#define ISO14443A_CMDCODE_SELECT_LVL1                   0x93
#define ISO14443A_CMDCODE_SELECT_LVL2                   0x95
#define ISO14443A_CMDCODE_SELECT_LVL3                   0x97
/* NVB bytes values */
#define ISO14443A_NVB_10                                0x10
#define ISO14443A_NVB_20                                0x20
#define ISO14443A_NVB_30                                0x30
#define ISO14443A_NVB_40                                0x40
#define ISO14443A_NVB_50                                0x50
#define ISO14443A_NVB_60                                0x60
#define ISO14443A_NVB_70                                0x70
/* ATQ FLAG */
#define ISO14443A_ATQA_UID_SINGLESIZE                   0
#define ISO14443A_ATQA_UID_DOUBLESIZE                   1
#define ISO14443A_ATQA_UID_TRIPLESIZE                   2
/* command control byte value of CR95HF */
#define ISO14443A_MAX_NBBYTE_UID                        0x07
#define ISO14443A_CMD_MAXNBBYTE                         0x10
#define ISO14443A_ANSWER_MAXNBBYTE                      0x20

/* command control byte value of CR95HF */
#define ISO14443A_NBSIGNIFICANTBIT_7                    0x07
#define ISO14443A_NBSIGNIFICANTBIT_8                    0x08
#define ISO14443A_APPENDCRC                             0x20

/* ISO14443_A Mask */
#define ISO14443A_MASK_PROPRIETARYCODING                0x0F
#define ISO14443A_MASK_UIDSIZEBITFRAME                  0xC0
#define ISO14443A_MASK_BITFRAMEANTICOL                  0x1F
#define ISO14443A_MASK_COLLISIONBIT                     0x80
#define ISO14443A_MASK_CRCBIT                           0x20
#define ISO14443A_MASK_PARITYBIT                        0x10
#define ISO14443A_MASK_SIGNIFICANTBITS                  0x0F
#define ISO14443A_MASK_FIRSTBYTECOLLISION               0xFF
#define ISO14443A_MASK_FIRSTBITCOLLISION                0x0F
#define ISO14443A_MASK_RATS_FSDI                        0xF0
#define ISO14443A_MASK_RATS_CID                         0x0F
#define ISO14443A_MASK_PPS_CID                          0x0F
#define ISO14443A_MASK_14443_4_COMPATIBLE               0x24
#define ISO14443A_MASK_SAK_UIDNOTCOMPLETE               0x04
#define ISO14443A_MASK_UIDSIZE                          0x03

/* ISO14443_A offset */
#define ISO14443A_OFFSET_APPENDCRC                      0x00
#define ISO14443A_OFFSET_TXDATARATE                     0x06
#define ISO14443A_OFFSET_RXDATARATE                     0x04
#define ISO14443A_OFFSET_SLOTNUMBER                     0x04
#define ISO14443A_OFFSET_NVB                            0x04
#define ISO14443A_OFFSET_UIDSIZEBITFRAME                0x06
#define ISO14443A_OFFSET_RATS_FSDI                      0x04
#define ISO14443A_OFFSET_UID_SELECT                     2
#define ISO14443A_OFFSET_SAKBYTE                        CR95HF_DATA_OFFSET
#define ISO14443A_OFFSET_ATQAFIRSTBYTE                  CR95HF_DATA_OFFSET
#define ISO14443A_OFFSET_UIDSIZE                        6

/* SAK byte constant */
#define ISO14443A_SAK_14443_4_COMPATIBLE                0x20
#define ISO14443A_SAK_UIDNOTCOMPLETE                    0x04

/* UID Sizes */
#define ISO14443A_NBBYTE_UIDSINGLE                      4
#define ISO14443A_NBBYTE_UIDDOUBLE                      7
#define ISO14443A_NBBYTE_UIDTRIPLE                      10
#define ISO14443A_NBBYTE_SELECTRESPONSE                 4
#define ISO14443A_NBBYTE_SELECT                         5

/* protocol select parameters   */
#define ISO14443A_PROTOCOLSELECT_NBBYTE                 0x02
#define ISO14443A_MASK_APPENDCRC                        0x01
#define ISO14443A_MASK_TXDATARATE                       0xC0
#define ISO14443A_MASK_RXDATARATE                       0x30
#define ISO14443A_MASK_RFU                              0x0C

#define ISO14443A_TXVALUE_106K                          0x00
#define ISO14443A_TXVALUE_212K                          0x01
#define ISO14443A_TXVALUE_424K                          0x02
#define ISO14443A_TXVALUE_847K                          0x03

#define ISO14443A_RXVALUE_106K                          0x00
#define ISO14443A_RXVALUE_212K                          0x01
#define ISO14443A_RXVALUE_424K                          0x02
#define ISO14443A_RXVALUE_847K                          0x03
                                                
#define ISO14443A_MASK_SLOTNUMBER                       0xF0

/* protocol allowed */
#define PROTOCOL_TAG_FIELDOFF                       0x00
#define PROTOCOL_TAG_ISO15693                       0x01
#define PROTOCOL_TAG_ISO14443A                      0x02
#define PROTOCOL_TAG_ISO14443B                      0x03
#define PROTOCOL_TAG_FELICA                         0x04
#define PROTOCOL_CARD_ISO14443A                     0x12
#define PROTOCOL_CARD_ISO14443B                     0x13
#define PROTOCOL_CARD_FELICA                        0x14

/* CR95HF command definition */
#define IDN                                         0x01
#define PROTOCOL_SELECT                             0x02
#define POLL_FIELD                                  0x03
#define SEND_RECEIVE                                0x04
#define LISTEN                                      0x05
#define SEND                                        0x06
#define IDLE                                        0x07
#define READ_REGISTER                               0x08
#define WRITE_REGISTER                              0x09
#define BAUD_RATE                                   0x0A
#define SUB_FREQ_RES                                0x0B
#define AC_FILTER                                   0x0D
#define TEST_MODE                                   0x0E
#define SLEEP_MODE                                  0x0F
#define ECHO                                        0x55
#define ECHORESPONSE                                0x55

#define __ADDUNITS(x, y)              (x##y)

#if MBED_MAJOR_VERSION == 2
#define WAIT_MS(x)                    wait_ms(x)
#elif  MBED_MAJOR_VERSION == 5
#define WAIT_MS(x)                    Thread::wait(x)
#elif  MBED_MAJOR_VERSION == 6
#define WAIT_MS(x)                    ThisThread::sleep_for(__ADDUNITS(x,ms))
#else
#error "Unknown OS version"
#endif

class CR95 {
public:
    CR95(PinName SSI, PinName CS, PinName IRQ_IN, PinName MOSI, PinName MISO, PinName CLK);
    void init();
    void ReadCR95HF_ID();
    void Select_ISO_IEC_14443_A_Protocol();
    void Select_ISO_IEC_15693_Protocol();
    bool CheckTagPresent();
    void UpdateEXE();
    void getTagID(char * id);
    char CR95HF_ID[13];
    void readTag();
    void Check14443ATagPresent();
    void Check15693TagPresent();    
    unsigned short UID[10];
    unsigned short UIDLength;
    
private: 
    void writeCmd(unsigned short cmd, unsigned short dataLen);
    void readCmd();
    char EchoResponse();
    void ISO14443A_REQA();
    void ISO14443A_WUPA();
    void ISO14443A_HLTA();
    void ISO14443A_SelectSequence(unsigned short *SAKByte);
    void ProtocolSelect(unsigned short length, unsigned short protocol, unsigned short * parameters);
    DigitalOut _SSI;
    DigitalOut _CS;
    DigitalOut _IRQ_IN;
    SPI _spi;
    unsigned short _sdata[255];
    unsigned short _rdata[255];
    bool _tagPresent;
    unsigned short _res;
    unsigned short _dataNum;
};
    

#endif