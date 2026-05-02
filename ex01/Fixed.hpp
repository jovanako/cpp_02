/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:28:10 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 11:50:54 by jkovacev         ###   ########.fr       */
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
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif