#ifndef obd2_bt_h
#define obd2_bt_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class obd2_bt {
    public:
        obd2_bt(int rx_pin, int tx_pin, int baud); //constructor
        void begin(); //Initializes the pins
        void connect(unsigned char macAddr); //connect to the device

    private: 
        unsigned char macAddr;
        int baud, rx_pin, tx_pin;
}


#endif