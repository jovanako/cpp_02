/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:02:03 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 11:51:42 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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