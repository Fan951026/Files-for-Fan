//------------------------------------------------------------
//
//  HERE IS WHERE GAMELOOP IS
//
//------------------------------------------------------------

MyGame.screens['game-play'] = (function (globals, main, updateEngine,
    renderEngine, inputHandler, animationEngine, objects, bricksEngine, particleEngine) {
    'use strict';

    var mouseCapture = true,
        myKeyboard = inputHandler.Keyboard(),
        cancelNextRequest = false,
        lastTimeStamp;

    //------------------------------------------------------------------------
    //--------------------------------------------------------------------
    var lastTimeStamp = performance.now(),
        //myKeyboard = input.Keyboard(),

        creep1 = objects.AnimatedModel({
            spriteSheet: 'images/creep1-blue.png',
            spriteCount: 6,
            spriteTime: [1000, 200, 100, 1000, 100, 200],	// milliseconds per sprite animation frame
            center: { x: 23, y: 23 },
            rotation: 0,
            orientation: 0,				// Sprite orientation with respect to "forward"
            moveRate: 200 / 1000,			// pixels per millisecond
            rotateRate: 3.14159 / 1000,	// Radians per millisecond
            health: 20,
            healthMax: 20
        }),
        creep2 = objects.AnimatedModel({
            spriteSheet: 'images/creep2-red.png',
            spriteCount: 4,
            spriteTime: [200, 1000, 200, 600],	// milliseconds per sprite animation frame
            center: { x: 23, y: 50 + 23 },
            rotation: 0,
            orientation: 0,				// Sprite orientation with respect to "forward"
            moveRate: 200 / 1000,			// pixels per millisecond
            rotateRate: 3.14159 / 1000		// Radians per millisecond
        }),
        creep3 = objects.AnimatedModel({
            spriteSheet: 'images/creep3-green.png',
            spriteCount: 4,
            spriteTime: [1000, 200, 200, 200],	// milliseconds per sprite animation frame
            center: { x: 23, y: 100 + 23 },
            rotation: 0,
            orientation: 0,				// Sprite orientation with respect to "forward"
            moveRate: 200 / 1000,			// pixels per millisecond
            rotateRate: 3.14159 / 1000		// Radians per millisecond
        }),
        spider = objects.AnimatedMoveModel({
            spriteSheet: 'images/spider.png',
            spriteCount: 10,
            spriteTime: [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],	// milliseconds per sprite animation frame
            center: { x: 32, y: 150 + 32 },
            rotation: 0,
            orientation: 1.570795 * 3,		// Sprite orientation with respect to "forward"
            moveRate: 50 / 1000,			// pixels per millisecond
            rotateRate: 3.141590 / 2 / 1000	// Radians per millisecond
        });

    var monsters = [];

    function newWave() {
        globals.wavelevel += 1;
        globals.score += 500;
        if(globals.wavelevel > 6){
            wavelevel = 1;
        }

        if (globals.wavelevel == 1) {
            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/creep1-blue.png',
                    spriteCount: 6,
                    spriteTime: [1000, 200, 100, 1000, 100, 200],	// milliseconds per sprite animation frame
                    center: { x: -200 * i, y: 475 },
                    rotation: 0,
                    orientation: 0,				// Sprite orientation with respect to "forward"
                    moveRate: 50 / 1000,			// pixels per millisecond
                    rotateRate: 3.14159 / 1000,		// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    LtoR: 1,
                    type: 'ground'

                }));
            }

        }



        if (globals.wavelevel == 3) {
            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/creep1-blue.png',
                    spriteCount: 6,
                    spriteTime: [1000, 200, 100, 1000, 100, 200],	// milliseconds per sprite animation frame
                    center: { x: 475, y: -200 * i },
                    rotation: 1.570795 * 1,
                    orientation: 0,				// Sprite orientation with respect to "forward"
                    moveRate: 50 / 1000,			// pixels per millisecond
                    rotateRate: 3.14159 / 1000,		// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    LtoR: 0,
                    type: 'ground'
                }));
            }

            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/spider.png',
                    spriteCount: 10,
                    spriteTime: [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],	// milliseconds per sprite animation frame
                    center: { x: -200 * i, y: 475 },
                    rotation: 0,
                    orientation: 0,		// Sprite orientation with respect to "forward"
                    moveRate: 50 / 1000,			// pixels per millisecond
                    rotateRate: 3.141590 / 2 / 1000,	// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    LtoR: 1,
                    type: 'ground'
                }));
            }
        }



        if (globals.wavelevel == 5) {
            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/creep1-blue.png',
                    spriteCount: 6,
                    spriteTime: [1000, 200, 100, 1000, 100, 200],	// milliseconds per sprite animation frame
                    center: { x: 475, y: -200 * i },
                    rotation: 1.570795 * 1,
                    orientation: 0,				// Sprite orientation with respect to "forward"
                    moveRate: 100 / 1000,			// pixels per millisecond
                    rotateRate: 3.14159 / 1000,		// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    LtoR: 0,
                    type: 'ground'
                }));
            }

            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/spider.png',
                    spriteCount: 10,
                    spriteTime: [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],	// milliseconds per sprite animation frame
                    center: { x: -200 * i, y: 475 },
                    rotation: 0,
                    orientation: 0,		// Sprite orientation with respect to "forward"
                    moveRate: 100 / 1000,			// pixels per millisecond
                    rotateRate: 3.141590 / 2 / 1000,	// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    LtoR: 1,
                    type: 'ground'
                }));
            }


            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/creep2-red.png',
                    spriteCount: 4,
                    spriteTime: [200, 1000, 200, 600],	// milliseconds per sprite animation frame
                    center: { x: -200 * i + 50, y: 475 },
                    rotation: 0,
                    orientation: 0,				// Sprite orientation with respect to "forward"
                    moveRate: 100 / 1000,			// pixels per millisecond
                    rotateRate: 3.14159 / 1000,		// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    type: 'air'

                }));
            }

            for (let i = 0; i < 50; i++) {
                monsters.push(objects.AnimatedMoveModel({
                    spriteSheet: 'images/creep2-red.png',
                    spriteCount: 4,
                    spriteTime: [200, 1000, 200, 600],	// milliseconds per sprite animation frame
                    center: { x: 475, y: -200 * i + 50 },
                    rotation: 1.570795 * 1,
                    orientation: 0,				// Sprite orientation with respect to "forward"
                    moveRate: 100 / 1000,			// pixels per millisecond
                    rotateRate: 3.14159 / 1000,		// Radians per millisecond
                    health: 20,
                    healthMax: 20,
                    type: 'air'

                }));
            }

        }
    }

    //--------------------------------------------------
    //--------------------------------------------------

    function setButtons(towerName) {
        globals.mouseMode = towerName;
        updateEngine.showMouseTowerInfo(towerName);
    };

    function setHotKeys(){
        for(var i = 0; i < 3; i++){
            var word = "";
            switch(i){
                case 0:
                    word = "upgrade";
                break;
                case 1:
                    word = "sell";
                break;
                case 2:
                    word = "send wave";
                break;
            }
            var letter = prompt("enter a single, lowercase char for " + word);

            if(i == 0){
                console.log("setting upgrade");
                switch(letter){
                    case 'a':
                    console.log("set Upgrade");
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_A;
                    break;

                    case 'b':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_B;
                    break;
            
                    case 'c':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_C;
                    break;
            
                    case 'd':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_D;
                    break;
            
                    case 'e':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_E;
                    break;
            
                    case 'f':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_F;
                    break;
            
                    case 'g':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_G;
                    break;
            
                    case 'h':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_H;
                    break;
            
                    case 'i':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_I;
                    break;
            
                    case 'j':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_J;
                    break;
            
                    case 'k':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_K;
                    break;
            
                    case 'l':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_L;
                    break;
            
                    case 'm':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_M;
                    break;
            
                    case 'n':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_N;
                    break;
            
                    case 'o':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_O;
                    break;
            
                    case 'p':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_P;
                    break;
            
                    case 'q':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_Q;
                    break;
            
                    case 'r':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_R;
                    break;
            
                    case 's':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_S;
                    break;
            
                    case 't':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_T;
                    break;
            
                    case 'u':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_U;
                    break;
            
                    case 'v':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_V;
                    break;
            
                    case 'w':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_W;
                    break;
            
                    case 'x':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_X;
                    break;
            
                    case 'y':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_Y;
                    break;
            
                    case 'z':
                    globals.hotkeys.upgrade = KeyEvent.DOM_VK_Z;
                    break;
                }
            }
            if(i == 1){
                switch(letter){
                    case 'a':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_A;
                    break;

                    case 'b':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_B;
                    break;
            
                    case 'c':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_C;
                    break;
            
                    case 'd':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_D;
                    break;
            
                    case 'e':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_E;
                    break;
            
                    case 'f':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_F;
                    break;
            
                    case 'g':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_G;
                    break;
            
                    case 'h':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_H;
                    break;
            
                    case 'i':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_I;
                    break;
            
                    case 'j':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_J;
                    break;
            
                    case 'k':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_K;
                    break;
            
                    case 'l':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_L;
                    break;
            
                    case 'm':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_M;
                    break;
            
                    case 'n':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_N;
                    break;
            
                    case 'o':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_O;
                    break;
            
                    case 'p':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_P;
                    break;
            
                    case 'q':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_Q;
                    break;
            
                    case 'r':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_R;
                    break;
            
                    case 's':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_S;
                    break;
            
                    case 't':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_T;
                    break;
            
                    case 'u':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_U;
                    break;
            
                    case 'v':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_V;
                    break;
            
                    case 'w':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_W;
                    break;
            
                    case 'x':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_X;
                    break;
            
                    case 'y':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_Y;
                    break;
            
                    case 'z':
                    globals.hotkeys.sell = KeyEvent.DOM_VK_Z;
                    break;
                }
            }
            if(i == 2){
                switch(letter){
                    case 'a':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_A;
                    break;

                    case 'b':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_B;
                    break;
            
                    case 'c':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_C;
                    break;
            
                    case 'd':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_D;
                    break;
            
                    case 'e':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_E;
                    break;
            
                    case 'f':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_F;
                    break;
            
                    case 'g':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_G;
                    break;
            
                    case 'h':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_H;
                    break;
            
                    case 'i':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_I;
                    break;
            
                    case 'j':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_J;
                    break;
            
                    case 'k':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_K;
                    break;
            
                    case 'l':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_L;
                    break;
            
                    case 'm':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_M;
                    break;
            
                    case 'n':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_N;
                    break;
            
                    case 'o':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_O;
                    break;
            
                    case 'p':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_P;
                    break;
            
                    case 'q':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_Q;
                    break;
            
                    case 'r':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_R;
                    break;
            
                    case 's':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_S;
                    break;
            
                    case 't':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_T;
                    break;
            
                    case 'u':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_U;
                    break;
            
                    case 'v':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_V;
                    break;
            
                    case 'w':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_W;
                    break;
            
                    case 'x':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_X;
                    break;
            
                    case 'y':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_Y;
                    break;
            
                    case 'z':
                    globals.hotkeys.sendwave = KeyEvent.DOM_VK_Z;
                    break;
                }
            }
        }

    myKeyboard.registerCommand(globals.hotkeys.sendwave, function(){
        globals.haveWave = true;
        globals.sendwavebutton.frombutton = true;
        if(!globals.sendwavebutton.sent) newWave();
        globals.sendwavebutton.sent = true;
    });
    myKeyboard.registerCommand(globals.hotkeys.upgrade, function () { globals.mouseMode = 'upgrade'; });
    myKeyboard.registerCommand(globals.hotkeys.sell, function () { globals.mouseMode = 'sell'; });

    };

    function initialize() {
        console.log('game initializing...');

        //------------------------------------------
        //
        //  Menu Buttons
        //
        //------------------------------------------

        document.getElementById('id-game-back').addEventListener(
            'click',
            function () {
                cancelNextRequest = true;
                main.showScreen('main-menu');
            });

        document.getElementById('id-tower-one').addEventListener(
            'click',
            function () { setButtons('tower1'); });

        document.getElementById('id-tower-two').addEventListener(
            'click',
            function () { setButtons('tower2'); });

        document.getElementById('id-tower-three').addEventListener(
            'click',
            function () { setButtons('tower3'); });

        document.getElementById('id-tower-four').addEventListener(
            'click',
            function () { setButtons('tower4'); });

        document.getElementById('id-upgrade').addEventListener(
            'click',
            function () { globals.mouseMode = 'upgrade' });

        document.getElementById('id-sell-tower').addEventListener(
            'click',
            function () { globals.mouseMode = 'sell' });

        document.getElementById('id-toggle-grid').addEventListener(
            'click',
            function () {
                if(globals.showGridDown){
                    globals.showGrid = !globals.showGrid; 
                    globals.showGridDown = false;
                } else {
                    globals.showGridDown = true;
                }
            });

        document.getElementById('id-set-hotkeys').addEventListener(
            'click',
            function () {
                if(globals.setHotKeysDown){
                    setHotKeys(); 
                    globals.setHotKeysDown = false;
                } else {
                    globals.setHotKeysDown = true;
                }
            });

        document.getElementById('id-send-wave').addEventListener(
            'click',
            function () {
                globals.haveWave = true;
                newWave();
            });

        //------------------------------------------
        //
        //  Initialize other modules here
        //
        //------------------------------------------

        globals.initialize();
        bricksEngine.initialize();
        renderEngine.initialize();
        updateEngine.initialize();

        //--------------------------------------------------------
        //
        //  Add keyboard commands to call updateEngine functions
        //
        //--------------------------------------------------------

        myKeyboard.registerCommand(globals.hotkeys.t1, function () { setButtons('tower1'); });
        myKeyboard.registerCommand(globals.hotkeys.t2, function () { setButtons('tower2'); });
        myKeyboard.registerCommand(globals.hotkeys.t3, function () { setButtons('tower3'); });
        myKeyboard.registerCommand(globals.hotkeys.t4, function () { setButtons('tower4'); });
        myKeyboard.registerCommand(globals.hotkeys.sendwave, function(){
                globals.haveWave = true;
                globals.sendwavebutton.frombutton = true;
                if(!globals.sendwavebutton.sent) newWave();
                globals.sendwavebutton.sent = true;
        });
        myKeyboard.registerCommand(globals.hotkeys.upgrade, function () { globals.mouseMode = 'upgrade'; });
        myKeyboard.registerCommand(globals.hotkeys.sell, function () { globals.mouseMode = 'sell'; });
        myKeyboard.registerCommand(globals.KeyEvent.DOM_VK_ESCAPE, function () {
            //cancelNextRequest = true;
            //globals.gameAudio.pause();
            globals.mouseMode = 'none';
        });

        //ADD MOUSE COMMANDS

    }

    //--------------------------------------------------------
    //
    //  Update functions - 
    //  Don't forget to update the keyboard and mouse!
    //
    //--------------------------------------------------------
    // let Top = [];
    // let Down = [];
    // let Right = [];
    // let Left = [];
    // let current = [];
    function updatePathTtD(monsters) {
        'use-strict';
        var grid = bricksEngine.grid.bricks;
        let mx = [];
        let my = [];


        for (var r = 0; r < 20; r++) {
            for (var c = 0; c < 20; c++) {
                if (grid[r][c].distTtB == -1) {
                    grid[r][c].distTtB = 100;
                }
                for (var i = 0; i < monsters.length; i++) {

                    var monsterX = monsters[i].returnSpec().center.x;
                    var monsterY = monsters[i].returnSpec().center.y;
                    var LtoR = monsters[i].returnSpec().LtoR;
                    if (monsterX < grid[r][c].cx + 25 && monsterX > grid[r][c].cx - 25 &&
                        monsterY < grid[r][c].cy + 25 && monsterY > grid[r][c].cy - 25 &&
                        LtoR == 0) {
                        mx[i] = c;
                        my[i] = r;


                        let mValue = grid[mx[i]][my[i]].distTtB;
                        if (monsterX < 950 && monsterY < 950) {

                            if (grid[mx[i] + 1][my[i]].distTtB < mValue) {
                                monsters[i].returnSpec().rotation = 0;
                            }
                            else if (grid[mx[i] - 1][my[i]].distTtB < mValue) {
                                monsters[i].returnSpec().rotation = 1.570795 * 2;
                            }
                            else if (grid[mx[i]][my[i] + 1].distTtB < mValue) {
                                monsters[i].returnSpec().rotation = 1.570795 * 1;
                            }

                            else {
                                monsters[i].returnSpec().rotation = 1.570795 * 1;

                            }

                        } else {
                            monsters[i].returnSpec().rotation = 1.570795 * 1;
                            globals.escaped -= 1;
                        }
                    }
                }
            }
        }
    };

    function updatePathLtR(monsters) {
        'use-strict';
        var grid = bricksEngine.grid.bricks;
        let mx = [];
        let my = [];


        for (var r = 0; r < 20; r++) {
            for (var c = 0; c < 20; c++) {
                if (grid[r][c].distLtR == -1) {
                    grid[r][c].distLtR = 100;
                }
                for (var i = 0; i < monsters.length; i++) {
                    var monsterX = monsters[i].returnSpec().center.x;
                    var monsterY = monsters[i].returnSpec().center.y;
                    var LtoR = monsters[i].returnSpec().LtoR;
                    if (monsterX < grid[r][c].cx + 25 && monsterX > grid[r][c].cx - 25 &&
                        monsterY < grid[r][c].cy + 25 && monsterY > grid[r][c].cy - 25 && LtoR == 1) {
                        mx[i] = c;
                        my[i] = r;


                        let mValue = grid[mx[i]][my[i]].distLtR;
                        if (monsterX < 950 && monsterY < 950) {

                            if (grid[mx[i] + 1][my[i]].distLtR < mValue) {
                                monsters[i].returnSpec().rotation = 0;
                            }
                            else if (grid[mx[i]][my[i] - 1].distLtR < mValue) {
                                monsters[i].returnSpec().rotation = 1.570795 * 3;
                            }
                            else if (grid[mx[i]][my[i] + 1].distLtR < mValue) {
                                monsters[i].returnSpec().rotation = 1.570795 * 1;
                            }

                            else {
                                monsters[i].returnSpec().rotation = 0;
                            }

                        }
                        else {
                            monsters[i].returnSpec().rotation = 0;
                            globals.escaped -= 1;
                        }
                    }
                }
            }
        }
    }

    //--------------------------------------------------------
    //
    //  Update functions - 
    //  Don't forget to update the keyboard and mouse!
    //
    //--------------------------------------------------------
    function update(elapsedTime) {

        //----------------------------------

        updatePathLtR(monsters);
        updatePathTtD(monsters);

        for (let i = 0; i < monsters.length; i++) {
            monsters[i].update(elapsedTime);
        }

        //console.log(monsters[0].returnSpec().center.x);
        if (globals.haveWave == true) {
            for (let i = 0; i < monsters.length; i++) {
                monsters[i].moveForward(elapsedTime);
                if (monsters[i].returnSpec().center.x > 1050) {
                    monsters[i].returnSpec().health = 0;
                }
            }
            for (let i = 0; i < monsters.length; i++) {
                if (monsters[i].returnSpec().health <= 0 && monsters[i].returnSpec().center.x < 1050) {
                    particleEngine.damageEnemy({
                        cx: monsters[i].returnSpec().center.x,
                        cy: monsters[i].returnSpec().center.y,
                        w: 50,
                        h: 50,
                        sizeMin: 200,
                        sizeMax: 400,
                        mean: 500,
                        stddev: 50,
                        restInt: 0,
                        speedMin: 5,
                        speedMax: 10
                    });
                    
                    globals.money += 50;
                    globals.score += 100;
                    globals.floatScores.push({
                        text: "100",
                        moveSpeed: 1 / 3,
                        color: 'blue',
                        cx: monsters[i].returnSpec().center.x,
                        cy: monsters[i].returnSpec().center.y,
                        timeAlive: 0,
                        alive: true,
                        lifespan: 1000
                    });
                }
            }
            for (let i = 0; i < monsters.length; i++) {
                if (monsters[i].returnSpec().health <= 0) {
                    monsters.splice(i, 1);
                }
            }
        }

        //------------------------------------------

        updateEngine.setET(elapsedTime);
        myKeyboard.update(elapsedTime);
        if (!globals.gameover) {
            updateEngine.updateGameState();
        }
        updateEngine.animate();
    }

    //--------------------------------------------------------
    //
    //  renderEngine functions called here
    //
    //--------------------------------------------------------
    function render() {
        renderEngine.clear();
        renderEngine.renderGameState();

        //---------------------
		/*creep1.render();
		creep2.render();
		creep3.render();
        spider.render();*/
        for (let i = 0; i < monsters.length; i++) {
            monsters[i].render();
        }
        //----------------------
    }

    //--------------------------------------------------------
    //
    //  Game loop
    //
    //--------------------------------------------------------	
    function gameLoop(currentTime) {
        var elapsedtime = currentTime - globals.previousTime;
        globals.previousTime = currentTime;

        update(elapsedtime);
        render(elapsedtime);

        if (!cancelNextRequest) {
            requestAnimationFrame(gameLoop);
        }
    }

    //--------------------------------------------------------
    //
    //  Set the very first things here
    //
    //--------------------------------------------------------
    function run() {
        initialize();
        cancelNextRequest = false;
        requestAnimationFrame(gameLoop);
    }

    return {
        initialize: initialize,
        run: run,
        monsters: monsters
    };
}(MyGame.Globals,
    MyGame.Main,
    MyGame.UpdateEngine,
    MyGame.RenderEngine,
    MyGame.InputHandler,
    MyGame.AnimationEngine,
    MyGame.objects,
    MyGame.BricksEngine,
    MyGame.ParticleEngine));