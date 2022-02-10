/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:05 by ywake             #+#    #+#             */
/*   Updated: 2022/02/10 14:33:06 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _rawBits(integer << _binalyPoint)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fraction) :
  _rawBits(roundf(fraction * (1 << _binalyPoint)))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
  std::cout << "Assignation operator called" << std::endl;
  if (this != &copy) {
    _rawBits = copy.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const
{
  return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
  _rawBits = raw;
}

float Fixed::toFloat(void) const
{
  float f;

  f = static_cast<float>(_rawBits);
  f /= 1 << _binalyPoint;
  return f;
}

int Fixed::toInt(void) const
{
  return _rawBits >> _binalyPoint;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
  os << fixed.toFloat();
  return (os);
}
