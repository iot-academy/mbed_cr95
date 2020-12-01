#include "CR95.h"
#include "mbed.h"
//#include "helper.h"
#include "ISO15693.h"


void CR95::Check15693TagPresent()
{
    
}

void CR95::Select_ISO_IEC_15693_Protocol()
{
    unsigned short txrate = 0;
    unsigned short rxrate = 0;
    unsigned short parameters = 0;
    ProtocolSelect(0, 0, &parameters);
}