//#1 -- For loop in Javascript.
const nemo = ['nemo'];

function findNemo1(array) {
  for (let i = 0; i < array.length; i++) {
    if (array[i] === 'nemo') {
      console.log('Found NEMO!');
      break; // Added in to break the loop.
    }
  }
}

findNemo1(nemo);