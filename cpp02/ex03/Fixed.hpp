/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:53:25 by wimam             #+#    #+#             */
/*   Updated: 2025/12/17 15:43:43 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					val;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const float f);
		Fixed(const int i);
		~Fixed();
		Fixed(Fixed const &other);
		Fixed&	operator=(Fixed const &other);

		int		toInt(void) const;
		float	toFloat(void)const;
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		Fixed	operator+(Fixed const &other);
		Fixed	operator-(Fixed const &other);
		Fixed	operator*(Fixed const &other);
		Fixed	operator/(Fixed const &other);

		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;
		
		Fixed&	operator++();
		Fixed 	operator++(int);
		Fixed&	operator--();
		Fixed 	operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<( std::ostream & o, Fixed const & other);