#include "CR95.h"
#include "mbed.h"
//#include "helper.h"


void CR95::writeCmd(unsigned short cmd, unsigned short dataLen)
{   
    unsigned short i = 0;
    _CS = 0;
    _spi.write(0x00);
    _spi.write(cmd);
    _spi.write(dataLen);
    while(dataLen == 0){
        _CS = 1;
        break;
    }
    for(i=0;i<dataLen;i++)
    {
        _spi.write(_sdata[i]);
    }
    _CS = 1;
}

void CR95::readCmd()
{
    unsigned short i =0;
    
    while(1)
    {
        _CS = 0;
        _spi.write(CONTROL_POLL);
        _res = _spi.write(0);
        _CS = 1;
        
        if(_res & POLL_READ_MASK){
            _CS = 0;
            _spi.write(CONTROL_READ_CMD);
            _res = _spi.write(0);
            _dataNum = _spi.write(0);
            for(i = 0;i<_dataNum;i++)
            {
                _rdata[i] = _spi.write(0);
            }
            _CS = 1;
            break;
        }
        _CS = 1;
        wait_ms(10);
    }            
}

/*Sends the echo response to the CR 95*/
char CR95::EchoResponse()
{
    unsigned short temp = 0;
    _CS = 0;
    _spi.write(CONTROL_SEND_CMD);
    _spi.write(CMD_ECHO);
    _CS = 1;
    
    while(1)
    {
        //Poll for readiness
        _CS = 0;
        _spi.write(CONTROL_POLL);
        temp = _spi.write(0);
        _CS = 1;
        
        if((temp & POLL_READ_MASK))
        {
            _CS = 0;
            _spi.write(CONTROL_READ_CMD);
            temp = _spi.write(0);
            _CS = 1;
            if(temp == CMD_ECHO)
            {
                return 1;
            }
            return 0;
        }
    }
}

void CR95::ProtocolSelect(unsigned short length, unsigned short protocol, unsigned short * parameters)
{
    _sdata[0] = protocol;
    
    for (int i = 0; i< length -1  ;i++)
    {
        _sdata[1 + i ] = parameters[i];
    }
    
    writeCmd(CMD_PROTOCOLSELECT, 2);
    readCmd();
}