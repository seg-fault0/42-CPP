/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:37:02 by wimam             #+#    #+#             */
/*   Updated: 2025/12/11 18:10:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					val;
		static const int	bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed&	operator=(Fixed const &other);

		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
};