// What is the Big O of the below function? (Hint, you may want to go line by line)
function funChallenge(input) {
    let a = 10;     // a = 10 - O(1)
    a = 50 + 3;     // a = 53 - O(1)
  
    for (let i = 0; i < input.length; i++) { // O(n)
      anotherFunction();    // Unknown - O(n)
      let stranger = true;  // O(n)
      a++;                  // O(n)
    }
    return a;       // O(1)
  }

  // BigO - O(3 + 4n) => BigO - O(n)