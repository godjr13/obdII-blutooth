#include "Arduino.h"
#include "SoftwareSerial.h"
#include "obd2_bt.h"

obd2_bt:obd2_bt(){
    _rx_pin = rx_pin;
    _tx_pin = tx_pin;
    _baud = baud;
}

obd2_bt:begin(int rx_pin, int tx_pin, int baud){
    pinMode(rx_pin,INPUT);
    pinMode(tx_pin,INPUT);
    Serial.begin(baud);

    Serial.println("AT+NAME=HC-05\r\n");        //sets name to hc-05
    Serial.println("AT+ ROLE=1\r\n");           //sets role to master
    Serial.println("AT+UART=115200，1,2\r\n");  //sets baud rate
    Serial.println("AT+CMODE=0\r\n");           //bluetooth is set to connect to any address mode if it's set to 1. set the value to 0 to connect to a specific address.             
}

obd2_bt:connect(unsigned char macAddr){
    if(macAddr){
        Serial.println("AT+CMODE=0\r\n");       //bluetooth is set to connect to any address mode if it's set to 1. set the value to 0 to connect to a specific address.
        Serial.println("Attempting to connect to the mac address..");
        Serial.print("AT+BIND=");               // Start the BIND command for pairing to a device
        Serial.print(macAddr, HEX);             // Add the MAC address in hexadecimal format
        Serial.println("\r\n");

         if (Serial.available()) {             // Check if there's a response from the device
            String response = Serial.readString(); // Read the response as a string
            if (response.indexOf("OK") != -1) {    // Check if the response contains "OK"
                Serial.println("Connection successful!");
            } else {
                Serial.println("Failed to connect. Response: " + response);
            }
        } else {
            Serial.println("No response from the device.");
        }
    }
}