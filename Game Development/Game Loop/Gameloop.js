let previousTime = performance.now();
let events = [];
let inputAvailable = false;
let print = [];

function buttonPressed() {

    inputAvailable = true;
}



function processInput(elapsedTime) {
    if (inputAvailable) {
        let inputName = document.getElementById('id-name').value;
        let inputInterval = document.getElementById('id-interval').value;
        let inputTime = document.getElementById('id-time').value;
        inputAvailable = false;
        eventTime(inputName, inputInterval, inputTime);
        //console.log('the input contained: ', events[0].name );
        //console.log('the input contained: ', events[0].interval);
        //console.log('the input contained: ', events[0].time);

    }
}
function eventTime(name, interval, time) {
    event = {
        name: name,
        interval: interval,
        time: time,
        count: 0
    }

    events.push(event);
}

function update(elapsedTime) {
    print=[];
    for (i = 0; i < events.length; i++) {
        if (events[i].time <= 0) {
             events.splice(i,1);
        }
        else {
            events[i].count += elapsedTime;
            if (events[i].count >= events[i].interval) {
                events[i].count -= events[i].interval;
                events[i].time--;
                print.push(events[i]);
            }
        }
    }
}


function render(elapsedTime) {
    for (i = 0; i < print.length; i++) {
        let e = document.createElement("p");
        e.innerHTML= 'Event: '+ print[i].name + ' (' + print[i].time + ' remaining)';
        document.getElementById('output').appendChild(e);
    }
    document.getElementById('output').scrollTop =  document.getElementById('output').scrollHeight;
   

}

function gameloop(currentTime) {
    let elapsedTime = currentTime - previousTime;
    previousTime = currentTime;

    processInput();
    update(elapsedTime);
    render(elapsedTime);
    let quit = false;
    if (!quit) {
        requestAnimationFrame(gameloop);
    }
}
window.onload = gameloop;