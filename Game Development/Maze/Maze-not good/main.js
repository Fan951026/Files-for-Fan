let inputStage = {};
let maze = [];
let imgFloor = new Image();
let size = 5;
let totalTime = 0;
let previousTime = performance.now();
imgFloor.isReady = false;
imgFloor.onload = function () {
    this.isReady = true;
};
imgFloor.src = 'floor.png';
function start() {
    size = 5;
    maze = algorithm(size, size);
    myCharacter = createCharacter('character.png', maze[0][0]);
    rabbit = createCharacter('rabbit.png', maze[size - 1][size - 1]);
    totalTime = 0;
    score = 0;
    keybread = 1;
    keypass = 1;
    keyscore = 1;
    keyhint = 1;
    clearVisited(maze);
    ShortPass(myCharacter.location);
    if (myCharacter.location.path === true) {
        myCharacter.location.path = false;
    }

}
function buttonPressed(num) {
    size = num;
    creatmaze();
    keybread = 1;
    keypass = 1;
    keyhint = 1;
    return size;
}

function creatmaze() {
    maze = algorithm(size, size);
    myCharacter = createCharacter('character.png', maze[0][0]);
    rabbit = createCharacter('rabbit.png', maze[size - 1][size - 1]);
    clearVisited(maze);
    ShortPass(myCharacter.location);
    if (myCharacter.location.path === true) {
        myCharacter.location.path = false;
    }
}

let keeppath = [];
function ShortPass(cell) {
    cell.visited = true;
    keeppath = [];
    let end = maze[size - 1][size - 1];

    if (cell === end) {

        return true;
    }

    if (cell.edges.w != null && !cell.edges.w.visited) {
        let foundw = ShortPass(cell.edges.w);

        if (foundw) {
            keeppath.push(cell);
            console.log(keeppath);


            return cell.path = true;

        }

    }
    if (cell.edges.e != null && !cell.edges.e.visited) {
        let founde = ShortPass(cell.edges.e);

        if (founde) {
            keeppath.push(cell);
            console.log(keeppath);
            return cell.path = true;
        }
    }
    if (cell.edges.n != null && !cell.edges.n.visited) {
        let foundn = ShortPass(cell.edges.n);
        if (foundn) {
            keeppath.push(cell);
            console.log(keeppath);
            return cell.path = true;

        }
    }
    if (cell.edges.s != null && !cell.edges.s.visited) {
        let founds = ShortPass(cell.edges.s);
        if (founds) {
            keeppath.push(cell);
            console.log(keeppath);
            return cell.path = true;

        }

    }

    cell.path = false;

    return false;


}

// function HintPass(cell) {
//     cell.visited = true;
//     keeppath = [];
//     let end = maze[size - 1][size - 1];

//     if (cell === end) {

//         return true;
//     }

//     if (cell.edges.w != null && !cell.edges.w.visited) {
//         let foundw = ShortPass(cell.edges.w);

//         if (foundw) {
//             return keeppath.push(cell);
//             console.log(keeppath);


//         }

//     }
//     if (cell.edges.e != null && !cell.edges.e.visited) {
//         let founde = ShortPass(cell.edges.e);

//         if (founde) {
//            return keeppath.push(cell);
//             console.log(keeppath);

//         }
//     }
//     if (cell.edges.n != null && !cell.edges.n.visited) {
//         let foundn = ShortPass(cell.edges.n);
//         if (foundn) {
//            return  keeppath.push(cell);
//             console.log(keeppath);


//         }
//     }
//     if (cell.edges.s != null && !cell.edges.s.visited) {
//         let founds = ShortPass(cell.edges.s);
//         if (founds) {
//             keeppath.push(cell);
//             console.log(keeppath);


//         }

//     }


//     return keeppath;

// }
// function inend(){
//     if(myCharacter.location == maze[size][size]){

//    }

// }
function clearVisited(maze) {
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            maze[i][j].visited = false;
        }
    }
}


