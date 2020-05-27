"Use strict";
//Full documentation on PIXI.Application settings can be found at: http://pixijs.download/release/docs/PIXI.Application.html
let app = new PIXI.Application({
    width:300, 
    height:400,
    antialias: true,
    transparent: false,
    resolution: 1
});

//Aliases
let Application = PIXI.Application,
    loader = PIXI.loader,
    resources = PIXI.loader.resources,
    Sprite = PIXI.Sprite;



app.renderer.backgroundColor = 0x007FFF;

/*app.renderer.view.style.position = "absolute";                //Fixed Window position.
app.renderer.view.style.display = "block";                      //CSS Display style.
app.renderer.autoResize = true;                                 //Resize the canvas with the broser.
app.renderer.resize(window.innerWidth, window.innerHeight);*/  //Set the width and height.

document.body.appendChild(app.view);

loader
.add("media/hub_mega.png")
.on("progress", loadProgressHandler)                            //Progress handler
.load(setup);

function loadProgressHandler() {
    console.log("loading...");
}

function setup() {
    let mega = new PIXI.Sprite(PIXI.loader.resources["media/hub_mega.png"].texture);
    /*mega.x = -50;
    mega.y = 65;*/                                              //Individual Positioning.
    mega.position.set(-50,65);
    /*mega.scale.x = 0.5;
    mega.scale.y = 0.5;*/                                       //Individual Image Scaling.

    //let mega_title = new Text("Hub MegaMan.EXE");
    //mega_title.position.set(25,25);

    //app.stage.addChild(mega_title);
    app.stage.addChild(mega);
    mega.visible = true;
}
