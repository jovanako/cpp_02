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
