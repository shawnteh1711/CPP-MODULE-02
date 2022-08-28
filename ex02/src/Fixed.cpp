/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:21:02 by steh              #+#    #+#             */
/*   Updated: 2022/08/28 22:42:13 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int const	Fixed::_frac = 8;

Fixed::Fixed(void): _fix(0)
{
	return ;
}

Fixed::Fixed(int const input)
{
	this->setRawBits(input << this->_frac);
}

Fixed::Fixed(float const input)
{
	int	fixed;
	
	fixed = roundf(input * (1 << this->_frac));
	this->setRawBits(fixed);
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fix = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fix = raw;
}

//https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
float	Fixed::toFloat(void) const
{
	int		bit;
	float	fix;

	bit = 1 << this->_frac; // 256
	fix = (float)this->_fix;
	return (fix / bit);
	// return ((float)this->_fix / (float)(1 << this->_frac));
}

int		Fixed::toInt(void) const
{
	int		bit;
	int		fix;

	bit = 1 << this->_frac; // 256
	fix = (int)this->_fix;
	return (fix / bit);
	// return ((int)this->_fix / (int)(1 << this->_frac));
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

// comparison operators
bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_fix > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_fix > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_fix >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_fix <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_fix == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_fix != rhs.getRawBits());
}

// arithmetic operators
Fixed	Fixed::operator+(Fixed const & rhs) const
{
	Fixed tmp;
	tmp._fix = this->_fix + rhs.getRawBits();
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	Fixed tmp;
	tmp._fix = this->_fix - rhs.getRawBits();
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	Fixed tmp;
	tmp._fix = this->_fix * rhs.toFloat();
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	Fixed tmp;
	tmp._fix = this->_fix / rhs.toFloat();
	return (tmp);
}

// increment/decrement operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp;

	tmp._fix = this->_fix++;
	return (tmp);
}

Fixed	Fixed::operator++(void)
{
	this->_fix++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp;

	tmp._fix = this->_fix--;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->_fix--;
	return (*this);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}
