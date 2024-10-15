void sendDataOSC() {
  AsyncUDPMessage udpMsg;
  OSCMessage oscMsg("/data");
  
  // the magic happens here:
  oscMsg.add(int(millis())); // sends data
  oscMsg.add(0.001); // sends data
  oscMsg.add(100);
  
  oscMsg.send(udpMsg);
  oscMsg.empty();
  udpOut.broadcastTo(udpMsg, networkOutPort); // sends it too all devices in the network (broadcast)

}