"use strict";

var buttonColors = ["red","blue","green","yellow"];

var gamePattern = [];
var userClickedPattern = [];
var level = 0;
var start = false;

$(document).on("keydown",function(e) {
    if(e.which == 13) {
        if(start === false){
            //alert('You pressed enter!');
            nextSequence();
            start = true;
        }        
    }
});

$(".btn").on("click", function(e) {
    var userChosenColor = $(this).attr("id");
    userClickedPattern.push(userChosenColor);
    playSound(userChosenColor);
    //$("#" + userChosenColor).addClass("pressed").delay(1000).removeClass("pressed");
    animateButton(userChosenColor);
    checkAnswer(userClickedPattern[userClickedPattern.length - 1]);
});

function nextSequence() {
    var randomNumber = Math.floor((Math.random()*4));
    
    var randomChosenColor = buttonColors[randomNumber];

    gamePattern.push(randomChosenColor);

    level++;
    $("#level-title").html("Level " + level);

    $("#" + randomChosenColor).fadeOut(100).fadeIn(100);

    playSound(randomChosenColor);
}

function playSound(name) {
    var audio = new Audio("sounds/" + name + ".mp3");
    audio.play();
}

function animateButton(currentColor) {
    $("#" + currentColor).addClass("pressed");
    setTimeout(function() {
        $("#" + currentColor).removeClass("pressed");
    }, 100);
}

function checkAnswer(currentLevel) {
    if(currentLevel != gamePattern[gamePattern.length - 1]){
        console.log("Wrong");
        reset();
    }
    else {
        //console.log("Correct");
        setTimeout(function() {
            nextSequence();
        }, 1000);
        userClickedPattern = [];
    }
}

function reset() {
    console.log("reset phase");
    var audio = new Audio("sounds/wrong.mp3");
    audio.play();
    $("body").addClass("game-over");
    setTimeout(function() {
        $("body").removeClass("game-over");
    }, 200);
    $("#level-title").html("Game Over, Press Enter to Restart");
    level = 0;
    start = false;
    userClickedPattern = [];
    gamePattern = [];
}