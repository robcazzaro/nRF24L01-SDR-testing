/** @file
    ANT and ANT+ decoder.

    Copyright (C) 2022 Roberto Cazzaro <https://github.com/robcazzaro>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/
/*
* Carrier Wave to test SDR downconverters
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*
* startConstCarrier() documentation
* https://nrf24.github.io/RF24/classRF24.html#ac43ad43c34337ec0de189105bab2213b
*/

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CHANNEL 57
#define LEVEL RF24_PA_MAX // RF24_PA_MIN = -18 dBm, RF24_PA_LOW = -12 dBm, RF24_PA_HIGH = -6 dBm, RF24_PA_MAX = 0dBm
RF24 radio(PB0, PB1);   // CE, CSN
byte address[6];

void setup() {

  for (int i = 0; i < 6; i++)
  {
    address[i] = 0xFF;
  }

  pinMode(LED_BUILTIN, OUTPUT);
  radio.begin();
  radio.setChannel(CHANNEL);
  radio.startListening();
  radio.stopListening();

  if (radio.isPVariant())
  {
    radio.setAutoAck(false);
    radio.setRetries(0, 0);
    radio.flush_tx();
    radio.disableCRC();
  }
}

void loop() {
  
  digitalWrite(LED_BUILTIN, HIGH);
  radio.startConstCarrier(LEVEL, CHANNEL);
  delay(2000);

  radio.stopConstCarrier();
  radio.startListening();
  radio.stopListening();
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}
