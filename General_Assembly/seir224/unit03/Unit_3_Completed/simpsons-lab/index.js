const express = require('express');
const app = express();

app.get('/', (req, res) => {
    console.log("Oh hey! I got a request. Let me respond with something");
    res.send("Hello World!");
});

app.get('/Homer', (req, res) => {
    res.send("Test!");
});

app.get('/Marge', (req, res) => {
    res.send("Test!");
});

app.get('/Bart', (req, res) => {
    res.send("Test!");
});

app.get('/Lisa', (req, res) => {
    res.send("Test!");
});

app.get('/Maggie', (req, res) => {
    res.send("Test!");
});

app.get('/Snowball-2', (req, res) => {
    res.send("Test!");
});

app.get('/Santas-little-helper', (req, res) => {
    res.send("Test!");
});
// App Listen
app.listen(3000, ()=> {
    console.log("I am listening for requests!!!");
});