function createCharacter(imageSource, location) {
    let image = new Image();
    image.isReady = false;
    image.onload = function () {
        this.isReady = true;
    };
    image.src = imageSource;
    return {
        location: location,
        image: image
    };
}


function algorithm(rowNum, colNum) {
    maze = [];
    for (let row = 0; row < rowNum; row++) {
        maze.push([]);
        for (let col = 0; col < colNum; col++) {
            maze[row].push({
                x: col,
                y: row,
                edges: {
                    n: null,
                    s: null,
                    w: null,
                    e: null
                },
                visited: false,
                path: false,
                bread: false,
                hint:false
            });
        }
    }

    randr = randint(rowNum);
    randc = randint(colNum);
    let cell = maze[randr][randc];
    maze[randr][randc].visited = true;
    let queue = [];
    for (let i = 0; i < 4; i++) {
        queue.push(
            {
                x: randr,
                y: randc,
                side: i
            }
        )
    }
    while (queue.length > 0) {
        let indexWall = randint(queue.length);
        if (!help(queue[indexWall], size)) {
            if (queue[indexWall].side === 0 && !maze[queue[indexWall].x - 1][queue[indexWall].y].visited) {
                for (let i = 0; i < 4; i++) {
                    queue.push({
                        x: queue[indexWall].x - 1,
                        y: queue[indexWall].y,
                        side: i
                    })
                }
                maze[queue[indexWall].x - 1][queue[indexWall].y].visited = true;
                maze[queue[indexWall].x - 1][queue[indexWall].y].edges.s = maze[queue[indexWall].x][queue[indexWall].y];
                maze[queue[indexWall].x][queue[indexWall].y].edges.n = maze[queue[indexWall].x - 1][queue[indexWall].y];
            }
            else if (queue[indexWall].side === 1 && !maze[queue[indexWall].x][queue[indexWall].y + 1].visited) {
                for (let i = 0; i < 4; i++) {
                    queue.push({
                        x: queue[indexWall].x,
                        y: queue[indexWall].y + 1,
                        side: i
                    })
                }
                maze[queue[indexWall].x][queue[indexWall].y + 1].visited = true;
                maze[queue[indexWall].x][queue[indexWall].y + 1].edges.w = maze[queue[indexWall].x][queue[indexWall].y];
                maze[queue[indexWall].x][queue[indexWall].y].edges.e = maze[queue[indexWall].x][queue[indexWall].y + 1];
            }
            else if (queue[indexWall].side === 2 && !maze[queue[indexWall].x + 1][queue[indexWall].y].visited) {
                for (let i = 0; i < 4; i++) {
                    queue.push({
                        x: queue[indexWall].x + 1,
                        y: queue[indexWall].y,
                        side: i
                    })
                }
                maze[queue[indexWall].x + 1][queue[indexWall].y].visited = true;
                maze[queue[indexWall].x + 1][queue[indexWall].y].edges.n = maze[queue[indexWall].x][queue[indexWall].y];
                maze[queue[indexWall].x][queue[indexWall].y].edges.s = maze[queue[indexWall].x + 1][queue[indexWall].y];
            }
            else if (queue[indexWall].side === 3 && !maze[queue[indexWall].x][queue[indexWall].y - 1].visited) {
                for (let i = 0; i < 4; i++) {
                    queue.push({
                        x: queue[indexWall].x,
                        y: queue[indexWall].y - 1,
                        side: i
                    })
                }
                maze[queue[indexWall].x][queue[indexWall].y - 1].visited = true;
                maze[queue[indexWall].x][queue[indexWall].y - 1].edges.e = maze[queue[indexWall].x][queue[indexWall].y];
                maze[queue[indexWall].x][queue[indexWall].y].edges.w = maze[queue[indexWall].x][queue[indexWall].y - 1];
            }

        }
        queue.splice(indexWall, 1);
    }


    return maze;
};

