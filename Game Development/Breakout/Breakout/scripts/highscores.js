MyGame.screens['high-scores'] = (function (game) {
	'use strict';

	function initialize() {
		document.getElementById('id-high-scores-back').addEventListener(
			'click',
			function () { game.showScreen('main-menu'); });
		document.getElementById('id-removed-score').addEventListener(
			'click',
			function () {MyGame.screens['game-play'].Slist();                 });
	}

	function run() {

		//
		// I know this is empty, there isn't anything to do.
	}

	return {
		initialize: initialize,
		run: run
	};
}(MyGame.game));
