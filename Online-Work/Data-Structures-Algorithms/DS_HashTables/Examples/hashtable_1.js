let user = {
    age: 54,
    name: 'Kylie',
    magic: true,
    scream: function() {
        console.log('ahhhhhh!');
    }
}

user.age;                       // O(1)
user.spell = 'abra kadabra';    // O(1)
user.scream();                  // O(1)

// const a = new Map() - allows you to save any data type as a key,  also maintains insertion order
