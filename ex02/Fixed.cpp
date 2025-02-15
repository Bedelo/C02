/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:24 by bsunda            #+#    #+#             */
/*   Updated: 2025/02/15 14:01:28 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_nb_fraction = 8;

Fixed::Fixed(void):_nb_fix(0){
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nb){
	// std::cout << "Float constructor called" << std::endl;
	this->_nb_fix = roundf( nb * ( 1 << Fixed::_nb_fraction )); 
	return ;
}

Fixed::Fixed(int const nb){
	// std::cout << "Int constructor called" << std::endl;
	this->_nb_fix = nb << Fixed::_nb_fraction ;
	return ;
}

Fixed::Fixed(Fixed const & src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ; 
}

Fixed::~Fixed(void){
	// std::cout << "Destructor called" << std::endl;
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

Fixed	Fixed::operator+( Fixed const &rhs ) const{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &rhs ) const{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &rhs ) const{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &rhs ) const{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool	Fixed::operator>( Fixed const &rhs ) const{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<( Fixed const &rhs ) const{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const &rhs ) const{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=( Fixed const &rhs ) const{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const &rhs ) const{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const &rhs ) const{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	& Fixed::operator++( void ){
	this->_nb_fix++;
	return (*this);
}

Fixed	Fixed::operator++( int ){
	Fixed	old = *this;
	this->_nb_fix++;
	return (old);
}

Fixed	& Fixed::operator--( void ){
	this->_nb_fix--;
	return (*this);
}

Fixed	Fixed::operator--( int ){
	Fixed	old = *this;
	this->_nb_fix--;
	return (old);
}

Fixed	& Fixed::min(Fixed & min1, Fixed & min2){ 
	if ( min1.getRawBits() < min2.getRawBits())
		return (min1);
	else
		return (min2);
}

Fixed	Fixed::min(Fixed const & min1, Fixed const & min2){ 
	if ( min1.getRawBits() < min2.getRawBits())
		return Fixed(min1);
	else
		return Fixed(min2);	
}

Fixed	 &Fixed::max(Fixed & max1, Fixed & max2){ 
	if ( max1.getRawBits() > max2.getRawBits())
		return (max1);
	else
		return (max2);
}

Fixed	Fixed::max(Fixed const & max1, Fixed const & max2){ 
	if ( max1.getRawBits() > max2.getRawBits())
		return Fixed(max1);
	else
		return Fixed(max2);	
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}

Fixed & Fixed::operator=(Fixed const & rhs){
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->setRawBits(rhs.getRawBits())  ;
	}
	return *this;
}