#ifndef __ISO15693_H__
#define __ISO15693_H__

#define RFU                                     0
#define ISO15693_PROTOCOL                       0x01
#define ISO15693_SELECTLENGTH                   0x02


// data rates constants fot select commands
#define ISO15693_TRANSMISSION_26                0
#define ISO15693_TRANSMISSION_53                1
#define ISO15693_TRANSMISSION_6                 2
#define ISO15693_TRANSMISSION_RFU               3
// constants fot select commands
#define ISO15693_RESPECT_312                    0
#define ISO15693_WAIT_FOR_SOF                   1
// modulation constants fot select commands
#define ISO15693_MODULATION_100                 0
#define ISO15693_MODULATION_10                  1
// sub carrier constants fot select commands
#define ISO15693_SINGLE_SUBCARRIER              0
#define ISO15693_DUAL_SUBCARRIER                1
// appendCrc constants fot select commands
#define ISO15693_APPENDCRC                      1
#define ISO15693_DONTAPPENDCRC                  0




// mask of request flag
#define ISO15693_MASK_SUBCARRIERFLAG            0x01
#define ISO15693_MASK_DATARATEFLAG              0x02
#define ISO15693_MASK_INVENTORYFLAG             0x04
#define ISO15693_MASK_PROTEXTFLAG               0x08
#define ISO15693_MASK_SELECTORAFIFLAG           0x10
#define ISO15693_MASK_ADDRORNBSLOTSFLAG         0x20
#define ISO15693_MASK_OPTIONFLAG                0x40
#define ISO15693_MASK_RFUFLAG                   0x80
// mask of response flag
#define ISO15693_MASK_ERRORFLAG                 0x01

// memmory size information
#define ISO15693_MEMSIZEMASK_BLOCKSIZE          0x1F00
#define ISO15693_MEMSIZEMASK_NBBLOCK            0x00FF
#define ISO15693_MEMSIZEOFFSET_BLOCKSIZE        0x08


// mask for information flags
#define ISO15693_MASK_DSFIDFLAG                 0x01
#define ISO15693_MASK_AFIFLAG                   0x02
#define ISO15693_MASK_MEMSIZEFLAG               0x04
#define ISO15693_MASK_ICREFFLAG                 0x08

#define ISO15693_MASK_GETSYSINFOREPLY_MEMSIZE   0x1F

// command code 
#define ISO15693_CMDCODE_INVENTORY              0x01
#define ISO15693_CMDCODE_STAYQUIET              0x02
#define ISO15693_CMDCODE_READSINGLEBLOCK        0x20
#define ISO15693_CMDCODE_WRITESINGLEBLOCK       0x21
#define ISO15693_CMDCODE_LOCKBLOCK              0x22
#define ISO15693_CMDCODE_READMULBLOCKS          0x23
#define ISO15693_CMDCODE_WRITEMULBLOCKS         0x24
#define ISO15693_CMDCODE_SELECT                 0x25
#define ISO15693_CMDCODE_RESETTOREADY           0x26
#define ISO15693_CMDCODE_WRITEAFI               0x27
#define ISO15693_CMDCODE_LOCKAFI                0x28
#define ISO15693_CMDCODE_WRITEDSFID             0x29
#define ISO15693_CMDCODE_LOCKDSFID              0x2A
#define ISO15693_CMDCODE_GETSYSINFO             0x2B
#define ISO15693_CMDCODE_GETSECURITYINFO        0x2C





// request flags 
#define ISO15693_REQFLAG_SINGLESUBCARRIER           0
#define ISO15693_REQFLAG_TWOSUBCARRIER              1
#define ISO15693_REQFLAG_LOWDATARATE                0
#define ISO15693_REQFLAG_HIGHDATARATE               1
#define ISO15693_REQFLAG_INVENTORYFLAGNOTSET        0
#define ISO15693_REQFLAG_INVENTORYFLAGSET           1
#define ISO15693_REQFLAG_NOPROTOCOLEXTENSION        0
#define ISO15693_REQFLAG_PROTOCOLEXTENSION          1
    // request flag 5 to 8 definition when inventory flag is not set
