MyGame.persistence = (function () {
    'use strict';
    var highScores = {},
        previousScores = localStorage.getItem('MyGame.highScores');
    if (previousScores !== null) {
        highScores = JSON.parse(previousScores);
    }

    function add(key, value) {
        highScores[key] = value;
        localStorage['MyGame.highScores'] = JSON.stringify(highScores);
    }

    function remove(key) {
        console.log(highScores);
        delete highScores[key];
        localStorage['MyGame.highScores'] = JSON.stringify(highScores);
    }

    function report() {
        var htmlNode = document.getElementById('score')
            ,key;
        
        htmlNode.innerHTML = '';
        for (key in highScores) {
            htmlNode.innerHTML += ( key + "   " +  highScores[key] + '<br/>'); 
        }
        htmlNode.scrollTop = htmlNode.scrollHeight;
    }
    function prescore(){
        let listscore = [];
        for (var key in highScores){
              listscore.push(highScores[key]);
        }
        return listscore;
    }

    return {
        add : add,
        remove : remove,
        report : report,
        prescore: prescore
    };
}())

// MyGame.persistence.add('highscore1', score);
// MyGame.persistence.add('highscore', 100000);

// MyGame.persistence.remove('highscore');
// MyGame.persistence.remove('highscore1');