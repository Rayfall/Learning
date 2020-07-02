"use strict";

function handleClick() {
    var buttonInnerHTML = this.innerHTML;
    makeSound(buttonInnerHTML);
    buttonAnimation(buttonInnerHTML);
 }

document.addEventListener("keydown", function (event) {
    makeSound(event.key);
    buttonAnimation(event.key);
});

function buttonAnimation(currentKey) {
    var activeButton = document.querySelector("." + currentKey);
    activeButton.classList.add("pressed");
    setTimeout(function(){ activeButton.classList.remove("pressed");}, 100);
}

function makeSound(key) {
    switch (key) {
        case "w":
            var tom1 = new Audio('sounds/tom-1.mp3');
            tom1.play();
            break;
        case "a":
            var tom2 = new Audio('sounds/tom-2.mp3');
            tom2.play();
            break;
        case "s":
            var tom3 = new Audio('sounds/tom-3.mp3');
            tom3.play();
            break;
        case "d":
            var tom4 = new Audio('sounds/tom-4.mp3');
            tom4.play();
            break;
        case "j":
            var snare = new Audio('sounds/snare.mp3');
            snare.play();
            break;
        case "k":
            var crash = new Audio('sounds/crash.mp3');
            crash.play();
            break;
        case "l":
            var kick = new Audio('sounds/kick-bass.mp3');
            kick.play();
            break;
        default: console.log(key);
            break;
    }

}

// document.querySelector("button").addEventListener("click", handleClick); //First way to do this


/*document.querySelector("button").addEventListener("click", function () {
    alert("I got clicked!");
});*/ //Another way of doing this same function.

for(var i = 0; i < document.querySelectorAll(".drum").length; i++){
    document.querySelectorAll(".drum")[i].addEventListener("click", handleClick);
}

//Challenge in Video 149
/*
function add(num1, num2) {
    return num1 + num2;
}
function subtract(num1, num2) {
    return abs(num1 - num2);
}
function multiply(num1, num2) {
    return num1 * num2;
}
function divide(num1, num2) {
    return num1 / num2;
}

function calculator(num1, num2, operator){
    return operator(num1,num2);
}
*/


/* Challenge in Video 152
--------------------------------------------------------------
var houseKeeper1 = {
    name: "Gloria",
    age: 43,
    yearsWorkingExperience: 10,
    cleaningPreference: ["bathroom", "lobby", "bedroom"]
};

function HouseKeeper(name, age, yearsWorkingExperience, cleaningPreference) {
    this.name = name;
    this.age = age;
    this.yearsWorkingExperience = yearsWorkingExperience;
    this.cleaningPreference = cleaningPreference;

    //-------------------------------------------------------
    this.clean = function () {
        alert("Cleaning in progress...");
    }
}
var houseKeeper2 = new HouseKeeper("Ria", 43, 10, ["bathroom","lobby","bedroom"]);
houseKeeper2.clean();
--------------------------------------------------------------

var bellboy1 = {
    name: "Timothy",
    age: 19,
    hasWorkPermit: true,
    languages: ["English","German","Spanish"]
};

function BellBoy (name, age, hasWorkPermit, languages) {
    this.name = name;
    this.age = age;
    this.hasWorkPermit = hasWorkPermit;
    this.languages = languages;
} //This is a constructor function, also denoted by the capitolized letters of the function.
var bellboy2 = new BellBoy("Timmy", 19, true, ["French", "Spanish", "English"]);
*/