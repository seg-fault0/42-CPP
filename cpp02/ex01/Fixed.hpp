/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:26:24 by wimam             #+#    #+#             */
/*   Updated: 2025/12/17 15:41:57 by wimam            ###   ########.fr       */
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
};

std::ostream & operator<<( std::ostream & o, Fixed const & other);