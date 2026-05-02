/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:56:02 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/02 11:50:28 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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

		// destructor
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif