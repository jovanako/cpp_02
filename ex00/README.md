- Discovering a new number type - fixed-point numbers
	- Problem: floating-point numbers can be unpredictable in terms of
		precision and performance in specific fields like computer
		graphics or sound processing.
	- Solution: fixed-point numbers provide a balanced middle ground
		between performance and accuracy. You will represent a decimal number using an integer by 'fixing' the position of the decimal
		point.

- The Orthodox Canonical Form
	Starting with this exercise, all your C++ classes must implement four
	specific member functions to ensure they behave correctly during object
	creation and assignment.
	(1) DEFAULT CONSTRUTOR
		initializes the fixed-point value to 0
	(2) COPY CONSTRUCTOR
		creates a new object as a copy of an existing one
	(3) COPY ASSIGNMENT OPERATOR
		sets an existing object's value to that of another existing object
	(4) DESTRUCTOR
		handles the 'cleanup' when an object is destroyed


COPY ASSIGNMENT OPERATOR

*	A copy assignment operator is a non-template non-static member function
	with the name "operator=" that can be called with an argument of the same class type and copies the content of the argument without mutating the argument.

*	SYNTAX: return-type operator=(parameter-list);
			->	declaration of a copy assignment operator inside of class
				definition

Implementation breakdown:

1.	Class structure

*	Header guard: #ifndef FIXED_HPP - mandatory to avoid double inclusion
*	Static constant: initialized to 8
*	Encapsulation: the raw value and the bit constant are placed in the
	private section

2.	ORTHODOX CANONICAL FORM Implementation

*	Default constructor: initializes an object to a valid default state
						 when no arguments are provided. In Fixed, this
						 initializes the fixed-point value to 0.

*	Copy constructor: used to create a new object as a direct copy of an
					  existing object. It ensures that when you pass an
					  object by value or create a duplicate, the data is
					  copied directly.

*	Copy Assignment operator: used to copy data from one already existing
							  object to another already existing object.
							  It allows the = sign to work between two
							  objects of your class.

*	Destructor: cleans up an object when it goes out of scope or is
				deleted. This is where you free any dynamically allocated
				memory to prevent leaks. 

3.	Member functions

*	getRawBits: marked as const, meaning it promises not to modify the
	object's state
*	setRawBits: updates the raw integer value