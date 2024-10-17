void sendDataOSC() {
  AsyncUDPMessage udpMsg;
  OSCMessage oscMsg("/data");

  // read sensor code data here eg acceleromenter. write it into variables etc.
  int data = random(1000);

  // the magic happens here:
  oscMsg.add((int)millis());        // send timestampo form arduino 
  oscMsg.add((int)2345);            // sends data (integer)
  oscMsg.add((float)3.14);          // sends data (float)
  oscMsg.add(data);                 // send data (from variable)
  oscMsg.add((int)analogRead(15));  // sends readout fron analog pin (integer)

  oscMsg.send(udpMsg);
  oscMsg.empty();
  udpOut.broadcastTo(udpMsg, networkOutPort);  // sends it too all devices in the network (broadcast)
}