/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:28:10 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 09:50:25 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed();    // default constructor

		Fixed(const Fixed &other);    // copy constructor

		Fixed & operator=(const Fixed &other);    // assignment operator
		
		Fixed(const int value);

		Fixed(const float value);

		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif