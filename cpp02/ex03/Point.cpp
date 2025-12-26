/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:25:55 by wimam             #+#    #+#             */
/*   Updated: 2025/12/13 17:45:35 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){}

Point::Point(const float x, const float y):x(x), y(y){}

Point::Point(const Point &copy): x(copy.getX()), y(copy.getY()){}

Point::~Point(){}

Point& Point::operator=(const Point &other)
{
	(void) other;
	return *this;
}

const Fixed	&Point::getX(void)const
{
	return (this->x);
}

const Fixed	&Point::getY(void)const
{
	return (this->y);
}
