# nRF24L01-SDR-testing

I recently completed the SUP-2400 modifications to have a 2.4GHz downconverter for my cheap RTL-SDR (https://www.kd0cq.com/2016/04/part-ii-the-mod-receive-up-to-4-5ghz-on-your-rtlsdr-for-5-00/). I also acquired a MMDS downconverter from China for the same purpose (http://blog.cyberexplorer.me/2014/01/sniffing-and-decoding-nrf24l01-and.html)

But I didn't know if it worked. I saw a lot of different random signals, but I had no way to know if it was just amplified noise, nor I had a way to know if the downconverter frequency was exactly 2.4GHz, or something else. I have a few cheap nRF24L01 modules around, and plenty of 3.3V Arduino boards, so after a quick read on the nRF24 library (https://github.com/nRF24/RF24), I had a super simple generator running using the carrier wave function of the nRF24.

Below is a sample of a SDR# screenshot, using a 31mm wire antenna with the nRF24 transmitting on channel 57 (2457 MHz) at max power. I found that a wire antenna very close to the nRF24 module is the best, as it doesn't pick up all the random 2.4GHz signals around. And on the RTL-SDR is much better to use manual gain, 12.5dB , no AGC (you can see my settings in the screenshot). Also, my code produces 2 seconds of the carrier wave, followed by 2 seconds of quiet, because I found it easier to find a signal and eliminate false positives that way. The code is running on an STM32F4 board, but outside of the CE/CSN pin definition, everything else works on any Arduino.

While the SUP-2400 downconverts exactly by 2.4GHz (so a 2.457GHz signal is 57MHz), most MMDS downconverters use a different center frequency (e.g. 1.998GHz), so that needs to be taken into account

Good news for me: my SUP-2400 downconverter worked, and the shift is really close to 2400MHz (can also be the either the cheap nRF24 module or the RTL-SDR off by a tiny amount) :)

![alt text](https://github.com/robcazzaro/nRF24L01-SDR-testing/raw/main/SDR_nRF24.png "SUP-2400, RTL_SDR and nRF24L01")
