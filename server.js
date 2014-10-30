var express = require('express'),
	app 	= express(),
	server 	= require('http').Server(app),
	io 		= require('socket.io').listen(server);

app.use(function (req, res, next){
	console.log(req.ip);
	next();
});
app.use(express.static(__dirname + '/public')); 
app.use(express.cookieParser('1234567890QWERTYoolalathisisastupidkey'));
app.use(express.session({secret: '1234567890QWERTYoolalathisisastupidkey'}));


process.nextTick(function (){
	require('./app/socketio.js')(io);
	require('./app/routes.js')(app);
});


server.listen(8888, "localhost");

