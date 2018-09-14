MyGame.screens['high-scores'] = (function(main) {
	'use strict';
	
	function initialize() {
		document.getElementById('id-high-scores-back').addEventListener(
			'click',
			function() { main.showScreen('main-menu'); });
	}
	
	function run() {
		document.getElementById("hs1n").innerHTML = localStorage.hs1name;
		document.getElementById("hs1s").innerHTML = localStorage.hs1score;

		document.getElementById("hs2n").innerHTML = localStorage.hs2name;
		document.getElementById("hs2s").innerHTML = localStorage.hs2score;

		document.getElementById("hs3n").innerHTML = localStorage.hs3name;
		document.getElementById("hs3s").innerHTML = localStorage.hs3score;

		document.getElementById("hs4n").innerHTML = localStorage.hs4name;
		document.getElementById("hs4s").innerHTML = localStorage.hs4score;

		document.getElementById("hs5n").innerHTML = localStorage.hs5name;
		document.getElementById("hs5s").innerHTML = localStorage.hs5score;
	}
	
	return {
		initialize : initialize,
		run : run
	};
}(MyGame.Main));