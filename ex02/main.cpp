/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:38:32 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/03 09:33:59 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;	// 0
	std::cout << ++a << std::endl;	// 0.00390625
	std::cout << a << std::endl;	// 0.00390625
	std::cout << a++ << std::endl;	// 0.00390625
	std::cout << a << std::endl;	// 0.0078125

	std::cout << b << std::endl;	// 10.1016
	
	std::cout << Fixed::max( a, b ) << std::endl;	// 10.1016
	
	return 0;
}