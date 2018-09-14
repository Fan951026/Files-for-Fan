MyGame.screens['about'] = (function(main) {
	'use strict';
	
	function initialize() {
		document.getElementById('id-about-back').addEventListener(
			'click',
			function() { main.showScreen('main-menu'); });
	}
	
	function run() {
		console.log("About run called.");
	}
	
	return {
		initialize : initialize,
		run : run
	};
}(MyGame.Main));