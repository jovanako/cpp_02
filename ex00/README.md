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

Implementation breakdown:

1.	Class structure

*	Header guard: #ifndef FIXED_HPP - mandatory to avoid double inclusion
*	Static constant: initialized to 8
*	Encapsulation: the raw value and the bit constant are placed in the
	private section

2.	Orthodox Canonical Form Implementation

*	Default constructor: initializes _value to 0 and prints message
*	Copy constructor: fetching the value with other.getRawBits so that
	the log message appears
*	Assignment operator: self-assignment check, to prevent issues if an
	object is assigned to itself

3.	Member functions

*	getRawBits: marked as const, meaning it promises not to modify the
	object's state
*	setRawBits: updates the raw integer value