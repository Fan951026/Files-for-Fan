MyGame.BricksEngine = (function(globals){
    
    function brickMaker(){
        that = {
        alive: true,
        x: 0,
        y: 0,
        w: 0,//map width px
        h: 0,//map hight px
        cx: 0,
        cy: 0,
        occupied: 'none',
        upgrade: 0,
        showBorder: false,
        visited: false,
        damage: 0,
        towerName: 'none',
        distTtB: -1,
        distLtR: -1,
        rotation: 0,
        rotationRate: 6 * 3.14159 / 1000,
        firingRate: 0,
        firingTime: 0,
        flipme: false,
        firing: false,
        attacks: 'ground'
        };

        return that;
    };

    let grid = {
        bricks: [],
        col: 20,
        row: 20,
        width: 1000,
        height: 1000,
       // baseHeight: 223,
       // space: 2,
        color: ''
    };

    function rowColor(r,c){
      
    



        switch (r%2) {
         
            case 1://odd
            if(c%2 == 1){
                return 'rgb(237, 230, 220)';
            }else{
                return 'rgb(205, 216, 201)';
            }
               
            break;


            case 0://even
            if(c%2 == 0){
                return 'rgb(237, 230, 220)';
            }
            else{
                return 'rgb(205, 216, 201)';
            }
            break;


            default:
            console.log("brickEngine: rowColor: Invalid Row");
        }
       
    };

   

    function initialize(){
        grid.bricks = [];
        for(var r = 0; r < grid.row; r++){
            grid.bricks.push([]);
            for(var c = 0; c < grid.col; c++){
                var temp = brickMaker();
                temp.w = grid.width/grid.col;
                temp.h = grid.height/grid.row;
                temp.x = c * temp.w;
                temp.y = r * temp.h;
                temp.cx = temp.x + temp.w/2;
                temp.cy = temp.y + temp.h/2;
                temp.color = rowColor(r,c);
                if(r == 0 || r == 19 || c == 0 || c == 19){
                    temp.occupied = 'border';
                } else {
                    temp.occupied = 'none';
                }

                grid.bricks[r].push(temp);
             
            }
        }

        grid.bricks[8][0].occupied = grid.bricks[9][0].occupied = grid.bricks[10][0].occupied = grid.bricks[11][0].occupied =
        grid.bricks[8][19].occupied = grid.bricks[9][19].occupied = grid.bricks[10][19].occupied = grid.bricks[11][19].occupied = 
        grid.bricks[0][8].occupied = grid.bricks[0][9].occupied = grid.bricks[0][10].occupied = grid.bricks[0][11].occupied =
        grid.bricks[19][8].occupied = grid.bricks[19][9].occupied = grid.bricks[19][10].occupied = grid.bricks[19][11].occupied = 'none';
    };

    return {
        initialize: initialize,
        grid: grid
    };
    
})(MyGame.Globals);