//jshint esversion:6

const express = require("express");
const bodyParser = require("body-parser");
const port = 3000;
const app = express();

let items = [];

app.use(bodyParser.urlencoded({extended: true}));
app.set('view engine', 'ejs');
app.use(express.static("public"));

app.get("/", function(req, res){
    let options = {weekday:'long',day:'numeric',month:'long'};    
    let today = new Date();
    let currentDay = today.toLocaleDateString("en-US", options);
    
    /*let day = "";
    switch(currentDay) {
        case 0: day = "Sunday";
        break;
        case 1: day = "Monday";
        break;
        case 2: day = "Tuesday";
        break;
        case 3: day = "Wednesday";
        break;
        case 4: day = "Thursday";
        break;
        case 5: day = "Friday";
        break;
        case 6: day = "Saturday";
        break;
        default: console.log("Error: Current day is equal to " + currentDay);
        break;
    }*/    

    /*if(currentDay === 6 || currentDay === 0) {
        day = "weekend";
        //res.send("Yay it's the weekend!");
        //res.sendFile(__dirname + "/index.html");
        
    }
    else {
        day = "weekday";
        //res.send("Boo! I have to work");
        //res.write() can write multiple messages and then use res.send() at the end.
        res.render('list', {kindOfDay: day});
    }*/

    res.render('list', {kindOfDay: currentDay, newListItems: items});
});

app.post("/", function(req, res){
    let item = req.body.newItem;
    console.log(item);

    items.push(item);

    res.redirect("/");
    //res.render('list', {newListItem: item});
});

app.listen(port, function(){
    console.log("Listening in on port " + port);
});