/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:05 by ywake             #+#    #+#             */
/*   Updated: 2022/02/10 16:16:20 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _rawBits(0) { }
Fixed::Fixed(const int integer) : _rawBits(integer << _binalyPoint) { }
Fixed::Fixed(const float fraction) : _rawBits(roundf(fraction * (1 << _binalyPoint))) { }
Fixed::Fixed(const Fixed &copy)
{
  *this = copy;
}

Fixed::~Fixed() { }

/*
** Operators
*/

Fixed &Fixed::operator=(const Fixed &other)
{
  if (this != &other) {
    _rawBits = other.getRawBits();
  }
  return *this;
}

Fixed Fixed::operator+(const Fixed &other) const
{
  return Fixed(_rawBits + other.getRawBits());
}

Fixed Fixed::operator-(const Fixed &other) const
{
  return Fixed(_rawBits - other.getRawBits());
}

Fixed Fixed::operator*(const Fixed &other) const
{
  return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
  int res = _rawBits / other.getRawBits();

  return Fixed(res << _binalyPoint);
}

Fixed &Fixed::operator++(void)
{
  ++_rawBits;
  return (*this);
}

Fixed Fixed::operator++(int)
{
  Fixed temp = *this;

  ++(*this);
  return temp;
}

Fixed &Fixed::operator--(void)
{
  --_rawBits;
  return (*this);
}

Fixed Fixed::operator--(int)
{
  Fixed temp = *this;

  --(*this);
  return temp;
}

bool Fixed::operator>(const Fixed &other) const { return _rawBits > other.getRawBits(); }
bool Fixed::operator<(const Fixed &other) const { return _rawBits < other.getRawBits(); }
bool Fixed::operator>=(const Fixed &other) const { return _rawBits >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed &other) const { return _rawBits <= other.getRawBits(); }
bool Fixed::operator==(const Fixed &other) const { return _rawBits == other.getRawBits(); }
bool Fixed::operator!=(const Fixed &other) const { return _rawBits != other.getRawBits(); }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
  os << fixed.toFloat();
  return (os);
}

/*
** Members
*/

int Fixed::getRawBits(void) const
{
  return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
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

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  return a.getRawBits() <= b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  return a.getRawBits() >= b.getRawBits() ? a : b;
}
