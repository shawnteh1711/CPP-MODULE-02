/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:44:00 by steh              #+#    #+#             */
/*   Updated: 2022/09/06 23:02:26 by steh             ###   ########.fr       */
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

	Point	a(-2.8, 5.6);
	Point	b(-4, 1);
	Point	c(0.4, 1.8);

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
