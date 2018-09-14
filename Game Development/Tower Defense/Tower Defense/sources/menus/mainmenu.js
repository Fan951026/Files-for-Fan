MyGame.screens['main-menu'] = (function(main, globals) {
	'use strict';

	console.log("main menu called");
	
	function initialize() {
		console.log("main menu init called...");
		document.getElementById('id-new-game').addEventListener(
			'click',
			function() {main.showScreen('game-play'); });
		
		document.getElementById('id-high-scores').addEventListener(
			'click',
			function() { main.showScreen('high-scores'); });
		
		document.getElementById('id-help').addEventListener(
			'click',
			function() { main.showScreen('help'); });
		
		document.getElementById('id-about').addEventListener(
			'click',
			function() { console.log("about clicked"); main.showScreen('about'); });
	}
	
	function run() {
		//--------------------------------------------------------
		//
		//	This is an example of audio for menu
		//
		//--------------------------------------------------------
		if(!globals.playingMenuBG){
			globals.menuAudio.play();
			playingMenuBG = true;
		}
	};
	
	return {
		initialize : initialize,
		run : run
	};
}(MyGame.Main, MyGame.Globals));
