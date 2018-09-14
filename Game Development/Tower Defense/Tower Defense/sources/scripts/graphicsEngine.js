MyGame.GraphicsEngine = (function(globals, bricksEngine){
    let canvas = document.getElementById('canvas-main');
    let context = canvas.getContext('2d');

    //--------------------------------------------------------
    //
    //  Load images here
    //
    //--------------------------------------------------------

    let tower1 = document.getElementById("tower1");
    let tower2 = document.getElementById("tower2");
    let tower3 = document.getElementById("tower3");
    let tower4 = document.getElementById("tower4");
    let franc = document.getElementById("franc");

    let currentSkyImage;
    let skyArray = [];

    //--------------------------------
    CanvasRenderingContext2D.prototype.clear = function() {
        this.save();
        this.setTransform(1, 0, 0, 1, 0, 0);
        this.clearRect(0, 0, canvas.width, canvas.height);
        this.restore();
    };
    // function clear() {
    //     context.clear();
    // }
    function SpriteSheet(spec) {
        var that = {},
            image = new Image();

        //
        // Initialize the animation of the spritesheet
        spec.sprite = 0;		// Which sprite to start with
        spec.elapsedTime = 0;	// How much time has occured in the animation

        //
        // Load the image, set the ready flag once it is loaded so that
        // rendering can begin.
        image.onload = function() { 
            //
            // Our clever trick, replace the draw function once the image is loaded...no if statements!
            that.draw = function() {
                context.save();

                context.translate(spec.center.x, spec.center.y);
                context.rotate(spec.rotation);
                context.translate(-spec.center.x, -spec.center.y);

            

                context.beginPath();
                context.lineWidth = "3";
                context.strokeStyle = "black";
                context.rect(spec.center.x - spec.width/2,  spec.center.y - spec.height/2, spec.healthMax, 4);
                context.stroke();

                context.beginPath();
                // context.lineWidth = "1";
                context.fillStyle = "red";
                context.fillRect(spec.center.x - spec.width/2,  spec.center.y - spec.height/2, spec.health, 4);
                
                context.fill();

                //
                // Pick the selected sprite from the sprite sheet to render
                context.drawImage(
                    image,
                    spec.width * spec.sprite, 0,	// Which sprite to pick out
                    spec.width, spec.height,		// The size of the sprite
                    spec.center.x - spec.width/2,	// Where to draw the sprite
                    spec.center.y - spec.height/2,
                    spec.width, spec.height);

                context.restore();
            };
            //
            // Once the image is loaded, we can compute the height and width based upon
            // what we know of the image and the number of sprites in the sheet.
            spec.height = image.height;
            spec.width = image.width / spec.spriteCount;
        };
        image.src = spec.spriteSheet;

        //------------------------------------------------------------------
        //
        // Update the animation of the sprite based upon elapsed time.
        //
        //------------------------------------------------------------------
        that.update = function(elapsedTime, forward) {
            spec.elapsedTime += elapsedTime;
            //
            // Check to see if we should update the animation frame
            if (spec.elapsedTime >= spec.spriteTime[spec.sprite]) {
                //
                // When switching sprites, keep the leftover time because
                // it needs to be accounted for the next sprite animation frame.
                spec.elapsedTime -= spec.spriteTime[spec.sprite];
                //
                // Depending upon the direction of the animation...
                if (forward === true) {
                    spec.sprite += 1;
                    //
                    // This provides wrap around from the last back to the first sprite
                    spec.sprite = spec.sprite % spec.spriteCount;
                } else {
                    spec.sprite -= 1;
                    //
                    // This provides wrap around from the first to the last sprite
                    if (spec.sprite < 0) {
                        spec.sprite = spec.spriteCount - 1;
                    }
                }
            }
        };

        //------------------------------------------------------------------
        //
        // Render the correct sprint from the sprite sheet
        //
        //------------------------------------------------------------------
        that.draw = function() {
            //
            // Starts out empty, but gets replaced once the image is loaded!
        };

        return that;
    }

    function drawBricks(grid){
        context.save();

        for(var r = 0; r < grid.row; r++){
            for(var c = 0; c < grid.col; c++){
                var current = grid.bricks[r][c];
                if(current.alive){
                    context.fillStyle = current.color;
                    if(!globals.showGrid) context.fillStyle = 'rgba(0,255,0,.3)';
                    //console.log(current.x, current.y, current.w, current.h);
                    context.fillRect(current.x, current.y, current.w, current.h);
                }
            }
        }

        context.restore();
    };

    //-------------------------------------
    //=======================================================

    //--------------------------------------------------------
    //
    // This is a handy functions for drawing stars
    //
    //--------------------------------------------------------
    function drawStar(cx, cy, spikes, outerRadius, innerRadius) { //m1erikson http://jsfiddle.net/m1erickson/8j6kdf4o/
        //Before this function set the lineWidth, strokeStyle, and fillStyle
        var rot = Math.PI / 2 * 3;
        var x = cx;
        var y = cy;
        var step = Math.PI / spikes;
    
        context.beginPath();
        context.moveTo(cx, cy - outerRadius)
        for (i = 0; i < spikes; i++) {
            x = cx + Math.cos(rot) * outerRadius;
            y = cy + Math.sin(rot) * outerRadius;
            context.lineTo(x, y)
            rot += step
    
            x = cx + Math.cos(rot) * innerRadius;
            y = cy + Math.sin(rot) * innerRadius;
            context.lineTo(x, y)
            rot += step
        }
        context.lineTo(cx, cy - outerRadius)
        context.closePath();
        context.stroke();
        context.fill();
    
    };

    function clear(){
        //console.log("cleared");
        context.clearRect(0, 0, canvas.width, canvas.height);
    };

    function drawBackground(){
        context.drawImage(backgroundImg, 0, 0, 1000, 1000);
    };

    function mouseBoundsCheck(rect){
        if(globals.mouseCoords.x == -1){
            return true;
        }
        if(globals.mouseCoords.y == -1){
            return true;
        }
        return false;
    };

    function getMouseX(rect){
        //return (globals.mouseCoords.x - rect.left) * (1000/rect.width);
        return globals.mouseCoords.x;
    };

    function getMouseY(rect){
        //return (globals.mouseCoords.y - rect.top) * (1000/rect.height);
        return globals.mouseCoords.y;
    };

    function drawMouse(){
        if(globals.mouseMode == 'none'){
            return;
        }

        let rect = canvas.getBoundingClientRect();

        if(mouseBoundsCheck(rect)){
            return;
        }

        switch(mouseMode){
            case 'tower1':
            
                context.save();
                context.fillStyle = 'rgba(255,0,0,.5)';
                //make relative
                context.beginPath();
                context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                context.fill();
                context.restore();
                context.drawImage(tower1,
                    globals.mouseCoords.x - 20, 
                    globals.mouseCoords.y - 20, 
                    50, 50);
                if(globals.flashRed.show){
                    context.save();
                    context.fillStyle = 'rgba(255,0,0,.5)';
                    //make relative
                    context.beginPath();
                    context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                    context.fill();
                    context.restore();
                } 
                context.restore();
            break;

            case 'tower2':
                context.save();
                context.fillStyle = 'rgba(255,0,0,.5)';
                //make relative
                context.beginPath();
                context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                context.fill();
                context.restore();
                context.drawImage(tower2,
                    globals.mouseCoords.x - 20,
                    globals.mouseCoords.y - 20,
                    50, 50);
                if(globals.flashRed.show){
                    context.save();
                    context.fillStyle = 'rgba(255,0,0,.5)';
                    //make relative
                    context.beginPath();
                    context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                    context.fill();
                    context.restore();
                } 
                context.restore();
            break;

            case 'tower3':
                context.save();
                context.fillStyle = 'rgba(255,0,0,.5)';
                //make relative
                context.beginPath();
                context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                context.fill();
                context.restore();
                context.drawImage(tower3,
                    globals.mouseCoords.x - 20,
                    globals.mouseCoords.y - 20,
                    50, 50);
                if(globals.flashRed.show){
                    context.save();
                    context.fillStyle = 'rgba(255,0,0,.5)';
                    //make relative
                    context.beginPath();
                    context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                    context.fill();
                    context.restore();
                } 
                context.restore();
            break;

            case 'tower4':
                context.save();
                context.fillStyle = 'rgba(255,0,0,.5)';
                //make relative
                context.beginPath();
                context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                context.fill();
                context.restore();
                context.drawImage(tower4,
                    globals.mouseCoords.x - 20,
                    globals.mouseCoords.y - 20,
                    50, 50);
                if(globals.flashRed.show){
                    context.save();
                    context.fillStyle = 'rgba(255,0,0,.5)';
                    //make relative
                    context.beginPath();
                    context.arc(globals.mouseCoords.x, globals.mouseCoords.y, 175, 0, 2 * Math.PI);
                    context.fill();
                    context.restore();
                } 
                context.restore();
            break;

            case 'upgrade':
                    context.save();
                    context.fillStyle = 'bronze';
                    context.strokeStyle = 'black';
                    drawStar(globals.mouseCoords.x - 10, globals.mouseCoords.y - 10, 4, 15, 8);
                    context.restore();
            break;

            case 'sell':
                context.drawImage(franc, globals.mouseCoords.x - 40, globals.mouseCoords.y - 40, 50, 50);
            break;
                    

            default:
            console.log("Error: DrawMouse: Invalid mouse mode");
        }
    };

    function drawUpgrade(block){
        switch(block.upgrade){
            case 1:
                context.save();
                context.fillStyle = 'bronze';
                context.strokeStyle = 'black';
                drawStar(block.x + 40,
                    block.y+7, 4, 6, 4);
                context.restore();
            break;

            case 2:
                context.save();
                context.fillStyle = 'silver';
                context.strokeStyle = 'black';
                drawStar(block.x + 40,
                    block.y+7, 6, 8, 4);
                context.restore();
            break;

            case 3:
                context.save();
                context.fillStyle = 'gold';
                context.strokeStyle = 'black';
                drawStar(block.x + 40,
                    block.y+7, 9, 11, 4);
                context.restore();
            break;
        }
    };

    function drawATower(image, block){
        context.save();
        
        context.translate(block.cx, block.cy);
        context.rotate(block.rotation);
        //if(block.flipme) context.rotate(90*Math.Pi/180);
        context.translate(-block.cx, -block.cy);
        
        context.drawImage(image, block.x, block.y, 50, 50);



        context.restore();
    };

    function drawTowers(){
        var grid = bricksEngine.grid.bricks;
        var drawAStar = true;

        for (var r = 0; r<20; r++){
            for (var c = 0; c<20; c++){
                drawAStar = true;
                if(grid[r][c].showBorder){
                    context.save();
                    context.fillStyle = 'rgba(255,0,0,.5)';
                    //make relative
                    //context.fillRect(grid[r][c].cx-175, grid[r][c].cy-175, 350, 350);
                    context.beginPath();
                    context.arc(grid[r][c].cx, grid[r][c].cy, 175, 0, 2 * Math.PI);
                    context.fill();
                    context.restore();
                }
                switch(grid[r][c].occupied){
                    case 'none':
                    case 'border':
                        drawAStar = false;
                    break;

                    case 'tower1':
                        drawATower(tower1, grid[r][c]);
                    break;

                    case 'tower2':
                        drawATower(tower2, grid[r][c]);
                    break;

                    case 'tower3':
                        drawATower(tower3, grid[r][c]);
                    break;

                    case 'tower4':
                        drawATower(tower4, grid[r][c]);
                    break;

                    default:
                        console.log("Error: drawTowers: invalid grid brick occupied status");
                    break;
                }

                if(drawAStar){
                    drawUpgrade(grid[r][c]);
                }
            }
        }
    };

    function drawBorder(){
        context.save();
        context.fillStyle = 'orange';
        context.fillRect(0,0,50, 8*50);
        context.fillRect(0,0,8*50, 50);
        
        context.fillRect(1000-(8*50),0, 8*50, 50);
        context.fillRect(1000-50, 0, 50, 8*50);
        
        context.fillRect(0,1000-(8*50),50,8*50);
        context.fillRect(0, 1000-50, 8*50, 50);

        context.fillRect(1000-(8*50), 1000-50, 8*50, 50);
        context.fillRect(1000-50, 1000-(8*50), 50, 8*50);
        context.restore();
    };

    function drawTtB(grid){
        for(var r=0; r<20; r++){
            for(var c=0; c<20; c++){
                context.save();
                context.font = "20px Arial";
                context.fillStyle = 'rgba(255,0,0,1)';
                context.textAlign = "center";
                context.fillText(grid[r][c].distTtB, r*50+25, c*50+25)
                context.restore();
            }
        }
    };

    function drawLtR(grid){
        for(var r=0; r<20; r++){
            for(var c=0; c<20; c++){
                context.save();
                context.font = "20px Arial";
                context.fillStyle = 'rgba(0,255,0,1)';
                context.textAlign = "center";
                context.fillText(grid[r][c].distLtR, r*50+25, c*50+25)
                context.restore();
            }
        }
    };

    function drawCoords(grid){
        for(var r=0; r<20; r++){
            for(var c=0; c<20; c++){
                context.save();
                context.font = "14px Arial";
                context.fillStyle = 'rgba(0,255,0,1)';
                context.textAlign = "center";
                context.fillText("r: " + r, r*50+25, c*50+15);
                context.fillText("c: " + c, r*50+25, c*50+35);
                context.restore();
            }
        }
    };

    function drawBombs(){
        "use-strict";
        bombs = globals.bombs.bombArray;
        aoe = globals.bombs.aoe;
        explosions = globals.bombs.explosions;

        for(var i = 0; i<bombs.length; i++){
            if(bombs[i].alive){
                context.save();
                context.fillStyle = 'rgba(0,0,255,1)';
                context.beginPath();
                context.arc(bombs[i].x, bombs[i].y, 5, 0, 2 * Math.PI);
                context.fill();                    
                context.restore();
            }
        }

        for(var i = 0; i < aoe.length; i++){
            if(aoe[i].alive){
                context.save();
                context.fillStyle = 'rgba(255,0,0,1)';
                context.beginPath();
                context.arc(aoe[i].x, aoe[i].y, 10, 0, 2 * Math.PI);
                context.fill();                    
                context.restore();
            }
        }

        for(var i = 0; i < explosions.length; i++){
            if(explosions[i].alive){
                console.log(explosions[i]);
                context.save();
                context.fillStyle = 'rgba(255,0,0,.3)';
                context.beginPath();
                context.arc(explosions[i].cx, explosions[i].cy, explosions[i].r, 0, 2 * Math.PI);
                context.fill();                    
                context.restore();
            }
        }

    };

    function drawMoney(){
        context.save();
        context.font = "30px Arial";
        context.fillStyle = 'rgba(0,0,0,1)';
        context.textAlign = "center";
        context.fillText("Money: " + globals.money, 850, 980)
        context.restore();
    };

    function drawScore(){
        context.save();
        context.font = "30px Arial";
        context.fillStyle = 'rgba(0,0,0,1)';
        context.textAlign = "left";
        context.fillText("Score: " + globals.score, 50, 980)
        context.restore();
    };

    function drawFloats(){
        "use-strict";
        for(var i = 0; i < globals.floatScores.length; i++){
            context.save();
            context.font = "10px Arial";
            context.fillStyle = globals.floatScores[i].color;
            context.textAlign = "left";
            context.fillText(globals.floatScores[i].text, globals.floatScores[i].cx, globals.floatScores[i].cy);
            context.restore();
        }
    };

    function drawGame(grid){
        //--------------------------------------------------------
        //
        //  Call all the other draw functions in here 
        //      and call this function in renderEngine
        //
        //--------------------------------------------------------

        if(!globals.boundingRectGot){
            globals.canvasBounds = canvas.getBoundingClientRect();
            if(globals.canvasBounds.left!=0){
                globals.boundingRectGot = true;
            }
        }
        drawBricks(grid);
        drawBorder();
        drawTowers();
        drawMouse();
        drawBombs();
        drawMoney();
        drawScore();
        drawFloats();

        //drawTtB(grid.bricks);
        //drawLtR(grid.bricks);
        //drawCoords(grid.bricks);

    };

    //--------------------------------------------------------
    //
    //  Put the particle drawing functions here
    //      I left this one as an example
    //
    //--------------------------------------------------------
    function drawStarParticle(p){
        "use-strict";
        context.save();
        context.translate(p.cx, p.cy);
        context.rotate(p.rotation);
        context.translate(-p.cx, -p.cy);
        context.fillStyle = 'rgba(' + p.r + ', ' + p.g + ', ' + p.b + ', ' + p.a + ')';
        context.strokeStyle = 'rgba(' + p.r + ', ' + p.g + ', ' + p.b + ', ' + p.a + ')';
        drawStar(p.cx, p.cy, 5, p.w/2, p.w/3);
        context.restore();
    };

    function initialize(){
    };

    return{
        clear: clear,
        drawGame: drawGame,
        drawStarParticle: drawStarParticle,
        initialize: initialize,

        //----------------------
        SpriteSheet: SpriteSheet
        //----------------------

    };
})(MyGame.Globals, MyGame.BricksEngine);