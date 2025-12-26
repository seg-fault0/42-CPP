/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:53:19 by wimam             #+#    #+#             */
/*   Updated: 2025/12/17 15:44:00 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*************************************************/
/***************   ORTHODOX  *********************/
/*************************************************/

Fixed::Fixed() : val(0)
{
}

Fixed::Fixed(const float f)
{
	this->val = roundf(f * (1 << this->bits));
}

Fixed::Fixed(const int i)
{
	this->val = i * (1 << this->bits);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &other)
{
	val = other.val;
}

Fixed& Fixed::operator=(Fixed const &other)
{
	if (this != &other)
		this->val = other.val;
	return *this;
}

/*************************************************/
/***************   SET/GET  **********************/
/*************************************************/

void	Fixed::setRawBits(int const raw)
{
	val = raw;
}

int	Fixed::getRawBits(void) const 
{
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

/*************************************************/
/*****************  OSTREAM  *********************/
/*************************************************/

std::ostream & operator<<(std::ostream & cout, Fixed const & other)
{
	cout << other.toFloat();
	return (cout);
}

/*************************************************/
/*****************  + - * /  *********************/
/*************************************************/
Fixed Fixed::operator+(Fixed const &other)
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other)
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other)
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other)
{
	return Fixed(toFloat() / other.toFloat());
}

/*************************************************/
/************** > < >= <= == !=  *****************/
/*************************************************/

bool Fixed::operator>(Fixed const &other) const
{
	return toFloat() > other.toFloat();
}

bool Fixed::operator<(Fixed const &other) const
{
	return toFloat() < other.toFloat();
}

bool Fixed::operator>=(Fixed const &other) const
{
	return toFloat() >= other.toFloat();
}

bool Fixed::operator<=(Fixed const &other) const
{
	return toFloat() <= other.toFloat();
}

bool Fixed::operator==(Fixed const &other) const
{
	return toFloat() == other.toFloat();
}

bool Fixed::operator!=(Fixed const &other) const
{
	return toFloat() != other.toFloat();
}

/*************************************************/
/*****************   ++   --   *******************/
/*************************************************/
Fixed &Fixed::operator++()
{
	this->val++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->val++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->val--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->val--;
	return tmp;
}

/*************************************************/
/*****************  MIN    MAX  ******************/
/*************************************************/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}