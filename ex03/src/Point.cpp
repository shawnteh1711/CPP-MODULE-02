/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:42:15 by steh              #+#    #+#             */
/*   Updated: 2022/08/30 14:03:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Points.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point::Point(float const a, float const b): _x(Fixed(a)), _y(Fixed(b))
{
	return ;
}

Point::Point(Point const & src) : _x(src._x), _y(src._y)
{
	return ;
}

const Fixed	Point::getX(void) const
{
	return (this->_x);
}

const Fixed	Point::getY(void) const
{
	return (this->_y);
}

Point const & Point::operator=(Point const & rhs)
{
	return (rhs);
	// (void)rhs;
	// return (*this);
}




