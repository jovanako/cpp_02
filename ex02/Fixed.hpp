/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:38:42 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 21:08:03 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		// default constructor
		Fixed();
		
		// copy constructor
		Fixed(const Fixed & other);

		// copy assignment operator
		Fixed & operator=(const Fixed & other);

		// comparison operators
		bool operator>(const Fixed & other) const;
		bool operator<(const Fixed & other) const;
		bool operator>=(const Fixed & other) const;
		bool operator<=(const Fixed & other) const;
		bool operator==(const Fixed & other) const;
		bool operator!=(const Fixed & other) const;

		// arithmetic operators
		Fixed operator+(const Fixed & other) const;
		Fixed operator-(const Fixed & other) const;
		Fixed operator*(const Fixed & other) const;
		Fixed operator/(const Fixed & other) const;
		
		// increment and decrement operators
		Fixed & operator++();	// prefix
		Fixed operator++(int);	// postfix

		Fixed & operator--();	// prefix
		Fixed operator--(int);	// postfix
		
		// int constructor
		Fixed(const int n);

		// float constructor
		Fixed(const float f);

		// destructor
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;


		static Fixed & min(Fixed & a, Fixed & b);
		static const Fixed & min(const Fixed & a, const Fixed & b);

		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & max(const Fixed & a, const Fixed & b);
};

std::ostream & operator<<(std::ostream & o, const Fixed & i);

#endif