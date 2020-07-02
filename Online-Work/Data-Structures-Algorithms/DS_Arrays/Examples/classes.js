// Reference Type - 
[] === [];   // False
[1] === [1]; // False

// Objects are reference types. These are not defined by the programming language. These are created by the programmer.
// Numbers, Booleans, Strings, nulls, underfined are primitive types.
var object1 = { value: 10};
var object2 = object1;  // This call references object1 and so they are equal.
var object3 = { value: 10}; // This creates its own object and thus is not equal.
object1 === object2; // True
object1 === object3; // False
object1.value = 15;
object2.value;       // 15
object3.value;       // 10


// Context, gets confused with scope.
function b() {
    let a = 4;
}
console.log(a); // This returns a reference error because this is outside the scope.

const object4 = {
    a: function() {
        console.log(this); // Context is where we are within the object.
    }
}
object4.a(); // Returns {a: f}

// Instantiation - Making a copy or an instance of an object and re-use the code.
class Player {
    constructor(name, type) {
        console.log(this);  // Wizard {}
        console.log('player', this); // Reference error, must call super constructer in derived class before accessing 'this' or returning from derived constructor
        // Otherwise, -> player > Wizard {}
        this.name = name;
        this.type = type;
    }
    introduce() {
        console.log(`Hi I am ${this.name}, I'm a ${this.type}`);
    }
}

class Wizard extends Player {
    constructor(name, type) {
        super(name, type)
        console.log('wizard', this); // If this were before, it would cause a reference error.
        // Otherwise, -> wizard > Wizard {name: "Shelly", type: "Healer"}
    }
    play() {
        console.log(`WEEEEEEE I'm a ${this.type}`);
    }
}

const wizard1 = new Wizard('Shelly', 'Healer');
const wizard2 = new Wizard('Shaun', 'Dark Magic');

wizard1.play(); // WEEEEEEE I'm a Healer
wizard1.introduce(); // Hi I am Shelly, I'm a Healer
wizard2.introduce(); // Hi I am Shaun, I'm a Dark Magic