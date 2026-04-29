/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:56:02 by jkovacev          #+#    #+#             */
/*   Updated: 2026/04/29 14:28:16 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed();
		
		Fixed(const Fixed &other);
		
		Fixed & operator=(const Fixed &other);

		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif