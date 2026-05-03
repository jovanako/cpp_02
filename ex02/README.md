*	Multiplication operator overloading

Fixed Fixed::operator*(const Fixed & other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Example implementation:

The scenario: 2.5 x 2

Imagine we have two objects:
*	a: A Fixed object initialized with 2.5f
*	b: A Fixed object initialized with 2

(1) Inside this->toFloat()
	*	Object a has a raw value of 640 (because 2.5 x 256 = 640)
	*	a.toFloat() returns 640 / 256.0f, which is 2.5f

(2) Inside other.toFloat()
	*	Object b has a raw value of 512 (because 2 x 256 = 512)
	*	b.toFloat() returns 512 / 256.0f, which is 2.0f

(3) The multiplication
	*	The code calculates 2.5f * 2.0f, which results in the float 5.0f

(4) The return: return Fixed(5.0f);
	*	This calls the Float Constructor with the value 5.0f
	*	Inside that constructor, it performs roundf(5.0f * 256), which
		equals 1280
	*	The constructor creates a new Fixed object with raw bits set to 1280

*	Division by zero:

	When you use the toFloat() method, dividing by zero will typically
	result in a float value of inf (infinity) or nan (not a number). When
	these are passed back into your Fixed constructor and converted to raw
	bits, the behavior will be defined by how roundf and integer casting
	handle those special floating-point values - which is perfectly fine for
	this exercise.

*	Epsilon
	In the context of computer science, Epsilon generally refers to the
	smallest possible difference between two distinct values in a number system.

	*	Since Fixed class is a fixed-point system with 8 fractional bits,
		you have a "grid" of numbers. You cannot represent a value between
		these grid marks.
	*	The smallest increment you can possibly represent is 1 unit of the
		raw integer _value.
	*	Mathematically, because that "1" is in the 8th bit position, its
		value is 1/2^8, which is 1/256.
	*	Therefore, your smallest "epsilon" is 0.00390625.

	*	When you overload operator++, the subject requires you to increment
		by this epsilon.
		*	If you were to increment by 1.0, you would be skipping 255
			possible representable values.
		*	By incrementing the raw bits by 1(_value++), you move to the
			very next possible number your class is capable of storing.
	
	*	In standard floating-point math (float), epsilon is not a constant
		valie; it gets larger as the numbers get larger
		*	In your Fixed Point class, the epsilon is constant.
		*	Whether your value is 0.0 or 1000.0, the distance to the next
			representable number is always exactly 1/256.

*	Output explained:
	(1) The initial values:
		*	0:	This is the result of a default-constructed "Fixed a;".
				Since the raw bits are 0, the value is 0.
		*	0.00390625: This is the smallest epsilon. It appears after a
						prefix increment "++a;".
			*	raw bits go from 0 to 1
			*	1/256 = 0.00390625
	
	(2) Postfix increment confusion (a++)
		*	0.00390625: This is the output of
						"std::cout << a++ << std::endl;".
						Because it is postfix, it returns the old value
						(from the previous step) to the console before
						incrementing the object internally.
		*	0.00390625: This is the current state of "a" after the previous
						postfix increment finished.
	
	(3) Continued incrementing
		*	0.0078125:	This is 2/256. It means your raw bits have reached
						2. This happens after another increment.
	
	(4) Floating point math
		*	10.1016: 5.05 x 2 = 10.01

	(5) Static max
		*	10.1016: a = 0.0078125, b = 10.1016


