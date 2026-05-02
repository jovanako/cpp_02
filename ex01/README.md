*	What should be added to the Fixed class:

	(1)	A constructor that takes a CONSTANT INTEGER as a parameter.
		It converts it to the corresponding fixed-point value. The
		fractional bits value should be initialized to 8.
	
	(2)	A constructor that takes a CONSTANT FLOATING-POINT NUMBER as
		a parameter. It converts it to the corresponding fixed-point value.
		The fractional bits value should be initialized to 8.

	(3)	A member function "float toFloat(void) const;"
		that converts the fixed-point value to a floating-point value.
	
	(4)	A member function "int toInt(void) const;"
		that converts the fixed-point value to an integer value.
	
	(5)	An overload of the insertion (<<) operator that inserts a
		floating-point representation of the fixed-point number into the
		output stream object passed as a parameter.

*	The math: Bit Shifting

	(1) Integer to Fixed-Point:
		Since an integer has no fractional part, you simply "shift" the
		the decimal point 8 places to the left. In code, this is done by
		using the bitwise Left Shift operator (<<).
		*	Calculation: raw_value = input_int << 8;
		*	Visual: you are effectively multiplying the integer by 2^8 
			(which is 256) to move it into the "whole number" section of
			your fixed-point representation.
		
	(2) Floating-Point to Fixed-Point:
		Floats are trickier because they have decimals. You can't use
		bit-shifting on a float directly in C++.
		*	Calculation: raw_value = roundf(input_float * 256);
		*	We use roundf from <cmath> to ensure the closest possible
			accuracy when "mapping" the float onto the fixed grid.

*	The << Operator Overload

	The overload of the insertion (<<) operator allows you to print your
	class directly using "std::cout <<myFixedObject;

	Logic:	This function should call your toFloat() member function to
			represent the fixed-point number as a readable decimal for
			the user.
	
	o << i.toFloat();
	return o;

	Breakdown:
	
	(1) o << ...
		The variable "o" is a reference to the output stream (like
		std::cout). By using "<<", you are pushing data into that stream.
		Since the stream doesn't inherently know how to read your custom
		"Fixed" class, you have to 'translate' your object into a type that
		it does understand.
	
	(2) i.toFloat()
		This is the translation step. Instead of trying to rint the raw
		bits (which would just be a large, confusing integer), you call
		your tofloat() member function.
		-	this function takes your internal _value and divides it by 256.0
		-	it returns a standard C++ float
		-	now, the output stream "o" receives a simple float, which it
			already knows how to print perfectly
	
	(3) ; return o;
		This is a crucial C++ requirement for OPERATOR CHAINING.
		-	By returning the reference to the stream "o", you allow the next
			part of the code to keep using it.
		-	Example: std::cout << a << " is the value";
			1 - First, std::cout << a runs. Your function returns std::cout.
			2 - Then, the code effectively becomes
				std::cout << " is the value";, which works perfectly.

*	SUMMARY OF LOGIC:

	Direction					Operation
	______________________________________________________________________

	Int -> Fixed				Shift left by 8 bits (value << 8)

	______________________________________________________________________

	Float -> Fixed				Multiply by 256 and roundf

	______________________________________________________________________

	Fixed -> Int				Shift right by 8 bits (value >> 8)

	______________________________________________________________________

	Fixed -> Float				Divide by 256.0 (casting to float)

	______________________________________________________________________