function ParticleSystem(spec, graphics) {
	let that = {};
	let particles = [];
//	let image = new Image();
//	image.onload = function () {
	that.render = function() {
		for (let particle = 0; particle < particles.length; particle++) {
			if (particles[particle].alive >= 100) {
				let box = {
					height: particles[particle].size,
					width: particles[particle].size,
					location: {
						x: particles[particle].position.x,
						y: particles[particle].position.y
					},
					color: '#42f46e',
				
				};
				graphics.drawrect(box);
			}
		}
	};	
	//};
	//image.src = spec.image;

	that.update = function(elapsedTime) {
		let keepMe = [];

		for (let particle = 0; particle < particles.length; particle++) {
			particles[particle].alive += elapsedTime;
			particles[particle].position.x += (elapsedTime * particles[particle].speed * particles[particle].direction.x);
			particles[particle].position.y += (elapsedTime * particles[particle].speed * particles[particle].direction.y);
			particles[particle].rotation += particles[particle].speed / .5;

			if (particles[particle].alive <= particles[particle].lifetime) {
				keepMe.push(particles[particle]);
			}
		}
		
		
		particles = keepMe;
	};
	for (let particle = 0; particle < 30; particle ++) {
		for (var i = 0 ; i <3 ; i++){
		let p = {
			position: { x: spec.position.x + 68/4 * (i+1), y: spec.position.y },
			direction: Random.nextCircleVector(),
			speed: Random.nextGaussian( spec.speed.mean, spec.speed.stdev ),	// pixels per millisecond
			rotation: 0,
			lifetime: Random.nextGaussian(spec.lifetime.mean, spec.lifetime.stdev),	// milliseconds
			alive: 0,
			size: Random.nextGaussian(spec.size.mean, spec.size.stdev),
			fill: spec.fill,
			stroke: 'rgb(0, 0, 0)'
		};

		particles.push(p);
	}
	}

	// that.render = function() {};

	return that;
}
