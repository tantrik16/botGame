(function (){	
	var turn = 0;
	var socket = io.connect();
	var init = [0,0,0,0,0,0,0,0,0];
	var game_over = false;
	for(var i = 0; i < 9; i++){
		var block = document.getElementById('block' + i);
		block.addEventListener('click', function (){
			var context = document.getElementById(this.id).getContext("2d");
			context.beginPath();
			context.font = "bold 90px Arial";
			var id = this.id.toString();
			
			if(turn % 2 == 0 && !game_over && init[id[5]] == 0){
				turn = turn + 1;
				context.fillText("X", 20, 80);	
				init[id[5]] = 1;			
				socket.emit('run_code', init);
			}
			context.stroke();
		});
	}
	socket.on('output', function (data){
		init[data] = 2;
		console.log(data);
		var context = document.getElementById('block' + data).getContext("2d");
		context.beginPath();
		context.font = "bold 90px Arial";
		if(turn % 2 == 1){
			turn = turn + 1;
			context.fillText("O", 20, 80);
		}
		context.stroke();
	});
	socket.on('result', function (data){
		document.getElementById('result').innerHTML = data;
		game_over = true;
	});
})();