- Discovering a new number type - fixed-point numbers


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