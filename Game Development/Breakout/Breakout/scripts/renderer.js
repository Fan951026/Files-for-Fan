// ------------------------------------------------------------------
//
//
// ------------------------------------------------------------------

MyGame.graphics = (function() {
	'use strict';
	
	var canvas = document.getElementById('canvas-main'),
		context = canvas.getContext('2d');
	//canvas.width = document.body.clientWidth;
	//canvas.height = document.body.clientHeight;
	//
	// Place a 'clear' function on the Canvas prototype, this makes it a part
	// of the canvas, rather than making a function that calls and does it.
	CanvasRenderingContext2D.prototype.clear = function() {
		this.save();
		this.setTransform(1, 0, 0, 1, 0, 0);
		this.clearRect(0, 0, canvas.width, canvas.height);
		this.restore();
	};
	
	//------------------------------------------------------------------
	//
	// Public method that allows the client code to clear the canvas.
	//
	//------------------------------------------------------------------
	function clear() {
		context.clear();
	}
	function drawball(ball){
		context.beginPath();
		context.arc(ball.x,ball.y,ball.radius,0,2*Math.PI);
		context.fillStyle = 'white';
		context.strokeStyle = 'black';
		context.stroke();
		context.fill();
		context.closePath();
		
	}
	function drawrect(box){
		context.beginPath();
		
		context.rect(box.location.x,box.location.y,box.width,box.height);
		context.fillStyle = box.color;
		context.stroke();
		context.fill();
		context.closePath();
	}
	function drawScore(countScore){
		context.beginPath();
		context.fillStyle = 'rgb(66, 167, 244)';
		context.font = '20px Georgia';
		
		context.fillText('Score: ' + countScore,900,790);
	
		context.closePath();
	}
	function drawtimer(counttime){
		context.beginPath();
		context.fillStyle = 'rgb(167, 229, 9)';
	
	
		context.font = '100px Georgia';
		context.fillText(counttime,500,600);
		context.closePath();
	}
	function drawGameOver(){
		context.beginPath();
		context.fillStyle = 'black';
		context.font = '150px Georgia';
		context.fillText('Game Over!',100,500);
		context.closePath();
	}


	//------------------------------------------------------------------
	//
	// This is used to create a texture object that can be used by client
	// code for rendering.
	//
	//------------------------------------------------------------------

	function Texture(spec) {
		var that = {},
			ready = false,
			image = new Image();
			
		//
		// Load the image, set the ready flag once it is loaded so that
		// rendering can begin.
		image.onload = function() { 
			ready = true;
		};
		image.src = spec.image;
		
		that.updateRotation = function(angle) {
			spec.rotation += angle;
		};
		
		that.rotateRight = function(elapsedTime) {
			spec.rotation += spec.rotateRate * (elapsedTime / 1000);
		};
		
		that.rotateLeft = function(elapsedTime) {
			spec.rotation -= spec.rotateRate * (elapsedTime / 1000);
		};
		
		that.moveLeft = function(elapsedTime) {
			if (spec.center.x - spec.width/2 <= 0){
				spec.center.x = spec.center.x;
			}
			else {
			spec.center.x -= spec.moveRate * (elapsedTime / 1000);
			}
		};
		
		that.moveRight = function(elapsedTime) {
			if (spec.center.x + spec.width/2 >= canvas.width){
				spec.center.x = spec.center.x;
			}
			else {
			spec.center.x += spec.moveRate * (elapsedTime / 1000);
			}
		};
		
		that.moveUp = function(elapsedTime) {
			if (spec.center.y - spec.height <= canvas.height/2){
				spec.center.y = spec.center.y;
			}
			else{
			spec.center.y -= spec.moveRate * (elapsedTime / 1000);
			}
		};
		
		that.moveDown = function(elapsedTime) {
			if (spec.center.y + spec.height >= canvas.height){
				spec.center.y = spec.center.y;
			}
			else {
			spec.center.y += spec.moveRate * (elapsedTime / 1000);
			}
		};
		
		that.moveTo = function(center) {
			spec.center = center;
		};

		that.setWidth= function(width) {
			spec.width = width;
			that.width = width;
		};
		
		that.draw = function() {
			if (ready) {
				context.save();
				
				context.translate(spec.center.x, spec.center.y);
				context.rotate(spec.rotation);
				context.translate(-spec.center.x, -spec.center.y);
			
				context.drawImage(
					image, 
					spec.center.x - spec.width/2,
					spec.center.y - spec.height/2,
					spec.width, spec.height);
				
				context.restore();
			}
		};

		that.center = spec.center;
		that.height = spec.height;
		that.width = spec.width;
		
		return that;
	}
	

	return {
		clear : clear,
		Texture : Texture,
		width: canvas.width,
		height:canvas.height,
		drawball: drawball,
		drawrect: drawrect,
		drawScore:drawScore,
		drawtimer:drawtimer,
		drawGameOver: drawGameOver
	};
}());
