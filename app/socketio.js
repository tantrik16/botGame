var exec = require('child_process').exec;
var connections = {};
function check(status){
	for(var i = 0; i < 3; i++){
		if(status[i] == status[i + 3] && status[i + 3] == status[i + 6] && status[i]){			
			return true;
		}
	}
	for(var i = 0; i < 9; i += 3){
		if(status[i] == status[i + 1] && status[i + 1] == status[i + 2] && status[i]){
			return true;
		}
	}
	if(status[0] == status[4] && status[4] == status[8] && status[0]){		
		return true;
	}
	if(status[2] == status[4] && status[4] == status[6] && status[2]){
		return true;
	}
	return false;
}

function isFinished(status){
	for(var i = 0; i < 9; i++)
		if(status[i] == 0)
			return false;
	return true;
}
module.exports = function (io){
	io.on('connection', function (socket){
		connections[socket.id] = [0, 0, 0, 0, 0, 0, 0, 0, 0];
		socket.on('run_code', function (data){
			var cmd = 'cd codes && g++ test.cpp && ./a.out';
			if(connections[socket.id] == 'Game over Bitches'){
				socket.emit('result', 'Game over Bitches');
				return;
			}
			if(Array.isArray(data) && data.length == 9){
				for(var i = 0; i < data.length; i++)
					cmd += ' ' + data[i];
				var c = 0;	
				for(var i = 0; i < 9; i++){
					if(data[i] != connections[socket.id][i]){
						c++;
						if(connections[socket.id][i] != 0){
							socket.emit('result', 'Game over Bitches');
							return;
						}
					}
				}		
				if(c != 1){
					console.log(data);
					console.log(connections[socket.id]);
					console.log(c);
					socket.emit('Exception', 'error');
				}	
				else{
					if(check(data)){
						socket.emit("result", "You Win!");
						connections[socket.id] = 'Game over Bitches';
					}
					else if(isFinished(data)){
						socket.emit("result", "Draw!");
						connections[socket.id] = 'Game over Bitches';
					}
					else{
						exec(cmd, function (error, stdout, stderr){	
							var flag = true;	
							console.log(stdout);					
							if(data[stdout] != 0 || stdout > 8 || stdout < 0){
								socket.emit("failure", "Incorrect Move");
								flag = false;
							}
							else{
								data[stdout] = 2;
								connections[socket.id] = data;	
							}
							if(flag){
								socket.emit('output', stdout);
							}
							if(check(data)){
								socket.emit("result", "BOT Wins!");
								connections[socket.id] = 'Game over Bitches';
							}	
							else if(isFinished(data)){
								socket.emit("result", "Draw!");
								connections[socket.id] = 'Game over Bitches';
							}
								
						});
							
					}
				}
			}
			else{
				socket.emit('Exception', "Not an array :(");
			}
			
		});	
		socket.on('disconnect', function (){

		});	
	});
}