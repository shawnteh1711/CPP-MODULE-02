/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:44:00 by steh              #+#    #+#             */
/*   Updated: 2022/08/30 15:11:18 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Points.hpp"
#include "Fixed.hpp"

using std::cin;

// https://www.geogebra.org/geometry
int main(void)
{
	float	x;
	float	y;

	Point	a(16.4, 61.5);
	Point	b(11.1, 38.1);
	Point	c(37.7, 42.3);

	cout << "Check point whether in triangle " << endl;
	cout << "Give float x to check :";
	cin >> x;
	cout << "Give float y to check :";
	cin >> y;
	Point	pt(x, y);
	if (bsp(pt, a, b, c))
		cout << "points is inside triangle" << endl;
	else
		cout << "points is outside triangle" << endl;
	return (0);
}
