/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:38:51 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 22:17:11 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed() {
	_value = 0;
}

// copy constructor
Fixed::Fixed(const Fixed & other) {
	this->_value = other.getRawBits();
}

// copy assignment operator
Fixed & Fixed::operator=(const Fixed & other) {
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// comparison operators
bool Fixed::operator>(const Fixed & other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed & other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed & other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed & other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed & other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed & other) const {
	return this->_value != other._value;
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed & other) const {
	Fixed temp;
	temp.setRawBits(this->getRawBits() + other.getRawBits());
	return temp;
}

Fixed Fixed::operator-(const Fixed & other) const {
	Fixed temp;
	temp.setRawBits(this->getRawBits() - other.getRawBits());
	return temp;
}

Fixed Fixed::operator*(const Fixed & other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed & other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// increment and decrement operators
// prefix
Fixed & Fixed::operator++() {
	this->_value++; // smallest epsilon change
	return *this;
}

// postfix
Fixed Fixed::operator++(int) {
	Fixed temp(*this); // copy old state
	this->_value++; // update actual object
	return temp; // return old state
}

// prefix
Fixed & Fixed::operator--() {
	this->_value--;
	return *this;
}

// postfix
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return temp;	
}

// int constructor
Fixed::Fixed(const int n) {
	this->_value = n << _bits;
}

// float constructor
Fixed::Fixed(const float f) {
	this->_value = roundf(f * (1 << _bits));
}

// destructor
Fixed::~Fixed() {}

int Fixed::getRawBits() const {
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

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	if (a < b)
		return a;
	return b;
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
	if (a < b)
		return a;
	return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	if (a > b)
		return a;
	return b;
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
	if (a > b)
		return a;
	return b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
	o << i.toFloat();
	return o;
}