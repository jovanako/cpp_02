/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:28:22 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 12:02:52 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed() {
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed & other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

// copy assignment operator
Fixed & Fixed::operator=(const Fixed & other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// int constructor
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _bits;
}

// float constructor
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << _bits));
}

// destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _bits);
}

int Fixed::toInt(void) const {
	return _value >> _bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
	o << i.toFloat(); // use toFloat to print a human-readable decimal
	return o; // return the stream for chaining
}