#define ISO15693_REQFLAG_NOTSELECTED                0
#define ISO15693_REQFLAG_SELECTED                   1
#define ISO15693_REQFLAG_NOTADDRESSES               0
#define ISO15693_REQFLAG_ADDRESSED                  1
#define ISO15693_REQFLAG_OPTIONFLAGNOTSET           0
#define ISO15693_REQFLAG_OPTIONFLAGSET              1
#define ISO15693_REQFLAG_RFUNOTSET                  0
#define ISO15693_REQFLAG_RFUSET                     1
    // request flag 5 to 8 definition when inventory flag is set
#define ISO15693_REQFLAG_NOTAFI                     0
#define ISO15693_REQFLAG_AFI                        1
#define ISO15693_REQFLAG_16SLOTS                    0
#define ISO15693_REQFLAG_1SLOT                      1



// mask for parameter byte (select command)
#define ISO15693_MASK_APPENDCRC                     0x01
#define ISO15693_MASK_SUBCARRIER                    0x02
#define ISO15693_MASK_MODULATION                    0x04
#define ISO15693_MASK_WAITORSOF                     0x08
#define ISO15693_MASK_DATARATE                      0x30
#define ISO15693_MASK_RFU                           0xC0
// bits offset for parameter byte (select command)
#define ISO15693_OFFSET_APPENDCRC                   0x00
#define ISO15693_OFFSET_SUBCARRIER                  0x01
#define ISO15693_OFFSET_MODULATION                  0x02
#define ISO15693_OFFSET_WAITORSOF                   0x03
#define ISO15693_OFFSET_DATARATE                    0x04
#define ISO15693_OFFSET_RFU                         0x06
                                        
// byte offset for tag responses
#define ISO15693_OFFSET_FLAGS                       0x00
#define ISO15693_OFFSET_ERRORCODE                   0x01

#define ISO15693_OFFSET_GETSYSINFOREPLY_NBBLOCK     0x00
#define ISO15693_OFFSET_GETSYSINFOREPLY_MEMSIZE     0x01



#define ISO15693_INVENTORYOFFSET_DSFID              0x01
#define ISO15693_INVENTORYOFFSET_UID                0x02
#define ISO15693_INVENTORYOFFSET_CRC16              0x05

#define ISO15693_GETSYSINFOOFFSET_INFOFLAGS         0x01
#define ISO15693_GETSYSINFOOFFSET_UID               0x02
#define ISO15693_GETSYSINFOOFFSET_DSFID             0x0A

#define ISO15693_READSINGLEOFFSET_SECURITY          0x01
#define ISO15693_GETMULSECURITIOFFSET_SECURITY      0x01


//  number of byte of parameters
#define ISO15693_NBBYTE_UID                         0x08
#define ISO15693_NBBYTE_CRC16                       0x02
#define ISO15693_NBBYTE_DSFID                       0x01
#define ISO15693_NBBYTE_AFI                         0x01
#define ISO15693_NBBYTE_BLOCKSECURITY               0x01
#define ISO15693_NBBYTE_REPLYFLAG                   0x01
#define ISO15693_NBBYTE_INFOFLAG                    0x01
#define ISO15693_NBBYTE_MEMORYSIZE                  0x02
#define ISO15693_NBBYTE_ICREF                       0x01
#define ISO15693_NBBYTE_REQUESTFLAG                 0x01

#define ISO15693_NBBIT_INVENTORYSCANCHAIN           2+8+8+64
#define ISO15693_NBBYTE_INVENTORYSCANCHAIN          11  // =(2+8+8+64) /8 +1 
#define ISO15693_NBBITS_MASKPARAMETER               64

// error code
#define ISO15693_ERRORCODE_REQUESTFLAG              0xF1
#define ISO15693_ERRORCODE_PARAMETERLENGTH          0xF2
#define ISO15693_ERRORCODE_CRCRESIDUE               0xF3



