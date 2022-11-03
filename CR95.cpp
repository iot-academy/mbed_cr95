#include "CR95.h"
#include "mbed.h"
//#include "helper.h"

/*Constructor for class. This sets the pins and initial data*/
CR95::CR95(PinName SSI, PinName CS, PinName IRQ_IN, PinName MOSI, PinName MISO, PinName CLK): _SSI(SSI)
                                                                                             ,_CS(CS)
                                                                                             ,_IRQ_IN(IRQ_IN)
                                                                                             ,_spi(MOSI,MISO,CLK)
{
    _tagPresent = false;
    _res = 0;
    _dataNum = 0;
}

/*Initialises the device*/
void CR95::init()
{
    _SSI = 1;
    _IRQ_IN = 1;
    WAIT_MS(100);
    
    _IRQ_IN = 0;
    WAIT_MS(100);
    _IRQ_IN = 1;
    WAIT_MS(100);
    
    //reset
    _CS = 0;
    _spi.write(0x01);
    _CS = 1;
    
    WAIT_MS(100);
    
    _IRQ_IN = 0;
    WAIT_MS(100);
    _IRQ_IN = 1;
    WAIT_MS(100);
    
    
    //Initialise the SPI module
    _spi.format(8,3);//8 bits per transmission, mode 3
    _spi.frequency(1000000);//1MHz
    WAIT_MS(100);
    
    while(!EchoResponse())
    {
        _IRQ_IN = 1;
        WAIT_MS(1);
        _IRQ_IN = 0;
        WAIT_MS(1);
    }
}

/*Read the ID from the CR95*/
void CR95::ReadCR95HF_ID()
{
    writeCmd(CMD_IDN,0);
    readCmd();
    for(int j=0;j<_dataNum;j++)
    {
        CR95HF_ID[j] = _rdata[j];
    }
}

/*Called ever 125ms to check for tags*/
void CR95::UpdateEXE()
{
    /*Check for ISO 14443 A Tags*/
    Select_ISO_IEC_14443_A_Protocol();
    Check14443ATagPresent();
    /*Check for ISO 15693 Tags*/
    Select_ISO_IEC_15693_Protocol();
    Check15693TagPresent();
}
