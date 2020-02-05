const express = require("express");
const app = express();


//req = request, res = response
app.get("/", function(req, res){
    console.log(req);
    //res.send("Hello!");
    res.send("<h1>Hello, World!</h1>");
});

app.get("/contact", function(req, res){
    res.send("Contact me at: atgrant23@gmail.com");
});

app.get("/about", function(req,res){
    res.send("<h1>Hello, I'm Andrew!</h1>" + 
             "<p>I am a snowboarder</p>");
});

app.listen(3000, function(){
    console.log("Server started on port 3000");
});