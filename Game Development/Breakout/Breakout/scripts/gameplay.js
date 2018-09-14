MyGame.screens['game-play'] = (function (game, graphics, input) {
	'use strict';

	var mouseCapture = false,
		myMouse = input.Mouse(),
		myKeyboard = input.Keyboard(),
		myTexture = null,
		image_back1 = null,
		cancelNextRequest = false,
		lastTimeStamp,
		rect = [],
		life = 2,
		ballList = [],
		ballNum = false,
		Numb = 100,
		start = false,
		counttime = 3,
		time1 = 0,
		endgame = false;


	function createball() {
		return {
			speed_x: 200,
			speed_y: 200,
			radius: 10,
			x: myTexture.center.x,
			y: myTexture.center.y - 22 //678
		}
	}


	var angle = 60;
	let removed = 0;
	let countScore = 0;
	let particleslist = [];
	let j = [true, true, true, true, true, true, true, true];
	let scorelist = MyGame.persistence.prescore();
	function Slist(){
		for (var i = 0; i < scorelist.length; i++) {
		MyGame.persistence.remove(((i + 1) + ':  '));
		}
		MyGame.persistence.report();
	}
	function updateball(ball, elapsedTime) {
		let dx, dy;

		dx = ball.speed_x * elapsedTime * 0.001 * Math.cos((2 * Math.PI / 360) * angle);
		dy = ball.speed_y * elapsedTime * 0.001 * Math.sin((2 * Math.PI / 360) * angle);

		ball.x = ball.x + dx;
		ball.y = ball.y - dy;


		// ------------------------ cllision with four wall------------------// 
		if (ball.x + ball.radius >= graphics.width) {
			ball.speed_x = -ball.speed_x;

		}
		if (ball.x - ball.radius <= 0) {
			ball.speed_x = -ball.speed_x;
		}
		if (ball.y - ball.radius <= 0) {
			ball.speed_y = -ball.speed_y;
		}
		if (ball.y + ball.radius >= graphics.height) {
			
		
			ballList.splice(ballList.indexOf(ball), 1);
			
			if (ballList.length === 0 && life > 0) {
				
				
				life -= 1;
				removed = 0;
				myTexture.center.x = 500;
				myTexture.center.y = 750;
				myTexture.setWidth(180);
				ballList.push(createball());
				start = false;
				counttime = 3;
				time1 = 0;
				console.log(ballList);
			}
			else if (ballList != null && life != 0) {
				console.log('continou');
			}
			else if (life === 0 && ballList.length ===0 ) {
		
				endgame = true;
				scorelist.push(countScore);
				scorelist.sort(function (a, b) { return a < b; });
				if (scorelist.length > 5) {
					scorelist.length = 5;
				}
				for (var i = 0; i < scorelist.length; i++) {
					console.log(i + "   " + scorelist[i]);
					MyGame.persistence.add((i + 1) + ':  ', scorelist[i]);
				}
				MyGame.persistence.report();
			}


			//ball.speed_y = -ball.speed_y;
			// ball.x = 500;
			// ball.y = 678;
		}
		// --------------------------End with wall --------------------------------//
		//-------------------paddle cllision check start ----------------------------------------//
		if (ball.y + ball.radius >= myTexture.center.y - myTexture.height / 2 &&
			ball.x + ball.radius >= myTexture.center.x - myTexture.width / 2 &&
			ball.x - ball.radius <= myTexture.center.x + myTexture.width / 2 &&
			ball.y < myTexture.center.y + myTexture.height / 2) {
			ball.speed_y = -ball.speed_y;
			if (ball.x - myTexture.center.x > 0) {
				angle = 90 - (ball.x - myTexture.center.x + 10) / myTexture.width / 2 * 90;
				if (ball.speed_x > 0) {
					//ball.y = ball.y - ball.radius;
					ball.speed_x = ball.speed_x;
				}
				else if (ball.speed_x < 0) {
					//ball.y = ball.y - ball.radius;
					ball.speed_x = -ball.speed_x;
				}
			}
			else {
				angle = 90 - (myTexture.width / 2 - (ball.x - myTexture.center.x + 10)) / myTexture.width / 2 * 90;

				if (ball.speed_x > 0) {
					//ball.y = ball.y - ball.radius;
					ball.speed_x = -ball.speed_x;
				}
				else if (ball.speed_x < 0) {
					//ball.y = ball.y - ball.radiuss;
					ball.speed_x = ball.speed_x;
				}
			}
		}


		//--------------------------------- paddle cllision check end--------------------------------//

		// ---------------------Check ball collision with different angle-------------------//

		let rowcount = [0, 0, 0, 0, 0, 0, 0, 0];

		for (var i = rect.length - 1; i >= 0; i--) {
			rowcount[rect[i].row]++;

			if (ball.speed_x < 0 && ball.speed_y > 0) {

				if (ball.y - ball.radius <= rect[i].location.y + rect[i].height &&
					ball.y > rect[i].location.y && ball.x - ball.radius <= rect[i].location.x + rect[i].width &&
					ball.x > rect[i].location.x) {
					var a = Math.abs(rect[i].location.y + rect[i].height - (ball.y - ball.radius));
					var b = Math.abs(rect[i].location.x + rect[i].width - (ball.x - ball.radius));
					particleslist.push(ParticleSystem({
						position: { x: rect[i].location.x, y: rect[i].location.y },
						speed: { mean: 0.07, stdev: 0.025 },
						lifetime: { mean: 300, stdev: 20 },
						size: { mean: 5, stdev: 2 },
						fill: 'rgba(0, 0, 255, 0.5)',

					}, MyGame.graphics));
					if (a < b) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else if (a > b) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);

					}

				}
			}

			else if (ball.speed_x > 0 && ball.speed_y > 0) {
				if (ball.y - ball.radius <= rect[i].location.y + rect[i].height &&
					ball.y > rect[i].location.y && ball.x + ball.radius >= rect[i].location.x &&
					ball.x < rect[i].location.x + rect[i].width) {
					var c = Math.abs(rect[i].location.y + rect[i].height - (ball.y - ball.radius));
					var d = Math.abs(rect[i].location.x - (ball.x + ball.radius));
					particleslist.push(ParticleSystem({
						position: { x: rect[i].location.x, y: rect[i].location.y },
						speed: { mean: 0.07, stdev: 0.025 },
						lifetime: { mean: 300, stdev: 20 },
						size: { mean: 5, stdev: 2 },
						fill: 'rgba(0, 0, 255, 0.5)',

					}, MyGame.graphics));
					if (c < d) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);

					}
					else if (c > d) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}

				}
			}

			else if (ball.speed_x < 0 && ball.speed_y < 0) {

				if (ball.y + ball.radius >= rect[i].location.y && ball.y < rect[i].location.y + rect[i].height &&
					ball.x - ball.radius <= rect[i].location.x + rect[i].width && ball.x > rect[i].location.x) {
					var e = Math.abs(rect[i].location.y - (ball.y + ball.radius));
					var f = Math.abs(rect[i].location.x + rect[i].width - (ball.x - ball.radius));
					particleslist.push(ParticleSystem({
						position: { x: rect[i].location.x, y: rect[i].location.y },
						speed: { mean: 0.07, stdev: 0.025 },
						lifetime: { mean: 300, stdev: 20 },
						size: { mean: 5, stdev: 2 },
						fill: 'rgba(0, 0, 255, 0.5)',

					}, MyGame.graphics));
					if (e < f) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else if (e > f) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}

				}

			}

			else if (ball.speed_x > 0 && ball.speed_y < 0) {
				if (ball.y + ball.radius >= rect[i].location.y && ball.y < rect[i].location.y + rect[i].height &&
					ball.x + ball.radius >= rect[i].location.x && ball.x < rect[i].location.x + rect[i].width) {
					var g = Math.abs(rect[i].location.y - (ball.y + ball.radius));
					var h = Math.abs(rect[i].location.x - (ball.x + ball.radius));
					particleslist.push(ParticleSystem({
						position: { x: rect[i].location.x, y: rect[i].location.y },
						speed: { mean: 0.07, stdev: 0.025 },
						lifetime: { mean: 300, stdev: 20 },
						size: { mean: 5, stdev: 2 },
						fill: 'rgba(0, 0, 255, 0.5)',

					}, MyGame.graphics));
					if (g < h) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else if (g > h) {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}
					else {
						if (rect[i].shrink === 'good') {
							myTexture.setWidth(90);

						}
						ball.speed_y = -ball.speed_y;
						ball.speed_x = -ball.speed_x;
						removed += 1;
						countScore += rect[i].score;
						rect.splice(i, 1);
					}

				}
			}

			else {
				particleslist.push(ParticleSystem({
					position: { x: rect[i].location.x, y: rect[i].location.y },
					speed: { mean: 0.07, stdev: 0.025 },
					lifetime: { mean: 300, stdev: 20 },
					size: { mean: 5, stdev: 2 },
					fill: 'rgba(0, 0, 255, 0.5)',

				}, MyGame.graphics));
				if (rect[i].shrink === 'good') {
					myTexture.setWidth(90);

				}
				ball.speed_y = -ball.speed_y;
				removed += 1;
				countScore += rect[i].score;
				rect.splice(i, 1);

			}



		}


		for (var i = 0; i < 8; i++) {
			if (rowcount[i] === 0 && j[i] === true) {
				countScore += 25;

				j[i] = false;
			}
		}
	

		if (countScore > Numb && !ballNum) {
			ballNum = true;
			Numb += 100;
		}

		// ------------------------End ball collision with different angle----------------//
		//-----------------------------------change speed of the ball--------------------------//
		if (removed >= 4 && removed < 12) {
			if (ball.speed_y < 0) {
				ball.speed_y = -400;
			}
			if (ball.speed_y > 0) {
				ball.speed_y = 400;
			}
			if (ball.speed_x < 0) {
				ball.speed_x = -400;
			}
			if (ball.speed_x > 0) {
				ball.speed_x = 400;
			}
		}
		if (removed >= 12 && removed < 36) {
			if (ball.speed_y < 0) {
				ball.speed_y = -600;
			}
			if (ball.speed_y > 0) {
				ball.speed_y = 600;
			}
			if (ball.speed_x < 0) {
				ball.speed_x = -600;
			}
			if (ball.speed_x > 0) {
				ball.speed_x = 600;
			}
		}
		if (removed >= 36 && removed < 62) {
			if (ball.speed_y < 0) {
				ball.speed_y = -800;
			}
			if (ball.speed_y > 0) {
				ball.speed_y = 800;
			}
			if (ball.speed_x < 0) {
				ball.speed_x = -800;
			}
			if (ball.speed_x > 0) {
				ball.speed_x = 800;
			}
		}
		if (removed >= 62) {
			if (ball.speed_y < 0) {
				ball.speed_y = -1000;
			}
			if (ball.speed_y > 0) {
				ball.speed_y = 1000;
			}
			if (ball.speed_x < 0) {
				ball.speed_x = -1000;
			}
			if (ball.speed_x > 0) {
				ball.speed_x = 1000;
			}
		}
		//-------------------------ball speed change finished--------------------//
		//-------------------------count socre ----------------------------//
		//console.log(countScore)


	}


	//	let checkrowS = [];
	function createrect(rowNum, colNum) {
		let rect = [];
		let start_y = 300;
		let myscore = null;

		for (let row = 0; row < rowNum; row++) {
			let start_x = 3;
			for (let col = 0; col < colNum; col++) {
				let mycolor;
				let shink;
				if (row >= 0 && row < 2) {
					mycolor = 'Yellow';
					shink = 'bad';
					myscore = 1;
				}
				if (row >= 2 && row < 4) {
					mycolor = 'Orange';
					shink = 'bad';
					myscore = 2;
				}
				if (row >= 4 && row < 6) {
					mycolor = 'Blue';
					shink = 'bad';
					myscore = 3;
				}
				if (row >= 6 && row < 8) {
					mycolor = 'Green';
					shink = 'bad';
					myscore = 5;
				}
				if (row == 7) {
					shink = 'good';
				}



				rect.push({
					height: 20,
					width: 68,//68
					location: {
						x: start_x,
						y: start_y
					},
					row: row,
					color: mycolor,
					shrink: shink,
					score: myscore
				});
				start_x += 68 + 3;
			}
			start_y -= 20 + 3;
		}

		return rect;

	}




	let threeP = [];
	function initialize() {
		console.log('game initializing...');

		myTexture = graphics.Texture({
			image: 'images/paddle.png',
			center: { x: 500, y: 750 },
			width: 180, height: 20,
			rotation: 0,
			moveRate: 1000,			// pixels per second
			rotateRate: 3.14159	// Radians per second
		});
		// if (myTexture.center.x === 501){
		// 	myTexture.width = 90;
		// }

		for (var i = 0; i < life; i++) {
			threeP.push(graphics.Texture({
				image: 'images/paddle.png',
				center: { x: (22 + (50 * i)), y: 790 },
				width: 45, height: 12
			}));
		}

		image_back1 = graphics.Texture({
			image: 'images/back1.jpg',
			center: { x: 500, y: 400 },
			width: 1000, height: 800,
			rotation: 0,
			moveRate: 0,			// pixels per second
			rotateRate: 0	// Radians per second

		});



		ballList.push(createball());
		rect = createrect(8, 14);
		//
		// Create the keyboard input handler and register the keyboard commands
		myKeyboard.registerCommand(KeyEvent.DOM_VK_A, myTexture.moveLeft);
		myKeyboard.registerCommand(KeyEvent.DOM_VK_D, myTexture.moveRight);
		myKeyboard.registerCommand(KeyEvent.DOM_VK_W, myTexture.moveUp);
		myKeyboard.registerCommand(KeyEvent.DOM_VK_S, myTexture.moveDown);
		myKeyboard.registerCommand(KeyEvent.DOM_VK_Q, myTexture.rotateLeft);
		myKeyboard.registerCommand(KeyEvent.DOM_VK_E, myTexture.rotateRight);
		myKeyboard.registerCommand(KeyEvent.DOM_VK_ESCAPE, function () {
			//
			// Stop the game loop by canceling the request for the next animation frame
			cancelNextRequest = true;
			//
			// Then, return to the main menu
			game.showScreen('main-menu');
		});

		//
		// Create an ability to move the logo using the mouse
		myMouse = input.Mouse();
		myMouse.registerCommand('mousedown', function (e) {
			mouseCapture = true;
			myTexture.moveTo({ x: e.clientX, y: e.clientY });
		});

		myMouse.registerCommand('mouseup', function () {
			mouseCapture = false;
		});

		myMouse.registerCommand('mousemove', function (e) {
			if (mouseCapture) {
				myTexture.moveTo({ x: e.clientX, y: e.clientY });
			}
		});
	}

	function update(elapsedTime) {
		myKeyboard.update(elapsedTime);
		//myMouse.update(elapsedTime);
		if (ballNum) {
			ballNum = false;
			ballList.push(createball());
		}
		for (var i = 0; i < ballList.length; i++) {
			updateball(ballList[i], elapsedTime);
		}
		for (var i = 0; i < particleslist.length; i++) {
			particleslist[i].update(elapsedTime);
		}

		// Check for paddle hit
		//updatepaddle(myTexture);
		//if (myTexture.center.x === 500){
		//myTexture.width = 20;

		//}
	}

	function render() {
		graphics.clear();
		image_back1.draw();

		myTexture.draw();
		for (var i = 0; i < ballList.length; i++) {
			graphics.drawball(ballList[i]);
		}
		for (var i = 0; i < rect.length; i++) {
			graphics.drawrect(rect[i]);
			//	console.log(rect[110]);
		}
		for (var i = 0; i < particleslist.length; i++) {
			particleslist[i].render();
		}
		graphics.drawScore(countScore);
		for (var i = 0; i < life; i++) {
			threeP[i].draw();
		}
		if (start == false) {
			graphics.drawtimer(counttime);
		}
		else if (start == true) {
			graphics.drawtimer('');
		}
		if (endgame === true){
		graphics.drawGameOver();
		}
	}

	//------------------------------------------------------------------
	//
	// This is the Game Loop function!
	//
	//------------------------------------------------------------------

	function gameLoop(time) {
		if (start === true) {

			update(time - lastTimeStamp);


		}
		else {

			let elapsedTime = performance.now() - lastTimeStamp; time1 += (elapsedTime / 1000);

			if (time1 >= 1) {

				counttime -= 1;
				time1 -= 1;

				if (counttime <= 0) {
					start = true;
				}
			}




		}
		lastTimeStamp = time;
		render();
		if (!cancelNextRequest) {
			requestAnimationFrame(gameLoop);
		}
	}

	function resetgame(){
		myTexture = null;
		image_back1 = null;
		cancelNextRequest = false;
		lastTimeStamp;
		rect = [];
		life = 2;
		ballList = [];
		ballNum = false;
		Numb = 100;
		start = false;
		counttime = 3;
		time1 = 0;
		endgame = false;
		threeP = [];
		angle = 60;
		removed = 0;
		countScore = 0;
		particleslist = [];
		j = [true, true, true, true, true, true, true, true];
		scorelist = MyGame.persistence.prescore();
		initialize();
	}
	function run() {
		resetgame();
		lastTimeStamp = performance.now();
		// var person = prompt("Please enter your name", "");
		//
		// Start the animation loop
		cancelNextRequest = false;
		requestAnimationFrame(gameLoop);
	}

	return {
		initialize: initialize,
		run: run,
		Slist: Slist
	};
}(MyGame.game, MyGame.graphics, MyGame.input));
