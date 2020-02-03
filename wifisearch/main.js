const express = require('express');
const find = require('local-devices');
const netList = require('network-list');
var ping = require('ping');
var ip = require("ip");
const wifi = require("node-wifi");
const wifiPassword = require('wifi-password');
var bodyParser = require('body-parser');
const app = express();
const PORT = process.env.PORT || 8080;
const path = require("path");

app.listen(PORT, () => console.log(`listening on ${PORT}`));
// app.listen('0.0.0.0:3000', () => console.log(`listening on ${PORT}`));
app.use(bodyParser.urlencoded({limit: '100mb', extended: true}));
// app.use(bodyParser.urlencoded({
//     extended: true
// }));

// TC8717T13-5G
// TC8717T099A13

wifi.init({
  iface: null // network interface, choose a random wifi interface if set to null
});

var ssid = "";
var pass = "";
var ipAddr = ip.address();
wifi.getCurrentConnections(function(err, currentConnections) {
  if (err) {
    console.log(err);
  }
  console.log(`Current Connection:`);
  console.log(currentConnections);
  ssid = currentConnections[0].ssid;
  // res.send(currentConnections[0].ssid)
  /*
    // you may have several connections
    [
        {
            iface: '...', // network interface used for the connection, not available on macOS
            ssid: '...',
            bssid: '...',
            mac: '...', // equals to bssid (for retrocompatibility)
            channel: <number>,
            frequency: <number>, // in MHz
            signal_level: <number>, // in dB
            quality: <number>, // same as signal level but in %
            security: '...' //
            security_flags: '...' // encryption protocols (format currently depending of the OS)
            mode: '...' // network mode like Infra (format currently depending of the OS)
        }
    ]
    */
});

wifiPassword().then(password => {
    console.log(password);
    pass = password
    //=> 'johndoesecretpassword'
});

app.get('/', function(req, res) {
    res.send({
      "ssid": ssid,
      "password": pass,
      "ip": ipAddr
    });
});

app.post('/', function(req, res) {
  // console.log("hhh");
  // wifi.connect({ ssid: ssid, password: pass }, function(err) {
  //   if (err) {
  //     console.log(err);
  //   }
  //   console.log("Connected");
  // });
  // console.log(res.body);
  var response = JSON.stringify(req.body);
  var obj = JSON.parse(response);
  var clientIP = obj.ip;

  console.log(clientIP);
  next(clientIP);
});

function next(newClientIP) {
  console.log("next");


}
// app.post('/wifisave', function(req, res) {
//   console.log(res);
//   // let s = req.body.SSID;
//   // let p = req.body.PASS;
//   // // res.send("hello test");
//   // console.log(s);
//   // console.log(p);
//   //
//
//
//   res.send("got it!")
// });

// var net = require('net');
//
// var HOST = '0.0.0.0';
// var PORT = 8080;
//
// var client = new net.Socket();
// client.connect(PORT, HOST, function() {
//     console.log('CONNECTED TO: ' + HOST + ':' + PORT);
//     client.write("testtt");
//     // while (1) {
//     //
//     // }
//
// });

// client.on('data', function(data) { // 'data' is an event handler for the client socket, what the server sent
//     console.log('DATA: ' + data);
//     client.destroy(); // Close the client socket completely
//
// });

// Add a 'close' event handler for the client socket
// client.on('close', function() {
//     console.log('Connection closed');
// });

// 1. search for availible networks that are named loomx
// 2. get current wifi and password and store in vars
// 3. when select loomx network, create a soft access point
//    and connect loomx nodes to current wifi
// 4. send credentials through ajax to nodemcu




// wifi.init({
//   iface: null
// });
//
// wifi.scan((err, networks) => {
//   if (err) {
//     console.log(err);
//   } else {
//     console.log("Other Networks:");
//     console.log(networks);
//   }
// })
