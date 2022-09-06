/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:21:02 by steh              #+#    #+#             */
/*   Updated: 2022/09/06 21:12:55 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int const	Fixed::_frac = 8;

Fixed::Fixed(void): _fix(0)
{
	cout << "Default constructor called" << endl;
	return ;
}

Fixed::Fixed(int const input)
{
	cout << "Int constructor called" << endl;
	this->setRawBits(input << this->_frac);
}

// Calculate fixed = floating_input * 2^(fractional_bits)
Fixed::Fixed(float const input)
{
	int	fixed;
	
	cout << "Float constructor called" << endl;
	fixed = roundf(input * (1 << this->_frac));
	this->setRawBits(fixed);
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
