MyGame.ParticleEngine = (function(randomEngine, graphicsEngine){
    
    //--------------------------------------------------------
    //
    //  Make particle widgets and push them here
    //
    // --------------------------------------------------------
    let particleWidgetsList = [];
    let elapsedtime;
    function setET(et) {elapsedtime = et;};

    //--------------------------------------------------------
    //
    //      Contains the information for every particle
    //
    //--------------------------------------------------------
    function particleMaker(){
        let that = {
            cx: 0,
            cy: 0,
            w: 0,
            h: 0,
            x: function(){
                return this.cx - this.w/2;
            },
            y: function(){
                return this.cy - this.h/2;
            },
            r: 0,
            g: 0,
            b: 0,
            a: 0,
            alive: true,
            lifetime: 0, //ms
            xSpeed: 0,
            ySpeed: 0,
            rotation: 0,
            image: false
        };
        
        return that;
    };

    //--------------------------------------------------------
    //
    //  Example function
    //
    //--------------------------------------------------------
    function createStarScreen(specs){
        let that = {
            cx: specs.cx,
            cy: specs.cy,
            w: specs.w,
            h: specs.h,
            x: function(){return this.cx - this.w/2;},
            y: function(){return this.cy - this.h/2;},
            particles: [],
            sizeMin: specs.sizeMin,
            sizeMax: specs.sizeMax,
            w_margin: specs.w_margin,
            h_margin: specs.h_margin,
            mean: specs.mean,
            stddev: specs.stddev,
            sizeDev: specs.sizeDev,
            restInt: specs.restInt,
            restTime: 0,
            speedMin: specs.speedMin,
            speedMax: specs.speedMax,
            created: false,
            alive: true
        }

        that.create = function(){
            particle = particleMaker();
            var thisRound = Math.ceil(randomEngine.nextGaussian(this.mean, this.stddev));

            for(var i = 0; i < thisRound; i++){
                particle.cx = randomEngine.nextRange(this.w_margin, this.w - this.w_margin) + this.x();
                particle.cy = randomEngine.nextRange(this.h_margin, this.h - this.h_margin) + this.y();
                particle.w = randomEngine.nextGaussian(this.sizeMax, this.sizeMax*this.sizeDev);
                particle.h = randomEngine.nextGaussian(this.sizeMin, this.sizeMax*this.sizeDev);

                switch (randomEngine.nextRange(0,3)){
                    case 0:
                        particle.r = 255;
                        particle.g = 0;
                        particle.b = 0;
                        particle.a = randomEngine.nextDouble();
                    break;

                    case 1:
                        particle.r = 225;
                        particle.g = 215;
                        particle.b = 0;
                        particle.a = randomEngine.nextDouble();
                    break;

                    case 2:
                        particle.r = 255;
                        particle.g = 20;
                        particle.b = 147;
                        particle.a = randomEngine.nextDouble();
                    break;

                    case 3:
                        particle.r = 255;
                        particle.g = 255;
                        particle.b = 255;
                        particle.a = randomEngine.nextDouble();
                    break;

                    default:
                        console.log("Star Screen Invalid Particle Color");
                }

                particle.lifetime = (1000/specs.speedMin) * 1100;
                particle.xSpeed = randomEngine.nextRange(specs.speedMin,specs.speedMax);
                particle.ySpeed = 0;
                particle.rotation = (randomEngine.nextDouble() * 7) % 2*Math.PI;
            
                this.particles.push(particle);
            }
            this.created = true;
        };

        that.update = function(){
            this.restTime += elapsedtime;
            if(this.restTime > this.restInt || !this.created){
                this.create();
                this.restTime = 0;
            }

            for(var i = 0; i < this.particles.length; i++){
                this.particles[i].cx += this.particles[i].xSpeed/1000 * elapsedtime;
                this.particles[i].cy += this.particles[i].ySpeed/1000 * elapsedtime;

                this.particles[i].lifetime -= elapsedtime;
                if(this.particles[i].lifetime < 0 || (this.particles[i].cx > 1100)){
                    this.particles[i].alive = false;
                }
            }

            for(var i = 0; i< this.particles.length; i++){
                if(!this.particles[i].alive){
                    this.particles.splice(i, 1);
                }
            }
        };

        that.render = function(){
            for(var i = 0; i < this.particles.length; i++){
                graphicsEngine.drawStarParticle(this.particles[i]);
            }
        }

        particleWidgetsList.push(that);

        return;
    };

    function damageEnemy(specs){
        let that = {
            cx: specs.cx,
            cy: specs.cy,
            w: specs.w,
            h: specs.h,
            x: function(){return this.cx - this.w/2;},
            y: function(){return this.cy - this.h/2;},
            particles: [],
            sizeMin: specs.sizeMin,
            sizeMax: specs.sizeMax,
            mean: specs.mean,
            stddev: specs.stddev,
            sizeDev: specs.sizeDev,
            restInt: specs.restInt,
            restTime: 0,
            speedMin: specs.speedMin,
            speedMax: specs.speedMax,
            created: false,
            alive: true
        }

        that.create = function(){
            particle = particleMaker();
            var thisRound = randomEngine.nextRange(8, 15);

            for(var i = 0; i < thisRound; i++){
                particle.cx = randomEngine.nextRange(this.x(), this.x() + this.w);
                particle.cy = randomEngine.nextRange(this.y(), this.y() + this.h);
                particle.w = 8;//randomEngine.nextGaussian(this.sizeMax, this.sizeMax*this.sizeDev);
                particle.h = 5;//randomEngine.nextGaussian(this.sizeMin, this.sizeMax*this.sizeDev);
                particle.radius = randomEngine.nextRange(specs.sizeMin, specs.sizeMax);
                particle.r = 255;
                particle.g = 0;
                particle.b = 0;                        
                particle.a = randomEngine.nextDouble();

                particle.lifetime = 1000;
                particle.xSpeed = randomEngine.nextRange(specs.speedMin,specs.speedMax);
                if(randomEngine.nextRange(0,1) > 0) particle.xSpeed *= -1;
                particle.ySpeed = randomEngine.nextRange(specs.speedMin,specs.speedMax);
                if(randomEngine.nextRange(0,1) > 0) particle.ySpeed *= -1;
                particle.rotation = (randomEngine.nextDouble() * 7) % 2*Math.PI;

                this.particles.push(particle);
            }
            this.created = true;
        };

        that.update = function(){
            if(!this.created){
                this.create();
            }

            for(var i = 0; i < this.particles.length; i++){
                this.particles[i].cx += this.particles[i].xSpeed/1000 * elapsedtime;
                this.particles[i].cy += this.particles[i].ySpeed/1000 * elapsedtime;

                this.particles[i].lifetime -= elapsedtime;
                if(this.particles[i].lifetime < 0 || (this.particles[i].cx > 1100)){
                    this.particles[i].alive = false;
                }
            }

            for(var i = 0; i< this.particles.length; i++){
                if(!this.particles[i].alive){
                    this.particles.splice(i, 1);
                }
            }
        };

        that.render = function(){
            for(var i = 0; i < this.particles.length; i++){
                graphicsEngine.drawStarParticle(this.particles[i]);
            }
        }

        particleWidgetsList.push(that);

        return;
    };

    //--------------------------------------------------------
    //
    //  All particle effects need an update which is called here
    //
    //--------------------------------------------------------
    function update(){
        for(var i = 0; i < particleWidgetsList.length; i++){
            particleWidgetsList[i].update();
            if(particleWidgetsList[i].particles.length <= 0) particleWidgetsList[i].alive = false;
        }
        for(var i = 0; i < particleWidgetsList.length; i++){
            if(!particleWidgetsList[i].alive){
                particleWidgetsList.splice(i, 1);
            }
        }
    };

    function render(){
        for(var i = 0; i < particleWidgetsList.length; i++){
            particleWidgetsList[i].render();
        }
    };

    function clear(){
        particleWidgetsList = [];
    }

    return{
        setET: setET,
        update: update,
        render: render,
        createStarScreen: createStarScreen,
        damageEnemy: damageEnemy,
        particleWidgetsList: particleWidgetsList,
        clear: clear
    }
})(MyGame.RandomEngine, MyGame.GraphicsEngine);