// command length
#define ISO15693_MAXLENGTH_INVENTORY                13      // 8 + 8 + 8 + 64 + 16 = 104bits => 13 bytes
#define ISO15693_MAXLENGTH_STAYQUIET                12      // 8 + 8     + 64 + 16 = 96 => 12 bytes
#define ISO15693_MAXLENGTH_READSINGLEBLOCK          13      // 8 + 8 + 8 + 64 + 16 = 104bits => 13 bytes
#define ISO15693_MAXLENGTH_LOCKSINGLEBLOCK          13      // 8 + 8 + 8 + 64 + 16 = 104bits => 13 bytes
#define ISO15693_MAXLENGTH_READMULBLOCK             14      // 8 + 8 + 8 + 64 + 8 + 16 = 112 bits => 14 bytes
#define ISO15693_MAXLENGTH_SELECT                   12      // 8 + 8     + 64 + 16 = 96 bits => 12 bytes
#define ISO15693_MAXLENGTH_RESETTOREADY             12      // 8 + 8     + 64 + 16 = 96 bits => 12 bytes
#define ISO15693_MAXLENGTH_WRTITEAFI                13      // 8 + 8 + 8 + 64 + 16 = 104bits => 13 bytes
#define ISO15693_MAXLENGTH_WRTITEDSFID              13      // 8 + 8 + 8 + 64 + 16 = 104bits => 13 bytes
#define ISO15693_MAXLENGTH_LOCKAFI                  12      // 8 + 8     + 64 + 16 = 96 bits => 12 bytes
#define ISO15693_MAXLENGTH_LOCKDSFID                12      // 8 + 8     + 64 + 16 = 96 bits => 12 bytes
#define ISO15693_MAXLENGTH_GETMULSECURITY           14      // 8 + 8 + 8 + 64 + 8 + 16 = 112 bits => 14 bytes
#define ISO15693_MAXLENGTH_GETSYSTEMINFO            12      // 8 + 8     + 64 + 16 = 96 => 12 bytes
// reply length
#define ISO15693_MAXLENGTH_REPLYINVENTORY           12      // 8 + 8 + 64 + 16  = 96 => 12 bytes
#define ISO15693_MAXLENGTH_REPLYSTAYQUIET           2       // No reply
#define ISO15693_MAXLENGTH_REPLYREADSINGLEBLOCK     MAX_BUFFER_SIZE     // 8 + 8 + 8 + 64 + 16 = 104bits => 13 bytes
#define ISO15693_MAXLENGTH_REPLYWRITESINGLEBLOCK    4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYLOCKSINGLEBLOCK     4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYREADMULBLOCK        MAX_BUFFER_SIZE     
#define ISO15693_MAXLENGTH_REPLYSELECT              4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYRESETTOREADY        4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYWRTITEAFI           4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYWRTITEDSFID         4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYLOCKAFI             4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYLOCKDSFID           4       // 8 + 8 + 16 = 32 bits => 4 bytes
#define ISO15693_MAXLENGTH_REPLYGETMULSECURITY      MAX_BUFFER_SIZE
#define ISO15693_MAXLENGTH_REPLYGETSYSTEMINFO       15      // 8 + 8 + 64 + 8 + 8 + 8 + 16 = 112 bits => 15 bytes


#define ISO15693_MAXLENGTH_BLOCKSIZE                0x32

typedef struct {
    int8_t      DataRate        ,   // 0 => 26k     1 => 52 k   2 => 6k 3=>RFU
                WaitOrSOF       ,   // 0 => respect 312 µs  1=> wait for SOF
                ModulationDepth ,   // 0 => 100% modulation 1=> 10% modulation
                SubCarrier      ,   // 0 => single  1=> Dual
                AppendCRC       ;   // 1=> append   0=> don't append            
}ISO15693ConfigStruct;

// CRC 16 constants
#define ISO15693_PRELOADCRC16                       0xFFFF 
#define ISO15693_POLYCRC16                          0x8408 
#define ISO15693_MASKCRC16                          0x0001
#define ISO15693_RESIDUECRC16                       0xF0B8


#endif