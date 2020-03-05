console.log("Up and Running!");

const cards = [
{
    rank: "queen",
    suit: "hearts",
    cardImage: "images/queen-of-hearts.png"
 },
 {
     rank: "queen",
     suit: "diamonds",
     cardImage: "images/queen-of-diamonds.png"
 },
 {
    rank: "king",
    suit: "hearts",
    cardImage: "images/king-of-hearts.png"
},
{
    rank: "king",
    suit: "diamonds",
    cardImage: "images/king-of-diamonds.png"
}];
const cardsInPlay = [];
let cardElement = [];

function checkForMatch() {
    if(cardsInPlay[0] === cardsInPlay[1]) {
        alert("You found a match!");
        //$("#message").text("You found a match").css("display", "block");
        //$("#game-board").css("opacity", "0.3");

    }
    else {
        alert("Sorry, try again.");
        //$("#message").text("Sorry, not a match").css("display", "block");
        //$("#game-board").css("opacity", "0.3");
    }
}

function flipCard() {
    let cardId = this.getAttribute("data-id");
    console.log("User flipped: " + cards[cardId].rank);
    console.log("User flipped: " + cards[cardId].suit);
    console.log("User flipped: " + cards[cardId].cardImage);
    cardsInPlay.push(cards[cardId].rank);

    this.setAttribute("src", cards[cardId].cardImage);
    if(cardsInPlay.length === 2) {
        checkForMatch();

    }
}

function createBoard() {
    for(let i = 0; i < cards.length; i++) {
        cardElement = document.createElement("img");
        cardElement.setAttribute("src", "images/back.png");
        cardElement.setAttribute("data-id", i);
        cardElement.addEventListener("click", flipCard);
        document.getElementById("game-board").appendChild(cardElement);

        //cardElement = new $("<img>").attr("src", "images/back.png").attr("data-id", i).on("click", flipCard);
        //$("#game-board").append(cardElement);
    }
}

createBoard();