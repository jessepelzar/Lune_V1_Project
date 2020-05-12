const express = require('express');
var ip = require("ip");
const wifi = require("node-wifi");
const wifiPassword = require('wifi-password');
var bodyParser = require('body-parser');
const app = express();
const PORT = process.env.PORT || 8080;
const path = require("path");


// local server listening on port
app.listen(PORT, () => console.log(`listening on ${PORT}`));

app.use(bodyParser.urlencoded({limit: '100mb', extended: true}));

// app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

var macAddr = "";
var dataObj = {
  id: "",
  data: ""
};

let connectedClients = [];
var http = require('http');
const server = http.createServer(app);



const io = require('socket.io')(server);
io.on('connection', socket => {
  socket.emit('request', "/* … */"); // emit an event to the socket
  io.emit('broadcast', "/* … */"); // emit an event to all connected sockets
  socket.on('reply', () => { console.log(socket); }); // listen to the event
});
server.listen(80);

// const WebSocket = require('ws');
// const s = new WebSocket.Server({ server });
// server.listen(80);
// s.on('request', (request) => onConnection(request));
// s.on('open', function(ws) {
//   console.log("new client connected");
// })
//
// s.on('connection', function connection(ws) {
//   ws.on('message', function incoming(message) {
//
//     if (message.length > 0) {
//       macAddr = message;
//       console.log('received: %s', message);
//     }
//
//     if (dataObj.id != macAddr || dataObj.data != val) {
//       dataObj.id = macAddr;
//       dataObj.data = val;
//       ws.send(JSON.stringify(dataObj));
//       console.log(JSON.stringify(dataObj));
//     }
//   });
// });


// s.on('open', function(ws) {
//   console.log("new client connected");
// })
// s.on('connection', (ws, req) => {
//     console.log('Connected');
//     // add new connected client
//     connectedClients.push(ws);
//     // listen for messages from the streamer, the clients will not send anything so we don't need to filter
//     ws.on('message', message => {
//         // send the base64 encoded frame to each connected ws
//         connectedClients.forEach((ws, i) => {
//             if (ws.readyState === ws.OPEN) { // check if it is still connected
//                 // if (message.length > 0) {
//                 //   macAddr = message;
//                 //   console.log('received: %s', message);
//                 // }
//                 if (dataObj.id != macAddr || dataObj.data != val) {
//                   dataObj.id = macAddr;
//                   dataObj.data = val;
//                   ws.send(JSON.stringify(dataObj));
//                   console.log(JSON.stringify(dataObj));
//                 }
//                 // ws.send(data); // send
//             } else { // if it's not connected remove from the array of connected ws
//                 connectedClients.splice(i, 1);
//             }
//         });
//     });
// });


// const server = http.createServer(app);
// // TC8717T13-5G
// // TC8717T099A13
// const WebSocket = require('ws');
// const s = new WebSocket.Server({ server });


//
// server.listen(3000);



wifi.init({
  iface: null // network interface, choose a random wifi interface if set to null
});
var val;
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

    // res.send(7);
    res.sendFile(path.join(__dirname+'/index.html'));
});

app.get('/home', function(req, res) {
    res.sendFile(path.join(__dirname+'/index.html'));

    // res.redirect('/home')
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
  val = req.body.SENDTOSOCK;
  console.log(clientIP);

  // connectWebSocket();
});


app.post('/socket', function(req, res) {
  // var stuff = req.body.SENDTOSOCK;
  // var obj = JSON.parse(response);
  val = req.body.SENDTOSOCK;
  // console.log("new client connected");
  // s.on('open', function(ws) {
  //   console.log("new client connected");
  // })
  // connectWebSocket();
});



function connectWebSocket() {
  console.log("connectWebSocket");

  // s.on('connection', function(ws) {
  //   ws.on('message', function(message) {
  //   //send message out to all clients
  //     s.clients.forEach(c => {
  //       c.send(val);
  //       c.send("sending data!!");
  //     });
  //
  //     // console.log(message);
  //   })
  //   console.log("new client connected");
  // })
  // s.on('connection', function connection(ws) {
  //   ws.on('message', function incoming(message) {
  //     console.log('received: %s', message);
  //     ws.send(val);
  //     val = "";
  //   });

    // s.clients.forEach(c => {
    //   c.send(val);
    //   c.send("sending data!!");
    // });
    // ws.send('something');
  // });
  // s.on('close', function close() {
  //   console.log('disconnected');
  // });
  // s.on('open', function open() {
  //   console.log('connected');
  //   s.send(val);
  // });
  //
  // s.on('close', function close() {
  //   console.log('disconnected');
  // });


  // s.on('open', (ws) => {
  //   s.clients.forEach(c => {
  //     c.send(val);
  //     c.send("sending data!!");
  //   });
  // });


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
