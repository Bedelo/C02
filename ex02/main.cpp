/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:21 by bsunda            #+#    #+#             */
/*   Updated: 2025/02/15 13:39:44 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	
	std::cout << "RETOUR SUJET" << std::endl;
	std::cout << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << std::endl;
	std::cout << "TEST FONCTIONS" << std::endl;
	Fixed c(5);
	Fixed d(2);
	std::cout << "c: " << c.toInt() << std::endl;
	std::cout << "d: " << d.toInt() << std::endl;
	std::cout << std::endl;
	
	std::cout << "multiplication c * d:" << std::endl;
	Fixed produit(c * d);
	std::cout << "produit: " << produit.toInt() << std::endl;
	std::cout << std::endl;
	
	std::cout << "soustraction produit - d:" << std::endl;
	Fixed soustraction(produit - d);
	std::cout << "soustraction: " << soustraction.toInt() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Division division / d:" << std::endl;
	Fixed division(soustraction / d);
	std::cout << "division: " << division.toInt() << std::endl;
	std::cout << std::endl;
	
	std::cout << "addition d + d:" << std::endl;
	Fixed addition(d * d);
	std::cout << "addition: " << addition.toInt() << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "COMPARAISON FONCTIONS" << std::endl;
	
	std::cout << "a == a: " << (a == a) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << addition << " != " << division << ": " << (addition != division) << std::endl;
	std::cout << addition << " <= " << division << ": " << (addition <= division) << std::endl;
	std::cout << produit << " >= " << division << ": " << (produit >= division) << std::endl;
	
	std::cout << std::endl;
	std::cout << "MIN MAX FONCTIONS" << std::endl;	
	std::cout << "max ? " << a << " : " << b << " => "<<Fixed::max(a, b) << std::endl;
	std::cout << "min ? " << a << " : " << b << " => "<<Fixed::min(a, b) << std::endl;
	Fixed &ref_a = a;
	Fixed &ref_c = c;
	std::cout << "max ? " << a << " : " << c << " => "<<Fixed::max(ref_a, ref_c) << std::endl;
	std::cout << "min ? " << a << " : " << c << " => "<<Fixed::min(ref_a, ref_c) << std::endl;
	
	
	
	std::cout << std::endl;
	
	
	return (0);
}
