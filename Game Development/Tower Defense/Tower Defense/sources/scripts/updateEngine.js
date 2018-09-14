MyGame.UpdateEngine = (function(globals, animationEngine, 
    graphicsEngine, bricksEngine, particleEngine){
    let elapsedtime;
    //let bombs = [];

    function setET(et) {elapsedtime = et;};
    
    function checkHighScores(){
        var score = globals.score;
        var temp;
        var name;
        var higher = false;

        if(score > localStorage.hs1score){
            if(!higher) name = prompt("You got a high score!\nEnter your name:");
            higher = true;

            temp = localStorage.hs1score;
            localStorage.hs1score = score;
            score = temp;

            temp = localStorage.hs1name;
            localStorage.hs1name = name;
            name = temp;
        }

        if(score > localStorage.hs2score){
            if(!higher) name = prompt("You got a high score!\nEnter your name:");
            higher = true;

            temp = localStorage.hs2score;
            localStorage.hs2score = score;
            score = temp;

            temp = localStorage.hs2name;
            localStorage.hs2name = name;
            name = temp;
        }

        if(score > localStorage.hs3score){
            if(!higher) name = prompt("You got a high score!\nEnter your name:");
            higher = true;

            temp = localStorage.hs3score;
            localStorage.hs3score = score;
            score = temp;

            temp = localStorage.hs3name;
            localStorage.hs3name = name;
            name = temp;
        }

        if(score > localStorage.hs4score){
            if(!higher) name = prompt("You got a high score!\nEnter your name:");
            higher = true;

            temp = localStorage.hs4score;
            localStorage.hs4score = score;
            score = temp;

            temp = localStorage.hs4name;
            localStorage.hs4name = name;
            name = temp;
        }

        if(score > localStorage.hs5score){
            if(!higher) name = prompt("You got a high score!\nEnter your name:");
            higher = true;

            temp = localStorage.hs5score;
            localStorage.hs5score = score;
            score = temp;

            temp = localStorage.hs5name;
            localStorage.hs5name = name;
            name = temp;
        }

    };
    
    function checkWin(){
        if(globals.escaped <= 0){
            var grid = bricksEngine.grid.bricks;
            alert("A winrar is you!\nYou got a score of " + globals.score);
            checkHighScores();
            globals.gameover = true;
        }
    };

    //------------------------------------------------------------------
	//
	// Returns the magnitude of the 2D cross product.  The sign of the
	// magnitude tells you which direction to rotate to close the angle
	// between the two vectors.
	//
	//------------------------------------------------------------------
	function crossProduct2d(v1, v2) {
		return (v1.x * v2.y) - (v1.y * v2.x);
	};

	//------------------------------------------------------------------
	//
	// Computes the angle, and direction (cross product) between two vectors.
	//
	//------------------------------------------------------------------
	function computeAngle(rotation, ptCenter, ptTarget) {
		var v1 = {
				x : Math.cos(rotation),
				y : Math.sin(rotation)
			},
			v2 = {
				x : ptTarget.x - ptCenter.x,
				y : ptTarget.y - ptCenter.y
			},
			dp,
			angle;

		v2.len = Math.sqrt(v2.x * v2.x + v2.y * v2.y);
		v2.x /= v2.len;
		v2.y /= v2.len;

		dp = v1.x * v2.x + v1.y * v2.y;
		angle = Math.acos(dp);

		//
		// Get the cross product of the two vectors so we can know
		// which direction to rotate.
		cp = crossProduct2d(v1, v2);

		return {
			angle : angle,
			crossProduct : cp
		};
	};

	//------------------------------------------------------------------
	//
	// Simple helper function to help testing a value with some level of tolerance.
	//
	//------------------------------------------------------------------
	function testTolerance(value, test, tolerance) {
		if (Math.abs(value - test) < tolerance) {
			return true;
		} else {
			return false;
		}
    };

    function findClosestEnemy(tower){
        "use-strict";
        targets = MyGame.screens['game-play'].monsters;

        var ret = -1;
        var closest;
        var closestDist;

        if(targets.length > 0){
            closest = 0;
            closestDist = Math.abs(Math.hypot(tower.cy - targets[0].returnSpec().center.y, tower.cx - targets[0].returnSpec().center.x));
            
            for(var i = 0; i < targets.length; i++){
                if(targets[i].returnSpec().type == tower.attacks){
                    var tempDist = Math.abs(Math.hypot(tower.cy - targets[i].returnSpec().center.y, tower.cx - targets[i].returnSpec().center.x));
                    if(tempDist < closestDist){
                        closestDist = tempDist;
                        closest = i;
                    }
                }
            }
        }

        if(closest == 0 && targets[0].returnSpec().type != tower.attacks) closest = -1;

        return {i: closest, closestDist: closestDist}
    };
    
    function checkTowersAgainstEnemies(){
        var grid = bricksEngine.grid.bricks;
        targets = MyGame.screens['game-play'].monsters;

        for(var r=0; r<20; r++){
            for(var c=0; c<20; c++){
                if(grid[r][c].occupied == "tower1" || grid[r][c].occupied == "tower2" || 
                    grid[r][c].occupied == "tower3" || grid[r][c].occupied == "tower4"){
                    var cei = findClosestEnemy(grid[r][c]);
                    if(cei.i != -1){
                        if(cei.closestDist < 200){
                            var result = computeAngle(grid[r][c].rotation, {x: grid[r][c].cx, y: grid[r][c].cy}, targets[cei.i].returnSpec().center);
			                if (testTolerance(result.angle, 0, .01) === false) {
				                if (result.crossProduct > 0) {
					                grid[r][c].rotation -= grid[r][c].rotationRate;
				                } else {
					                grid[r][c].rotation += grid[r][c].rotationRate;
                                }
                                grid[r][c].firing = true;
                            } else {
                                grid[r][c].firing = false;
                            }
                        } else {
                            grid[r][c].firing = false;
                        }
                    }
                }
            }
        }
    };

    function leftToRight(found, grid, r, c){
        "use strict";
        grid[r][c].visited = true;
        if(r == 8 && c == 19){
            return true;
        }

        if(!found && c < 19) {
            if(grid[r][c+1].occupied == 'none' && !grid[r][c+1].visited) found = leftToRight(found, grid, r, c+1);
        };
        if(!found && r < 19) {
            if(grid[r+1][c].occupied == 'none' && !grid[r+1][c].visited) found = leftToRight(found, grid, r+1, c);
        };
        if(!found && r > 0) {
            if(grid[r-1][c].occupied == 'none' && !grid[r-1][c].visited) found = leftToRight(found, grid, r-1, c);
        };
        if(!found && c > 0) {
            if(grid[r][c-1].occupied == 'none' && !grid[r][c-1].visited) found = leftToRight(found, grid, r, c-1);
        };

        return found;
    };

    function topToBottom(found, grid, r, c){
        "use strict";
        grid[r][c].visited = true;
        if(r == 19 && c == 8){
            return true;
        }

        if(!found && r < 19) {
            if(grid[r+1][c].occupied == 'none' && !grid[r+1][c].visited) found = topToBottom(found, grid, r+1, c);
        };
        if(!found && c > 0) {
            if(grid[r][c-1].occupied == 'none' && !grid[r][c-1].visited) found = topToBottom(found, grid, r, c-1);
        };
        if(!found && c < 19) {
            if(grid[r][c+1].occupied == 'none' && !grid[r][c+1].visited) found = topToBottom(found, grid, r, c+1);
        };
        if(!found && r > 0) {
            if(grid[r-1][c].occupied == 'none' && !grid[r-1][c].visited) found = topToBottom(found, grid, r-1, c);
        };

        return found;
    };

    function pathsClear(grid){
        for(var r=0; r<20; r++){
            for(var c=0; c<20; c++){
                grid[r][c].visited = false;
            }
        }
        var found;
        found = leftToRight(false, grid, 11, 0);
        if(found){
            for(var r=0; r<20; r++){
                for(var c=0; c<20; c++){
                    grid[r][c].visited = false;
                }
            }
            found = topToBottom(false, grid, 0, 11);
        }
        return found;
    };

    function getTowerName(towerName){
        switch(towerName){
            case "tower1":
                return "Tower 1 aka Unstoppable Force";
            break;

            case "tower2":
                return "Tower 2 aka Immovable Object";
            break;

            case 'tower3':
                return "Tower 3 aka Icarus";
            break;

            case 'tower4':
                return "Tower 4 aka Zeus";
            break;
        }
    };

    function getDamage(towerName){
        switch(towerName){
            case "tower1":
                return 1;
            break;

            case "tower2":
                return 2;
            break;

            case 'tower3':
                return 1;
            break;

            case 'tower4':
                return 2;
            break;
        }
    };

    function setTtB(grid, queue){
        'use-strict';
        while(queue.length > 0){
            cur = queue.shift();
            if(cur.r < 19){
                if(grid[cur.r+1][cur.c].distTtB == -1 && grid[cur.c][cur.r+1].occupied == 'none'){
                    grid[cur.r+1][cur.c].distTtB = cur.l + 1;
                    queue.push({r: (cur.r+1), c: (cur.c), l: cur.l+1});
                }
            }
            if(cur.r > 0){
                if(grid[cur.r-1][cur.c].distTtB == -1 && grid[cur.c][cur.r-1].occupied == 'none'){
                    grid[cur.r-1][cur.c].distTtB = cur.l + 1;
                    queue.push({r: cur.r-1, c: cur.c, l: cur.l+1});
                }
            }
            if(cur.c < 19){
                if(grid[cur.r][cur.c+1].distTtB == -1 && grid[cur.c+1][cur.r].occupied == 'none'){
                    grid[cur.r][cur.c+1].distTtB = cur.l + 1;
                    queue.push({r: cur.r, c: cur.c+1, l: cur.l+1});
                }
            }
            if(cur.c > 0){
                if(grid[cur.r][cur.c-1].distTtB == -1 && grid[cur.c-1][cur.r].occupied == 'none'){
                    grid[cur.r][cur.c-1].distTtB = cur.l + 1;
                    queue.push({r: cur.r, c: cur.c-1, l: cur.l+1});
                }
            }
        }
    };

    function setLtR(grid, queue){
        'use-strict';
        while(queue.length > 0){
            cur = queue.shift();
            if(cur.r < 19){
                if(grid[cur.r+1][cur.c].distLtR == -1 && grid[cur.c][cur.r+1].occupied == 'none'){
                    grid[cur.r+1][cur.c].distLtR = cur.l + 1;
                    queue.push({r: (cur.r+1), c: (cur.c), l: cur.l+1});
                }
            }
            if(cur.r > 0){
                if(grid[cur.r-1][cur.c].distLtR == -1 && grid[cur.c][cur.r-1].occupied == 'none'){
                    grid[cur.r-1][cur.c].distLtR = cur.l + 1;
                    queue.push({r: cur.r-1, c: cur.c, l: cur.l+1});
                }
            }
            if(cur.c < 19){
                if(grid[cur.r][cur.c+1].distLtR == -1 && grid[cur.c+1][cur.r].occupied == 'none'){
                    grid[cur.r][cur.c+1].distLtR = cur.l + 1;
                    queue.push({r: cur.r, c: cur.c+1, l: cur.l+1});
                }
            }
            if(cur.c > 0){
                if(grid[cur.r][cur.c-1].distLtR == -1 && grid[cur.c-1][cur.r].occupied == 'none'){
                    grid[cur.r][cur.c-1].distLtR = cur.l + 1;
                    queue.push({r: cur.r, c: cur.c-1, l: cur.l+1});
                }
            }
        }
    };

    function updatePaths(){
        'use-strict';
        var grid = bricksEngine.grid.bricks;

        for(var r=0;r<20; r++){
            for(var c=0;c<20; c++){
                grid[r][c].distTtB = -1;
                grid[r][c].distLtR = -1;
            }
        }
        
        for(var r=0;r<20; r++){
            for(var c=0;c<20; c++){
                if(grid[r][c].distTtB != -1){
                    console.log("Problem at ", r, ", ", c);
                }
            }
        }

        var TtBqueue = [];
        var LtRqueue = [];

        grid[8][19].distTtB = 0;
        grid[19][8].distLtR = 0;

        TtBqueue.push({r: 8, c: 19, l: 0});
        LtRqueue.push({r: 19, c: 8, l: 0});

        setTtB(grid, TtBqueue);
        setLtR(grid, LtRqueue);
    };

    function towerCost(towerName){
        switch(towerName){
            case "tower1":
                return 2000;
            break;

            case "tower2":
                return 3000;
            break;

            case 'tower3':
                return 500;
            break;

            case 'tower4':
                return 1000;
            break;
        }
    };

    function getTowerFR(towerName){
        switch(towerName){
            case "tower1":
                return 100;
            break;

            case "tower2":
                return 800;
            break;

            case 'tower3':
                return 100;
            break;

            case 'tower4':
                return 200;
            break;
        }
    };

    function getAttacks(towerName){
        switch(towerName){
            case "tower1":

            case "tower2":
                return 'ground';
            break;

            case 'tower3':

            case 'tower4':
                return 'air';
            break;
        }
    };

    function placeTower(towerName){
        var grid = bricksEngine.grid.bricks;
        var brickC = Math.floor(globals.mouseCoords.x / 50);
        var brickR = Math.floor(globals.mouseCoords.y / 50);

        if(globals.money - towerCost(towerName) < 0){
            globals.flashRed.show = true;
            return;
        }
        
        if(grid[brickR][brickC].occupied == 'none' && brickC > 0 && brickC < 19
            && brickR > 0 && brickR <19){
            grid[brickR][brickC].occupied = towerName;
            if(pathsClear(grid)){
                grid[brickR][brickC].towerName = getTowerName(towerName);
                grid[brickR][brickC].damage = getDamage(towerName);
                grid[brickR][brickC].upgrade = 1;
                grid[brickR][brickC].firingRate = getTowerFR(towerName);
                grid[brickR][brickC].attacks = getAttacks(towerName);
                globals.money -= towerCost(towerName);
                globals.score += towerCost(towerName);
                globals.mouseMode = 'none';
                clearTowerInfo();
                updatePaths();
            } else {
              grid[brickR][brickC].occupied = 'none';
              globals.flashRed.show = true;  
            }
        }

    };

    function upgradeTower(){
        var grid = bricksEngine.grid.bricks;
        var brickC = Math.floor(globals.mouseCoords.x / 50);
        var brickR = Math.floor(globals.mouseCoords.y / 50);
        var oc = grid[brickR][brickC].occupied;
        var uplevel = grid[brickR][brickC].upgrade;
        
        if((oc == 'tower1' || oc == 'tower2' || oc == 'tower3' || oc == 'tower4') && uplevel < 3){
            if(globals.money - towerCost(oc)/2 < 0){
                return;
            }
            globals.money -= towerCost(oc)/2;
            globals.score += towerCost(oc)/2;
            grid[brickR][brickC].upgrade += 1;
            grid[brickR][brickC].damage *= 2;
            globals.mouseMode = 'none';
        }

    };

    function sellTower(){
        var grid = bricksEngine.grid.bricks;
        var brickC = Math.floor(globals.mouseCoords.x / 50);
        var brickR = Math.floor(globals.mouseCoords.y / 50);
        var oc = grid[brickR][brickC].occupied;
        var uplevel = grid[brickR][brickC].upgrade;

        if(oc == 'tower1' || oc == 'tower2' || oc == 'tower3' || oc == 'tower4'){
            globals.money += 500 * grid[brickR][brickC].upgrade;
            
            grid[brickR][brickC].upgrade = 0;
            grid[brickR][brickC].occupied = 'none';
            grid[brickR][brickC].firing = false;
            globals.mouseMode = 'none';
            particleEngine.damageEnemy({
                cx: grid[brickR][brickC].cx,
                cy: grid[brickR][brickC].cy,
                w: 50,
                h: 50,
                sizeMin: 40,
                sizeMax: 80,
                mean: 500,
                stddev: 50,
                restInt: 0,
                speedMin: 5,
                speedMax: 10
            });
        }
    };

    function showTowerInfo(grid, r, c){
        document.getElementById("id-tower-info").innerHTML = "<font size =\"6\">" +
        "<p style=\"line-height=1\">" + grid[r][c].towerName + "<\p>" + 
        "------------------" +
        "<p style=\"line-height=1\">Damage " + grid[r][c].damage + "<\p>" +
        "<p style=\"line-height=1\">Level: " + grid[r][c].upgrade + "<\p>" +
        "<p style=\"line-height=1\">Cost: " + towerCost(grid[r][c].towerName) + "<\p>" +
        "</font>";

    };

    function showMouseTowerInfo(towerName){
        var msg = "<font size =\"6\">" +
        "<p style=\"line-height=1\">" + getTowerName(towerName) + "<\p>" + 
        "------------------" +
        "<p style=\"line-height=1\">Damage " + getDamage(towerName) + "<\p>" +
        "<p style=\"line-height=1\">Level: " + "1" + "<\p>" +
        "<p style=\"line-height=1\">Cost: " + towerCost(towerName) + "<\p>" +
        "</font>";
        document.getElementById("id-tower-info").innerHTML = msg;
    };

    function clearTowerInfo(){
        document.getElementById("id-tower-info").innerHTML = "";
    };

    function toggleTowerBorder(){
        var grid = bricksEngine.grid.bricks;
        var brickC = Math.floor(globals.mouseCoords.x / 50);
        var brickR = Math.floor(globals.mouseCoords.y / 50);
        var oc = grid[brickR][brickC].occupied;
        var uplevel = grid[brickR][brickC].upgrade;

        clearTowerInfo();
        for(var r = 0; r<20; r++){
            for(var c = 0; c<20;c++){
                grid[r][c].showBorder = false;
            }
        }

        if(oc == 'tower1' || oc == 'tower2' || oc == 'tower3' || oc == 'tower4'){
            grid[brickR][brickC].showBorder = true;
            globals.mouseMode = 'none';
            showTowerInfo(grid, brickR, brickC);
        }
    };

    function launchBomb(targetNum, startBlock){
        globals.bombs.bombArray.push({ x: startBlock.cx,
                     y: startBlock.cy,
                     target: targetNum,
                     speed: 10,
                     damage: startBlock.damage,
                     alive: true
                    });
    };

    function launchAoeBomb(targetCenter, startBlock){
        globals.bombs.aoe.push({
            x: startBlock.cx,
            y: startBlock.cy,
            tx: targetCenter.x,
            ty: targetCenter.y,
            speed: 20,
            radius: 100,
            damage: startBlock.damage,
            alive: true
        });
    };

    function dealAoeDamage(tx, ty, damage, radius){
        var targets = MyGame.screens['game-play'].monsters;

        for(var i = 0; i < targets.length; i++){
            if(targets[i].returnSpec().type == 'ground'){
                var tempDist = Math.sqrt(Math.pow( (targets[i].returnSpec().center.x - tx),2) + Math.pow((targets[i].returnSpec().center.y - ty),2) );;
                if(tempDist < radius){
                    targets[i].returnSpec().health -= damage;
                }
            }
        }

        globals.bombs.explosions.push({
            cx: tx,
            cy: ty,
            r: radius,
            alive: true,
            timeAlive: 0,
            lifespan: 100
        });

        particleEngine.damageEnemy({
            cx: tx,
            cy: ty,
            w: 100,
            h: 100,
            sizeMin: 200,
            sizeMax: 400,
            mean: 500,
            stddev: 50,
            restInt: 0,
            speedMin: 5,
            speedMax: 10
        });
    };

    function updateBombs(){
        "use-strict";
        var targets = MyGame.screens['game-play'].monsters;
        var bombs = globals.bombs.bombArray;
        var aoe = globals.bombs.aoe;
        var explosions = globals.bombs.explosions;

        for(var i = 0; i<bombs.length; i++){
            var bomb = bombs[i];
            if(bomb.target >= targets.length){
                bomb.alive = false;
            } else {
                if(bomb.alive){
                    var targetCenter = targets[bomb.target].returnSpec().center;

                    var distance = Math.sqrt(Math.pow( (targetCenter.x - bomb.x),2) + Math.pow((targetCenter.y - bomb.y),2) );
                    if(distance < bomb.speed){
                        bomb.alive = false;
                        targets[bomb.target].returnSpec().health -= bomb.damage;
                    } else {
                        particleEngine.damageEnemy({
                            cx: bomb.x,
                            cy: bomb.y,
                            w: 50,
                            h: 50,
                            sizeMin: 5,
                            sizeMax: 10,
                            mean: 500,
                            stddev: 50,
                            restInt: 0,
                            speedMin: 10,
                            speedMax: 30
                        });
                        var xr = bomb.speed * ( (targetCenter.x - bomb.x) / distance );
                        var yr = bomb.speed * ( (targetCenter.y - bomb.y) / distance );
                        bomb.x += xr;
                        bomb.y += yr;
                    }

                }
            }
        }

        for(var i = 0; i<aoe.length; i++){
            var a = aoe[i];
            if(a.alive){
                var distance = Math.sqrt(Math.pow( (a.tx - a.x),2) + Math.pow((a.ty - a.y),2) );
                if(distance < a.speed){
                    a.alive = false;
                    dealAoeDamage(a.tx, a.ty, a.damage, a.radius);
                } else {
                    particleEngine.damageEnemy({
                        cx: a.x,
                        cy: a.y,
                        w: 50,
                        h: 50,
                        sizeMin: 5,
                        sizeMax: 10,
                        mean: 500,
                        stddev: 50,
                        restInt: 0,
                        speedMin: 10,
                        speedMax: 30
                    });
                    var xr = a.speed * ( (a.tx - a.x) / distance );
                    var yr = a.speed * ( (a.ty - a.y) / distance );
                    a.x += xr;
                    a.y += yr;
                }
            }
        }

        for(var i = 0; i < explosions.length; i++){
            explosions[i].timeAlive += elapsedtime;
            if(explosions[i].timeAlive > explosions[i].lifespan){
                explosions[i].alive = false;
            }
        }

        for(var i = 0; i<bombs.length; i++){
            if(!bombs[i].alive){
                bombs.splice(1,i);
            }
        }

        for(var i = 0; i<aoe.length; i++){
            if(!aoe[i].alive){
                aoe.splice(1,i);
            }
        }

        for(var i = 0; i<explosions.length; i++){
            if(!explosions[i].alive){
                explosions.splice(1,i);
            } 
        }

        globals.bombs.bombArray = bombs;
        globals.bombs.aoe = aoe;
        globals.bombs.explosions = explosions;
    };

    function fireOnEnemies(){
        "use-strict";
        var grid = bricksEngine.grid.bricks;
        var targets = MyGame.screens['game-play'].monsters;

        for(var r = 0; r<20; r++){
            for(var c = 0; c<20; c++){
                if(grid[r][c].firing){
                    grid[r][c].firingTime += elapsedtime;
                    if(grid[r][c].firingTime > grid[r][c].firingRate){
                        grid[r][c].firingTime = 0;
                        var cei = findClosestEnemy(grid[r][c]);
                        if(cei.i != -1){
                            if(cei.closestDist < 200){
                                globals.shootAudio.play();
                                if(grid[r][c].occupied == 'tower4'){
                                    launchBomb(cei.i, grid[r][c]);
                                } else if (grid[r][c].occupied == 'tower2'){
                                    launchAoeBomb(targets[cei.i].returnSpec().center, grid[r][c]);
                                } else {
                                    particleEngine.damageEnemy({
                                        cx: targets[cei.i].returnSpec().center.x,
                                        cy: targets[cei.i].returnSpec().center.y,
                                        w: 50,
                                        h: 50,
                                        sizeMin: 5,
                                        sizeMax: 10,
                                        mean: 500,
                                        stddev: 50,
                                        restInt: 0,
                                        speedMin: 10,
                                        speedMax: 30
                                    });
                                    targets[cei.i].returnSpec().health -= grid[r][c].damage;
                                }
                            }
                        }
                    }
                }
            }
        }
    };

    function updateFloaters(){
        "use-strict";
        var floaters = globals.floatScores;

        for(var i = 0; i < floaters.length; i++){
            floaters[i].cy -= floaters[i].moveSpeed;
            if(floaters[i].color == 'blue'){
                floaters[i].color = 'green';
            } else {
                floaters[i].color = 'blue';
            }
            floaters[i].timeAlive += elapsedtime;
            if(floaters[i].timeAlive > floaters[i].lifespan){
                floaters[i].alive = false;
            }
        }

        for(var i = 0; i<floaters.length; i++){
            if(!floaters[i].alive){
                floaters.splice(1, i);
            }
        }
        globals.floatScores = floaters;
    };

    function mouseDown(){
        switch(globals.mouseMode){
            case 'none':
            toggleTowerBorder();
            case 'border':
            break;

            case 'tower1':
                placeTower('tower1');
            break;

            case 'tower2':
                placeTower('tower2');
            break;

            case 'tower3':
                placeTower('tower3');
            break;

            case 'tower4':
                placeTower('tower4');
            break;

            case 'upgrade':
                upgradeTower();
            break;

            case 'sell':
                sellTower();
            break;

            default:
                console.log("Error: mouseDown: invalid mouse mode");
            break;
        }
    };
    

    function fps(){
        globals.fps = 1000/elapsedtime;
    };

    function updateGameState(){
        //--------------------------------------------------------------------
        //
        // TO DO::
        //
        // ADD UPDATE FUNCTIONS FOR:
        //      1. CREEPS
        //          - INCLUDE COLLISION DETECTION AND AI MOVEMENT
        //      2. TOWER ROTATE
        //          - USE THE EXAMPLE MATH
        //      3. BULLET/MISSLES
        //          - MOVE TOWARD CREEP AND DO COLLISION DETECTION
        //
        //--------------------------------------------------------------------

        fps();
        particleEngine.setET(elapsedtime);
        particleEngine.update();
        if(globals.flashRed.show){
            globals.flashRed.time += elapsedtime;
            if(globals.flashRed.time > globals.flashRed.interval){
                globals.flashRed.show = false;
                globals.flashRed.time = 0;
            }
        }

        if(globals.haveWave){
            checkTowersAgainstEnemies();
            fireOnEnemies();
            updateBombs();
            updateFloaters();
            checkWin();
        }

        if(globals.sendwavebutton.sent){
            globals.sendwavebutton.wait += elapsedtime;
            if(globals.sendwavebutton.wait > globals.sendwavebutton.waitInt){
                globals.sendwavebutton.sent = false;
                globals.sendwavebutton.wait = 0;
            }
        }
    };

    function animate(){
        animationEngine.animate(elapsedtime);
    };

    function initialize(){
        updatePaths();
        particleEngine.clear();
        //----------------------------------------------------
        //
        // INITIALIZE PARTICLE ENGINE HERE
        //
        //----------------------------------------------------
    };

    return{
        initialize: initialize,
        animate: animate,
        setET: setET,
        updateGameState: updateGameState,
        mouseDown: mouseDown,
        showMouseTowerInfo: showMouseTowerInfo
    };
})(MyGame.Globals, MyGame.AnimationEngine,
     MyGame.GraphicsEngine, MyGame.BricksEngine,
    MyGame.ParticleEngine);