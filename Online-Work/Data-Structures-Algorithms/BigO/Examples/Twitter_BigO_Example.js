// Find 1st, Find Nth....
const array = [{
    tweet:'hi',
    date: 2012
    }, {
    tweet: 'my',
    date: 2014
    }, {
    tweet: 'teddy',
    date: 2018
    }];

array[0];               // O(1)
array[array.length-1];  // O(1)

// Compare the dates of the tweets

/*  To compare, this is going to take O(n^2) as they are 
    going to be in nested loops. */

//------------------------------------------------------------
// What is the cost of the length of a string?
'eaityhnilujkertnakejafea'.length // Depends on the language and how it is built.
// For JavaScript, this is O(1). This could be done differently in another language.