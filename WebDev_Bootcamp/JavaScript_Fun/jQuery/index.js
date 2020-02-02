/*
$(document).ready(function() {
    $("h1").css("color","red");
});
*/

//$("h1").css("color","red");


$(document).keydown(function(event){
    $("h1").html(event.key);
});
