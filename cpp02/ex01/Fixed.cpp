/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:26:23 by wimam             #+#    #+#             */
/*   Updated: 2025/12/17 15:42:43 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float Constructor called" << std::endl;
	this->val = roundf(f * (1 << this->bits));
}

Fixed::Fixed(const int i)
{
	std::cout << "Int Constructor called" << std::endl;
	this->val = i * (1 << this->bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	val = other.val;
}

Fixed& Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->val = other.val;
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	val = raw;
}

int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (val);
}

int	Fixed::toInt(void) const
{
	return ((int)toFloat());
}

float Fixed::toFloat(void) const
{
	return (float)this->val / (1 << this->bits);
}

std::ostream & operator<<( std::ostream & cout, Fixed const & other)
{
	cout << other.toFloat();
	return (cout);
}
