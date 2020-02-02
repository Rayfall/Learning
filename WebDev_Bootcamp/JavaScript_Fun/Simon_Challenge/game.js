"use strict";

var buttonColors = ["red","blue","green","yellow"];

var gamePattern = [];
var userClickedPattern = [];

$(".btn").on("click", function(e) {
    var userChosenColor = $(this).attr("id");
    userClickedPattern.push(userChosenColor);
    playSound(userChosenColor);
});

function nextSequence() {
    var randomNumber = Math.floor((Math.random()*4));
    
    var randomChosenColor = buttonColors[randomNumber];

    gamePattern.push(randomChosenColor);

    $("#" + randomChosenColor).fadeOut(100).fadeIn(100);
    
    playSound(randomChosenColor);
}

function playSound(name) {
    var audio = new Audio("sounds/" + name + ".mp3");
    audio.play();
}


nextSequence();