/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:21:02 by steh              #+#    #+#             */
/*   Updated: 2022/09/06 20:31:11 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_frac = 8;

Fixed::Fixed(void) : _fix(0)
{
	cout << "Default constructor called" << endl;
	return ;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	cout << "Copy constructor called" << endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		this->_fix = rhs._fix;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (this->_fix);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	this->_fix = raw;
}
