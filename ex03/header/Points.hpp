/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Points.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:41:14 by steh              #+#    #+#             */
/*   Updated: 2022/08/30 09:55:21 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(float const a, float const b);
		Point(Point const & src);
		Point const & operator=(Point const & rhs);
		~Point(void);

		Fixed const	getX(void) const;
		Fixed const	getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
