/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:24 by bsunda            #+#    #+#             */
/*   Updated: 2025/01/22 16:49:32 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_nb_fraction = 8;

Fixed::Fixed(void):_nb_fix(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int nb):_nb_fix(nb){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src){
	*this = src;
	return ; 
}

Fixed::~Fixed(void){
	std::cout << "Destructoir called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_nb_fix = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb_fix);
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb_fix = raw;
}