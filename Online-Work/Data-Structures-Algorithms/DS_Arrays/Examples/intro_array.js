const strings= ['a', 'b', 'c', 'd'];
//4*4 = 16 bytes of storage

const numbers = [1,2,3,4,5];
// Variable array is somewhere in memory and the computer knows it.
// When I do array[2], i'm telling the computer, hey go to the array and grab the 3rd item from where the array is stored.


//push. Adds an item onto the last part of array.
strings.push('e'); //O(1) operation

//pop, opposite of push. Removes last item of the array.
strings.pop(); //O(1) operation
strings.pop(); //O(1) operation

//unshift. Adds an item to the beginning of an array.
strings.unshift('x'); //O(n) operation

//splice, 
strings.splice(2, 0, 'alien'); //Faster O(n) operation.

//Different operations cause the program to behave differently.
//In affect, this will also have a resource hit on how the computer is effected.


console.log(strings)