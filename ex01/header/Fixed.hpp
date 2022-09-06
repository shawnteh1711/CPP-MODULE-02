/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:19:47 by steh              #+#    #+#             */
/*   Updated: 2022/09/06 22:53:13 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed
{
	private:
		int					_fix;
		static int const	_frac;
	public:
		Fixed(void);
		Fixed(int const input);
		Fixed(float const input);
		Fixed(Fixed const & src);
		Fixed & operator=(Fixed const & rhs);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
