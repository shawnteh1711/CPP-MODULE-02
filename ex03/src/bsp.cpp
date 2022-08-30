/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:19:19 by steh              #+#    #+#             */
/*   Updated: 2022/08/30 14:23:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Points.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed s = (b.getX() - point.getX()) * (a.getY() - point.getY())
			- (b.getY() - point.getY()) * (a.getX() - point.getX());
	Fixed t = (c.getX() - b.getX()) * (a.getY() - b.getY())
			- (c.getY() - b.getY()) * (a.getX() - b.getX());

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return (false);
	Fixed d = (point.getX() - c.getX()) * (a.getY() - c.getY()) 
			- (point.getY() - c.getY()) * (a.getX() - c.getX());

	if (d == 0 || (d < 0) == (s + t <= 0))
		return (false);
	return (true);
}

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
