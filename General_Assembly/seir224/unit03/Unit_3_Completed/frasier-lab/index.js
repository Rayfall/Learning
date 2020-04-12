/*// Dependencies
const express = require('express');
const app = express();

// listen for when someone goes to
// localhost:3000/
// upon getting a request at that URL
// send text 'Hello World'

// Routes
app.get('/', (req, res) => {
  console.log("Oh hey! I got a request. Let me respond with something");
  res.send('Hello World!');
});

app.get('/somedata', (request, response)=>{
  // console.log('response: ', response);
  // console.log('===================');
  response.send('here is your information');
});

// App Listen
app.listen(3000, ()=> {
  console.log("I am listening for requests!!!");
});*/
const express = require('express');
const app = express();

// Routes
app.get('/frasier', (req, res) => {
    console.log("Oh hey! I got a request. Let me respond with something");
    res.send("'Once in prep school, the Existentialist Club once named me 'Most Likely to Be'");
});

app.get('/niles', (request, response)=>{
    response.send("You know, sometimes I wonder if I'm not just in psychiatry for the money");
});

app.get('/daphne', (request, response)=>{
    response.send("Well, have fun. I'm off to stick my head in the oven.");
});

app.get('/roz', (request, response)=>{
    response.send("Let me make it easy for you. Freaks! Freaks on line 1. Freaks on line 2! Freaks! Everywhere!");
});

app.get('/martin', (request, response)=>{
    response.send("You may think it's tough being middle-aged, but think about me. I got a son who's middle-aged.");
});

app.get('/scrappy', (request, response)=>{
    response.send("woof");
});

// App Listen
app.listen(3000, ()=> {
    console.log("I am listening for requests!!!");
});