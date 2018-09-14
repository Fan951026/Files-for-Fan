MyGame.InputHandler = (function(globals, updateEngine){

	//--------------------------------------------------------
	//
	//	Need to add the mouse functions here
	//
	//--------------------------------------------------------

	

	function setMouseOut(){
		globals.mouseCoords.x = -1;
		globals.mouseCoords.y = -1;
	};

	function reportMousePosition(e){
		if(globals.boundingRectGot){
			globals.mouseCoords.x = (e.clientX - globals.canvasBounds.left) * (1000/globals.canvasBounds.width);
			globals.mouseCoords.y = (e.clientY - globals.canvasBounds.top) * (1000/globals.canvasBounds.height);
		}
	};

	function mouseDown(e){
		if(globals.boundingRectGot){
			globals.mouseCoords.x = (e.clientX - globals.canvasBounds.left) * (1000/globals.canvasBounds.width);
			globals.mouseCoords.y = (e.clientY - globals.canvasBounds.top) * (1000/globals.canvasBounds.height);
			updateEngine.mouseDown();
		}
	};

    function Keyboard() {
		let that = {
				keys : {},
				handlers : []
			};
		
		function keyPress(e) {
			that.keys[e.keyCode] = e.timeStamp;
		}
		
		function keyRelease(e) {
			delete that.keys[e.keyCode];
		}
		
		that.registerCommand = function(key, handler) {
			//console.log("handler reg");
			that.handlers.push({ key : key, handler : handler });
		};
		
		that.update = function(elapsedTime) {
			//console.log("keyboard update");
			let key = 0;

			for (key = 0; key < that.handlers.length; key++) {
				if (typeof that.keys[that.handlers[key].key] !== 'undefined') {
					that.handlers[key].handler(elapsedTime);
				}
			}
		};
		
		window.addEventListener('keydown', keyPress);
		window.addEventListener('keyup', keyRelease);
		
		return that;
	}

    function initialize(){
        startedMaze = false;
    };

    return{
		Keyboard: Keyboard,
		reportMousePosition: reportMousePosition,
		setMouseOut: setMouseOut,
		mouseDown: mouseDown,
        initialize: initialize
    };
})(MyGame.Globals,
	MyGame.UpdateEngine);