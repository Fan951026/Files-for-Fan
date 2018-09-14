MyGame.screens['help'] = (function(main) {
	'use strict';
	
	function initialize() {
		document.getElementById('id-help-back').addEventListener(
			'click',
			function() { main.showScreen('main-menu'); });
	}
	
	function run() {
		// I know this is empty, there isn't anything to do.
	}
	
	return {
		initialize : initialize,
		run : run
	};
}(MyGame.Main));