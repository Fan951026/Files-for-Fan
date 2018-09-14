MyGame.Globals = (function(){
    let staticBGImageSpecs = {
        ceiling: {
            x: 0, 
            y: 223,
            w: 1000,
            h: 225
        },
        stage: {
            x: 0,
            y: 448,
            w: 1000,
            h: 425
        },
        curtains: {
            x: 0,
            y: 448,
            w: 1000,
            h: 552
        },
        spotlight: {
            x: 798,
            y: 469,
            w: 59,
            h: 59
        },
        atmosphere: {
            x: 0,
            y: 223,
            w: 1000,
            h: 777,
            a: 0
        }
    };

    let dynamicBGImageSpecs = {
        sky: {
            w: 1000,
            h: 223
        },
        stars: {
            cx: -10,
            cy: 101.5,
            w: 10,
            h: 223,
            sizeMin: 5,
            sizeMax: 10,
            w_margin: 0,
            h_margin: 20,
            mean: 3,
            stddev: 1,
            sizeDev: 3,
            restInt: 500,
            speedMin: 20,
            speedMax: 20
        },
        lights: {
            cx: 1010,
            cy: 226 + 478,
            w: 10,
            h: 552,
            sizeMin: 5,
            sizeMax: 5,
            w_margin: 0,
            h_margin: 20,
            mean: 10,
            stddev: 3,
            sizeDev: 1,
            restInt: 300,
            speedMin: -10,
            speedMax: -10
        },
        floor: {
            x: 0,
            y: 873,
            w: 1000,
            h: 125,
            current: 0,
            max: 3,
            interval: 1000, //ms
            intTime: 0,
            update: function(){
                this.current = (this.current + 1) % this.max;
            }
        },
        man: {
            state: 'point',
            cx: 500,
            cy: 795,
            w: 150,
            h: 250,
            x: function(){
                return this.cx - this.w/2;
            },
            y: function(){
                return this.cy - this.h/2;
            },
            current: 0,
            max: 8,
            pMin: 5,
            pMax: 8,
            mwc: 1,
            mwMax: 3,
            pInt: 300, //ms
            pIntTime: 0,
            mwInt: 300, //ms
            mwIntTime: 0,
            pUpdate: function(){
                if(this.current >= this.pMin && this.current <= this.pMax){
                    this.current = (this.current + 1) % this.pMax;
                    if(this.current == 0) this.current = 5;
                } else {
                    this.current = 5;
                }
            },
            mwUpdate: function(dir){
                if(dir == 'right'){
                   this.mwc -= 2;
                }

                this.mwc = (this.mwc + 1) % this.mwMax;
                if(this.mwc == 0) this.mwc = 1;

                if(dir == 'right'){
                    this.mwc +=2;
                }
                this.current = this.mwc;
            }
        }
    }

    let ball = {
        cx: 500,
        cy: 485,
        w: 36,
        h: 36,
        x: function(){
            return this.cx - this.w/2;
        },
        y: function(){
            return this.cy - this.h/2;
        },
        current: 0,
        max: 2,
        interval: 100, //ms
        intTime: 0,
        update: function(){
            this.current = (this.current + 1) % this.max;
        },
        xSpeed: 0,
        ySpeed: 50
    }

    let player = {
        cx: 500,
        cy: 930,
        w: 150,
        h: 20,
        speed: 300,
        x: function(){
            return this.cx - this.w/2;
        },
        y: function(){
            return this.cy - this.h/2;
        },
        move: function(move){
            this.cx += move;
        }
    }

    let skyBGImageSpecs = {

    };

    let mouseCoords = {
        x: 0,
        y: 0
    }

    function initialize(){
        previousTime = performance.now();
        countdown = true;
        dynamicBGImageSpecs.man.cx = 500;
        player.cx = 500;
        lives = 3;
        ball.cx = 500;
        ball.cy = 485;
        ball.xSpeed = 0;
        ball.ySpeed = 100;
        countdownTime = 0;
        brokeTop = false;
        player.w = 150;
        gameover = false;
        bricksRemoved = 0;
        debug = false;
        playingMenuBG = false;
        playingGameBG = false;
        particlesMade = false;
        mouseMode = "none";
        boundingRectGot = false;
        haveWave = false;
        money = 10000;
        score = 0;
        wavelevel = 0;
        escaped = 50;
        showGrid = true;
        showGridDown = true;
        setHotKeysDown = true;
    }

    let KeyEvent = {};
    
    let bombs = {
        bombArray: [],
        aoe: [],
        explosions: []
    };

    let floatScores = [];

    let hotkeys = {
        t1: KeyEvent.DOM_VK_1,
        t2: KeyEvent.DOM_VK_2,
        t3: KeyEvent.DOM_VK_3,
        t4: KeyEvent.DOM_VK_4,
        sendwave: KeyEvent.DOM_VK_G,
        upgrade: KeyEvent.DOM_VK_U,
        sell: KeyEvent.DOM_VK_S
    }

    let sendwavebutton = {
        sent: false,
        wait: 0,
        waitInt: 600,
        frombutton: false
    };

    let canvasBounds = {};

    let flashRed = {
        show: false,
        time: 0,
        interval: 500
    };

    let that = {
        staticBGImageSpecs: staticBGImageSpecs,
        dynamicBGImageSpecs: dynamicBGImageSpecs,
        ball: ball,
        player: player,
        menuAudio: document.getElementById("menuAudio"),
        shootAudio: document.getElementById("shootAudio"),
        initialize: initialize,
        canvasBounds: canvasBounds,
        mouseCoords: mouseCoords,
        hotkeys: hotkeys,
        KeyEvent: KeyEvent,
        flashRed: flashRed,
        bombs: bombs,
        floatScores: floatScores,
        sendwavebutton: sendwavebutton
    };

    Object.defineProperty(that, 'previousTime', {
        get: function(){ return previousTime; },
        set: function(value) { previousTime = value; }
    });
    
    Object.defineProperty(that, 'countdown', {
        get: function(){ return countdown; },
        set: function(value) { countdown = value; }
    });

    Object.defineProperty(that, 'countdownNum',{
        get: function(){ return countdownNum; },
        set: function(value) { countdownNum = value; }
    });

    Object.defineProperty(that, 'countdownTime', {
        get: function(){ return countdownTime; },
        set: function(value) { countdownTime = value; }
    });

    Object.defineProperty(that, 'lives', {
        get: function(){ return lives; },
        set: function(value) { lives = value; }
    });

    Object.defineProperty(that, 'score', {
        get: function(){ return score; },
        set: function(value) { score = value; }
    });

    Object.defineProperty(that, 'brokeTop', {
        get: function(){ return brokeTop; },
        set: function(value) { brokeTop = value; }
    });

    Object.defineProperty(that, 'gameover', {
        get: function(){ return gameover; },
        set: function(value) { gameover = value; }
    });

    Object.defineProperty(that, 'bricksRemoved', {
        get: function(){ return bricksRemoved; },
        set: function(value) { bricksRemoved = value; }
    });

    Object.defineProperty(that, 'fps', {
        get: function(){ return fps; },
        set: function(value) { fps = value; }
    });

    Object.defineProperty(that, 'debug', {
        get: function(){ return debug; },
        set: function(value) { debug = value; }
    });

    Object.defineProperty(that, 'particlesMade', {
        get: function(){ return particlesMade; },
        set: function(value) { particlesMade = value; }
    });

    Object.defineProperty(that, 'mouseMode', {
        get: function(){ return mouseMode; },
        set: function(value) { mouseMode = value; }
    });

    Object.defineProperty(that, 'boundingRectGot', {
        get: function(){ return boundingRectGot; },
        set: function(value) { boundingRectGot = value; }
    });

    Object.defineProperty(that, 'haveWave', {
        get: function(){ return haveWave; },
        set: function(value) { haveWave = value; }
    });

    Object.defineProperty(that, 'money', {
        get: function(){ return money; },
        set: function(value) { money = value; }
    });

    Object.defineProperty(that, 'playingMenuBG', {
        get: function(){ return playingMenuBG; },
        set: function(value) { playingMenuBG = value; }
    });

    Object.defineProperty(that, 'wavelevel', {
        get: function(){ return wavelevel; },
        set: function(value) { wavelevel = value; }
    });

    Object.defineProperty(that, 'escaped', {
        get: function(){ return escaped; },
        set: function(value) { escaped = value; }
    });

    Object.defineProperty(that, 'showGrid', {
        get: function(){ return showGrid; },
        set: function(value) { showGrid = value; }
    });

    Object.defineProperty(that, 'showGridDown', {
        get: function(){ return showGridDown; },
        set: function(value) { showGridDown = value; }
    });

    Object.defineProperty(that, 'setHotKeysDown', {
        get: function(){ return setHotKeysDown; },
        set: function(value) { setHotKeysDown = value; }
    });

    return that;
})();