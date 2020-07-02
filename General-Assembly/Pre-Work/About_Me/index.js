var dissappearingH1 = document.querySelector("h1");
dissappearingH1.innerHTML = "(Press A, S, or D)";

document.addEventListener("keydown", function (event) {
    dissappearingH1.innerHTML = "Andrew Grant | Aspiring Developer";
    changeOpacity(event.key);
});

function changeOpacity(key) {
    switch (key) {
        case "a":
            dissappearingH1.style.opacity = "1";
            break;
        case "s":
            dissappearingH1.style.opacity = ".5";
            break;
        case "d":
            dissappearingH1.style.opacity = "0";
            break;
        default: console.log(key);
            break;
    }

}