function help(wall, size) {
    if (wall.y === 0 && wall.side == 3) {
        return true;
    }
    if (wall.y === size - 1 && wall.side == 1) {
        return true;
    }
    if (wall.x === size - 1 && wall.side == 2) {
        return true;
    }
    if (wall.x === 0 && wall.side == 0) {
        return true;
    }
    return false;
}



//     let queue = [];
//     queue.push(cell.edges);
//     let wall = ['n', 's', 'w', 'e'];
//     while (queue.length > 0) {
//         console.log(queue.length);
//         let r = randint(0, queue.length - 1);
//         let cur = queue[r];
//         queue.splice(r, 1);
//         if (cur.visited == true) {
//             continue;
//         }
//         if (cur.x + 1 < colNum) {
//             if (maze[cur.x + 1][cur.y].visited == false) {
//                 queue.push(maze[cur.x + 1][cur.y]);
//             }
//         }
//         if (cur.x - 1 >= 0) {
//             if (maze[cur.x - 1][cur.y].visited == false) {
//                 queue.push(maze[cur.x - 1][cur.y]);
//             }
//         }
//         if (cur.y + 1 < rowNum) {
//             if (maze[cur.x][cur.y + 1].visited == false) {
//                 queue.push(maze[cur.x][cur.y + 1]);
//             }
//         }
//         if (cur.y - 1 >= 0) {
//             if (maze[cur.x][cur.y - 1].visited == false) {
//                 queue.push(maze[cur.x][cur.y - 1]);
//             }
//         }

//         let rwall;
//         let redo = false;
//         do {
//             redo = false;
//             rwall = wall[randint(0, 3)];
//             if (rwall === 'n' && (cur.y - 1 < 0 && cur.edges.n == 'open' || beenVisited(cur.x, cur.y - 1,maze))) {
//                 redo = true;
//             }
//             if (rwall === 's' && (cur.y + 1 >= rowNum && cur.edges.s == 'open' || beenVisited(cur.x, cur.y + 1,maze))) {
//                 redo = true;
//             }
//             if (rwall === 'w' && (cur.x - 1 < 0 && cur.edges.w == 'open'|| beenVisited(cur.x-1, cur.y ,maze))) {
//                 redo = true;
//             }
//             if (rwall === 'e' && (cur.x + 1 >= colNum && cur.edges.e == 'open'|| beenVisited(cur.x+1, cur.y ,maze))) {
//                 redo = true;
//             }

//         }
//         while (redo)

//         //cur[rwall] ='open';

//         if (rwall === 'n') {
//             maze[cur.x][cur.y - 1].edges.s = 'open';
//             maze[cur.x][cur.y].edges.n = 'open';
//         }
//         if (rwall === 's') {
//             maze[cur.x][cur.y + 1].edges.n = 'open';
//             maze[cur.x][cur.y].edges.s = 'open';
//         }
//         if (rwall === 'w') {
//             maze[cur.x - 1][cur.y].edges.e = 'open';
//             maze[cur.x][cur.y].edges.w = 'open';
//         }
//         if (rwall === 'e') {
//             maze[cur.x + 1][cur.y].edges.w = 'open';
//             maze[cur.x][cur.y].edges.e = 'open';
//         }



//         cur.visited = true;

//     };

//     return maze;

// };

function randint(max) {
    return Math.floor(Math.random() * Math.floor(max));
}
// function beenVisited(x, y, maze) {
//     if (0 <= x && x < 10 && 0 <= y && y < 10) {
//         if (maze[x][y].visited == true) {
//             return false;
//         }
//         else {
//             return true;
//         }

//     }
//     return true;
// }





function findhint() {

    
    let fhit = [];

    
    if (myCharacter.location.edges.s ) {
        fhit.push(myCharacter.location.edges.s);
    }
    if (myCharacter.location.edges.e ) {
        fhit.push(myCharacter.location.edges.e);
    }
    if (myCharacter.location.edges.n) {
        fhit.push(myCharacter.location.edges.n);
    }
    if (myCharacter.location.edges.w ) {
        fhit.push(myCharacter.location.edges.w);
    }

    return fhit;
    
 
}
let presbread = false;
let hit;

