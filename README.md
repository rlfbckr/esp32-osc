esp32-osc
---------

this demo sends numbers via osc to all hosts in the wifi network (udp port 9999) on an esp32 microcontroller

needed library for arduino IDE
- AsyncUDP
- Chrono
- OSC

change *sendDataOSC()* in osc.ino tab
```
oscMsg.add(int(millis())); // sends data
oscMsg.add(0.001); // sends data
oscMsg.add(100);
```



