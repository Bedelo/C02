/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:17 by bsunda            #+#    #+#             */
/*   Updated: 2025/02/14 15:43:08 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
	
public:
	Fixed(void);
	Fixed(int const nb);
	Fixed(float const  nb);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);
	
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	bool operator<(Fixed const & rhs) const;
	bool operator>(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;
	
	Fixed operator++( int);
	Fixed & operator++( void);
	Fixed operator--( int);
	Fixed & operator--( void);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed  & min(Fixed & min1, Fixed & min2);
	static Fixed  min(Fixed const & min1, Fixed const & min2);
	static Fixed  & max(Fixed & max1, Fixed & max2);
	static Fixed  max(Fixed const & max1, Fixed const & max2);

private:
	int _nb_fix;
	static int const _nb_fraction;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif