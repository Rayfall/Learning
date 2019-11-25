"use script";


alert("Hello World!");

var myName = "Andrew";
alert("My name is: " + myName);

var yourName = prompt("What is your name?");
alert("Nice to meet you, " + yourName + "!");


myName.slice(0,1);
myName.toUpperCase();
myName.toLowerCase();

myName.slice(2,4).toUpperCase();

var newName = myName.slice(0,1).toUpperCase() + myName.slice(1,myName.length).toLowerCase();