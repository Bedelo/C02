/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:17 by bsunda            #+#    #+#             */
/*   Updated: 2025/01/22 17:53:51 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed{
	
public:
	Fixed(void);
	Fixed(int nb);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;

private:
	int _nb_fix;
	static int const _nb_fraction;
};

#endif