/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:24 by bsunda            #+#    #+#             */
/*   Updated: 2025/01/24 15:50:03 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_nb_fraction = 8;

Fixed::Fixed(void):_nb_fix(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float nb):_nb_fix(nb){
	std::cout << "Float constructor called" << std::endl;
	this->_nb_fix = roundf( nb * ( 1 << Fixed::_nb_fraction )); 
	return ;
}

Fixed::Fixed(int nb):_nb_fix(nb){
	std::cout << "Int constructor called" << std::endl;
	this->_nb_fix = nb * ( 1 << Fixed::_nb_fraction );
	return ;
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ; 
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb_fix);
}

void Fixed::setRawBits( int const raw ){
//	std::cout << "setRawBits member function called" << std::endl;
	this->_nb_fix = raw;
}

float	Fixed::toFloat( void ) const{
	float	f = (float)this->_nb_fix / (1 << Fixed::_nb_fraction); 
	return (f);
}

int		Fixed::toInt( void ) const{
	int	i = this->_nb_fix / (1 << Fixed::_nb_fraction);
	return (i);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}

Fixed & Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->setRawBits(rhs.getRawBits())  ;
	}
	return *this;
}