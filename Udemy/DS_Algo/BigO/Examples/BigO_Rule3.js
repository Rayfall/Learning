function compressBoxesTwice(boxes, boxes2) {
    boxes.forEach(function(boxes) {
        console.log(boxes);
    });

    boxes2.forEach(function(boxes) {
        console.log(boxes);
    });
}

// O(a + b)

// Log all pairs of array
const boxes = [1,2,3,4,5];

function logAllPairsOfArray(array) {
    for(let i = 0; i < array.length; i++) {
        for(let j = 0; j < array.length; j++) {
            console.log(array[i], array[j]);
        }
    }
}

logAllPairsOfArray(boxes);

// O(n^2)