MyGame.RenderEngine = (function(globals, graphicsEngine, particleEngine, bricksEngine){
    function showScore(){
    };

    function showTime(elapsedtime){
    };

    function clear(){
        graphicsEngine.clear();
    };

    //--------------------------------------------------------
    //
    //  Call things to render here
    //
    //--------------------------------------------------------
    function renderGameState(){
        graphicsEngine.drawGame(bricksEngine.grid);   
        particleEngine.render();     
    };

    function initialize(){
        graphicsEngine.initialize();
    };

    return{
        showScore: showScore,
        showTime, showTime,
        clear: clear,
        renderGameState: renderGameState,
        initialize: initialize
    };
})(MyGame.Globals, MyGame.GraphicsEngine, MyGame.ParticleEngine, MyGame.BricksEngine);