function drawCell(cell) {

    if (imgFloor.isReady) {
        context.drawImage(imgFloor,
            cell.x * (1000 / size), cell.y * (1000 / size),
            1000 / size, 1000 / size);
    }

    if (cell.edges.n === null) {
        context.moveTo(cell.x * (1000 / size), cell.y * (1000 / size));
        context.lineTo((cell.x + 1) * (1000 / size), cell.y * (1000 / size));
        context.stroke();
    }

    if (cell.edges.s === null) {
        context.moveTo(cell.x * (1000 / size), (cell.y + 1) * (1000 / size));
        context.lineTo((cell.x + 1) * (1000 / size), (cell.y + 1) * (1000 / size));
        context.stroke();
    }

    if (cell.edges.e === null) {
        context.moveTo((cell.x + 1) * (1000 / size), cell.y * (1000 / size));
        context.lineTo((cell.x + 1) * (1000 / size), (cell.y + 1) * (1000 / size));
        context.stroke();
    }

    if (cell.edges.w === null) {
        context.moveTo(cell.x * (1000 / size), cell.y * (1000 / size));
        context.lineTo(cell.x * (1000 / size), (cell.y + 1) * (1000 / size));
        context.stroke();
    }
    if (cell.path === true && keypass === 0) {
        context.drawImage(myCharacter.image,
            cell.x * (1000 / size), cell.y * (1000 / size), 1000 / size, 1000 / size);
    }
    if (cell.bread === true && presbread === true && keybread === 0) {
        image = new Image();
        image.src = 'peach.png';
        context.drawImage(image,
            cell.x * (1000 / size) + (250 / size), cell.y * (1000 / size) + (250 / size), 500 / size, 500 / size);
    }
    if (keyhint === 0) {
        
        hit = findhint();
        //console.log(hit);

        image = new Image();
        image.src = 'apple.png';
        context.drawImage(image,
            hit[0].x * (1000 / size) + (250 / size), hit[0].y * (1000 / size) + (250 / size), 500 / size, 500 / size);
            if(hit[1]){
        context.drawImage(image, hit[1].x * (1000 / size) + (250 / size), hit[1].y * (1000 / size) + (250 / size), 500 / size, 500 / size);
            }
            if(hit[2]){
        context.drawImage(image, hit[2].x * (1000 / size) + (250 / size), hit[2].y * (1000 / size) + (250 / size), 500 / size, 500 / size);
            }
            if(hit[3]){
        context.drawImage(image, hit[3].x * (1000 / size) + (250 / size), hit[3].y * (1000 / size) + (250 / size), 500 / size, 500 / size);
            }

    }


}

function renderCharacter(character) {
    if (character.image.isReady) {
        context.drawImage(character.image,
            character.location.x * (1000 / size), character.location.y * (1000 / size), 1000 / size, 1000 / size);
    }

}
let score = 0;

function moveCharacter(keyCode, character) {
    console.log('keyCode: ', keyCode);


    myCharacter.location.bread = true;
    if (keyCode === 40) {
        if (character.location.edges.s) {
            character.location = character.location.edges.s;
            if (myCharacter.location.path === true) {
                score += 5;

                myCharacter.location.path = false;
            }
            else {
                score -= 2;
            }
        }
    }
    if (keyCode == 38) {
        if (character.location.edges.n) {
            character.location = character.location.edges.n;
            if (myCharacter.location.path === true) {
                score += 5;
                myCharacter.location.path = false;
            }
            else {
                score -= 2;
            }
        }
    }
    if (keyCode == 39) {
        if (character.location.edges.e) {
            character.location = character.location.edges.e;
            if (myCharacter.location.path === true) {
                score += 5;
                myCharacter.location.path = false;
            }
            else {
                score -= 2;
            }
        }
    }
    if (keyCode == 37) {
        if (character.location.edges.w) {
            character.location = character.location.edges.w;
            if (myCharacter.location.path === true) {
                score += 5;
                myCharacter.location.path = false;
            }
            else {
                score -= 2;
            }
        }
    }

}


