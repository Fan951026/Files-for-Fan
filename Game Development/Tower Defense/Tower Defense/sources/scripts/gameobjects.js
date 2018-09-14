/* global MyGame */

MyGame.objects = (function(graphics) {
	
	//------------------------------------------------------------------
	//
	// Defines a game object/model that animates simply due to the passage
	// of time.
	//
	//------------------------------------------------------------------
	function AnimatedModel(spec) {
		var that = {},
			sprite = graphics.SpriteSheet(spec);	// We contain a SpriteSheet, not inherited from, big difference
			
		that.update = function(elapsedTime) {
			sprite.update(elapsedTime);
		};

		that.returnSpec = function(){
			return spec;
		};
		
		that.render = function() {
			sprite.draw();
			

		};
		
		that.rotateRight = function(elapsedTime) {
			spec.rotation += spec.rotateRate * (elapsedTime);
		};
		
		that.rotateLeft = function(elapsedTime) {
			spec.rotation -= spec.rotateRate * (elapsedTime);
		};
		
		//------------------------------------------------------------------
		//
		// Move in the direction the sprite is facing
		//
		//------------------------------------------------------------------
		that.moveForward = function(elapsedTime) {
			//
			// Create a normalized direction vector
			var vectorX = Math.cos(spec.rotation + spec.orientation),
				vectorY = Math.sin(spec.rotation + spec.orientation);
			//
			// With the normalized direction vector, move the center of the sprite
			spec.center.x += (vectorX * spec.moveRate * elapsedTime);
			spec.center.y += (vectorY * spec.moveRate * elapsedTime);
		};
		
		//------------------------------------------------------------------
		//
		// Move in the negative direction the sprite is facing
		//
		//------------------------------------------------------------------
		that.moveBackward = function(elapsedTime) {
			//
			// Create a normalized direction vector
			var vectorX = Math.cos(spec.rotation + spec.orientation),
				vectorY = Math.sin(spec.rotation + spec.orientation);
			//
			// With the normalized direction vector, move the center of the sprite
			spec.center.x -= (vectorX * spec.moveRate * elapsedTime);
			spec.center.y -= (vectorY * spec.moveRate * elapsedTime);
		};
		
		return that;
	}
	
	//------------------------------------------------------------------
	//
	// Defines a game object/model that animates based upon the elapsed time
	// that occurs only when moving.
	//
	//------------------------------------------------------------------
	function AnimatedMoveModel(spec) {
		var that = AnimatedModel(spec),	// Inherit from AnimatedModel
			base = {
				moveForward : that.moveForward,
				moveBackward : that.moveBackward,
				rotateRight : that.rotateRight,
				rotateLeft : that.rotateLeft,
				update : that.update,
				health:20,
				healthMax:20
			},
			didMoveForward = false,
			didMoveBackward = false;
			
		//------------------------------------------------------------------
		//
		// Replacing the update function from the base object.  In this update
		// we check to see if any movement was performed, if so, then the animation
		// is updated.
		//
		//------------------------------------------------------------------

		// that.movement = 10;
		that.update = function(elapsedTime) {
			// that.movement -= elapsedTime;

			// if (that.movement <= 0){
			// didMoveForward = true;
			// that.movement = 1;

			// }
			if (didMoveForward === true) {
				base.update(elapsedTime, true);
			} else if (didMoveBackward === true) {
				base.update(elapsedTime, false);
			}
			
			didMoveForward = false;
			didMoveBackward = false;
		};
		
		that.moveForward = function(elapsedTime) {
			base.moveForward(elapsedTime);
			didMoveForward = true;
		};
		
		that.moveBackward = function(elapsedTime) {
			base.moveBackward(elapsedTime);
			didMoveBackward = true;
		};
		
		that.rotateRight = function(elapsedTime) {
			base.rotateRight(elapsedTime);
			didMoveForward = true;
		};
		
		that.rotateLeft = function(elapsedTime) {
			base.rotateLeft(elapsedTime);
			didMoveForward = true;
		};
		
		return that;
	}
	
	return {
		AnimatedModel : AnimatedModel,
		AnimatedMoveModel : AnimatedMoveModel
	};

}(MyGame.GraphicsEngine));