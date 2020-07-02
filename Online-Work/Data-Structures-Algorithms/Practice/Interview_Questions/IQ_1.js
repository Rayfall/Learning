/*  Give 2 arrays, create a function that let's a user know (true/false)
    whether these two arrays contain any common items. 
    For Example:
    const array1 = ['a', 'b', 'c', 'x'];
    const array2 = ['z', 'y', 'i'];
    should return false.
    ------------------------------------
    const array1 = ['a', 'b', 'c', 'x'];
    const array2 = ['z', 'y', 'x'];
    should return true.
*/

// 1) Write down the key points. Make sure you have all the details.
// 2) Make sure to double check: What are the inputs? What are the outputs?
// - 2 Parameters: arrays
// - The function should return true or false.

// 3) What is the most important value of the problem?
// - How large is the size of the array?
// - Is our goal to be as efficient as possible or as fast as possible?

// 4) Don't be annoying and ask too many questions.

// 5) Start with the brute force approach.
// - Nested loop option, taking one element from the array and comparing it with the other. Two for loops nested in one another or BigO (n^2). Worse possible solution.

// 6) Tell them why this is not the best.
// - Code is not as efficient. Takes too long to go through each and every single possible solution between the two arrays.
// - Code solution can be improved for better efficiency.

// - Given Arrays.
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'x'];

// - Potential Solution. Demonstrates #5 and #6, brute force solution and can be explained why this is not the most efficient solution.
function containsCommonItem(arr1, arr2) // O(a*b)
{
    for (let i = 0; i < arr1.length; i++) 
    {
        for (let j = 0; j < arr2.length; j++)  
        {
            if(arr1[i] === arr2[j])
            {
                return false;
            }
        }
    }
    return false;
}

containsCommonItem(array1, array2);

// 7) Walk through the approach and see where you may be able to break things.
// - Is there a way to make this faster?
// - Is there any way to discard unnecessary work or repititions?

// array1 ==> obj { a: true, b: true, c: true, x: true}  (Convert the first array into an object.)
// array2[index] === obj.properties                      (Loop through only one array instead of two.)

// 8) Before you start coding, walk through the code and write down the steps.

// 9) Modularize your code from the very beginning. Break up the code into pieces and add comments if needed.

function containsCommonItem2(arr1, arr2) // O(a+b)
{
    // Loop through first array and create object where properties === items in the arracy
    let map = {};
    for (let i = 0; i < arr1.length; i++)
    {
        if(!map[array1[i]])
        {
            const item = array1[i];
            map[item] = true;
        }
    }
    // Loop through second array and check if item in second array exists on created object.
    for (let j = 0; j < arr2.length; j++)
    {
        if(map[array2[j]])
        {
            return true;
        }
    }
    return false;

    // - This solution will have two separate loops instead of a pair of nested loops. O(a+b) > O(a*b)
}

// 10) Start actually writing your code. Keep in mind that the more you prepare and understand what you need to code, the better you will be able to write it.
// - Never start a whiteboard interview not being sure of how things are going to work out.
// - Keep in mind, you will not be able to fully answer the question in time. This is more of a test of your coding ability and ability to work through a problem.

// 11) Think about the error checks for the code. Never make assupmtions about the input.
// - Think of ways to break your own code and how you can safeguard this.
// - Always think of possible ways to test your code and how to discuss possible improvements.

// 12) Don't use bad/confusing names like i or j. Write code that reads well.
// - Use parameters with actual names or meaningful variables.
// - This can be something to discuss with the interviewer so that they know you are thinking about it.

// 13) Test your code.

// 14) Talk to the interviewer about where you would improve the code.
// - Maybe there are language-specific methods you can use to improve the code, searching google for the answer.

// 15) Be prepared to answer left over or follow-up questions.