let keypass = 1;
function showpass(keyCode) {
    if (keyCode === 80) {
        if (keypass == 1) {
            keypass = 0;
        }
        else if (keypass == 0) {
            keypass = 1;
        }

        clearVisited(maze);

        ShortPass(myCharacter.location);
        if (myCharacter.location.path === true) {
            myCharacter.location.path = false;
        }
    }
}
let keybread = 1;
function showbread(keyCode) {
    if (keyCode === 66) {
        if (keybread == 1) {
            keybread = 0;
        }
        else if (keybread == 0) {
            keybread = 1;
        }

        presbread = true;
    }
}
let keyscore = 1;
function showscore(keycode) {
    if (keycode === 89) {
        if (keyscore == 1) {
            keyscore = 0;
        }
        else if (keyscore == 0) {
            keyscore = 1;
        }
    }
}

let keyhint = 1;

function showshint(keycode) {
    if (keycode === 72) {
        if (keyhint == 1) {
            keyhint = 0;
        }
        else if (keyhint == 0) {
            keyhint = 1;
        }

    }
}





function renderMaze() {
    context.strokeStyle = 'rgb(255, 255, 255)';
    context.lineWidth = 6;

    for (let row = 0; row < size; row++) {
        for (let col = 0; col < size; col++) {
            drawCell(maze[row][col]);
        }
    }

    context.beginPath();
    context.moveTo(0, 0);
    context.lineTo(999, 0);
    context.lineTo(999, 999);
    context.lineTo(0, 999);
    context.closePath();
    context.strokeStyle = 'rgb(0, 0, 0)';
    context.stroke();
}

function render() {
    context.clear();
    var num = totalTime / 1000;
    var n = num.toFixed();

    if (keyscore === 0) {

        document.getElementById("score").innerHTML = "score : " + score;
    }
    else {
        document.getElementById("score").innerHTML = "score : Hidden";
    }
    document.getElementById("time").innerHTML = "time : " + n + "s";
    renderMaze();
    renderCharacter(myCharacter);
    renderCharacter(rabbit);
}

function processInput() {
    for (input in inputStage) {
        moveCharacter(inputStage[input], myCharacter);
        showpass(inputStage[input]);
        showbread(inputStage[input]);
        showscore(inputStage[input]);
        showshint(inputStage[input]);
    }
    inputStage = {};
}

function update(elapsedTime) {
    totalTime += elapsedTime;


}

//  function nao1(){
//      keeppath = HintPass(myCharacter.location);
//  console.log("dsjfosjfois");
//  console.log(keeppath);
//  }

function gameLoop() {
    let currentTime = performance.now();
    let elapsedTime = currentTime - previousTime;
    previousTime = currentTime;

    update(elapsedTime);
    render(elapsedTime);

    processInput();
    render();

    requestAnimationFrame(gameLoop);

}

let canvas = null;
let context = null;
creatmaze();
clearVisited(maze);
ShortPass(maze[0][0]);
//HintPass(maze[0][0]);
console.log(keeppath);
var myCharacter = createCharacter('character.png', maze[0][0]);

var rabbit = createCharacter('rabbit.png', maze[size - 1][size - 1]);
//nao1();
function initialize() {
    canvas = document.getElementById('canvas-main');
    context = canvas.getContext('2d');
    //buttonPressed();
    //start();
    CanvasRenderingContext2D.prototype.clear = function () {
        this.save();
        this.setTransform(1, 0, 0, 1, 0, 0);
        this.clearRect(0, 0, canvas.width, canvas.height);
        this.restore();
    };

    window.addEventListener('keydown', function (event) {
        //moveCharacter(event.keyCode, myCharacter);
        inputStage[event.keyCode] = event.keyCode;
    });
    //creatmaze();
    // clearVisited(maze);
    //ShortPass(maze[0][0]);
    //HintPass(maze[0][0]);
    requestAnimationFrame(gameLoop);
}
