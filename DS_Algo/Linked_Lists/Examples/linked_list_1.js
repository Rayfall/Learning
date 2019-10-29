//const basket = ['apples', 'grapes', 'pears']

//linked list: apples --> grapes --> pears

//apples
//8947 --> grapes
//          8742 --> pears
//                    372 --> null

let obj1 = {a: true };
let obj2 = obj1;      // Points to the same location in memory

obj1.a = 'booya';     // Will change both obj1 and obj2
//delete obj1           // This will delete the obj1 but obj2 will still keep its place in memory.
obj2 = 'hello';  
console.log('1', obj1); // Must comment out if using the delete.
console.log('2', obj2);
