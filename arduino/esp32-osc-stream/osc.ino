void sendDataOSC() {
  AsyncUDPMessage udpMsg;
  OSCMessage oscMsg("/data");
 
  // read sensor data here

  // the magic happens here:
  oscMsg.add(int(millis())); // sends data (integer)
  oscMsg.add(0.001); // sends data (float)
  oscMsg.add(analogRead(23)); // sends readout fron analog portinteger
  
  oscMsg.send(udpMsg);
  oscMsg.empty();
  udpOut.broadcastTo(udpMsg, networkOutPort); // sends it too all devices in the network (broadcast)

}