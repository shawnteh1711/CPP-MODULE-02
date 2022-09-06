/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:19:19 by steh              #+#    #+#             */
/*   Updated: 2022/09/06 23:18:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Points.hpp"
#include "Fixed.hpp"

bool bsp( Point const pt, Point const a, Point const b, Point const c)
{
	Fixed s = (a.getX() - c.getX()) * (pt.getY() - c.getY())
			- (a.getY() - c.getY()) * (pt.getX() - c.getX());
	Fixed t = (b.getX() - a.getX()) * (pt.getY() - a.getY())
			- (b.getY() - a.getY()) * (pt.getX() - a.getX());

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return (false);
	Fixed d = (c.getX() - b.getX()) * (pt.getY() - b.getY()) 
			- (c.getY() - b.getY()) * (pt.getX() - b.getX());
	return d == 0 || (d < 0) == (s + t <= 0);

	// if (d == 0 || (d < 0) == (s + t <= 0))
	// 	return (false);
	// return (true);
}

// Fixed sign(Point ref_point, Point p2, Point p3)
// {
//     return Fixed((ref_point.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (ref_point.getY() - p3.getY()));
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed d1, d2, d3;
//     bool has_neg, has_pos;

//     d1 = sign(point, a, b);
//     d2 = sign(point, b, c);
//     d3 = sign(point, c, a);

//     has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
//     has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

// 	return !(has_neg && has_pos);
// }

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
