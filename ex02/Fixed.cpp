/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:05 by ywake             #+#    #+#             */
/*   Updated: 2022/03/09 13:47:35 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

Fixed::Fixed(void) : _rawBits(0) {}
Fixed::Fixed(const int integer) : _rawBits(integer << _binalyPoint) {}
Fixed::Fixed(const float fraction) :
    _rawBits(roundf(fraction * (1 << _binalyPoint)))
{
}
Fixed::Fixed(const Fixed &copy) { *this = copy; }

Fixed::~Fixed() {}

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
  Fixed res;

  res.setRawBits(_rawBits + other.getRawBits());
  return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
  Fixed res;

  res.setRawBits(_rawBits - other.getRawBits());
  return res;
}

/**
 * 0b0001.0000(1) * 0b0001.0000(1) = 0b00010000.0000 >> _binalyPoint
 * 0b0001.0000(1) * 0b1111.0000(-1) = 0b11110000.0000 >> _binalyPoint
 */
Fixed Fixed::operator*(const Fixed &other) const
{
  Fixed res;
  ssize_t val[3];

  val[0] = _rawBits;
  val[1] = other.getRawBits();

  val[2] = val[0] * val[1];
  res.setRawBits(val[2] / (1 << _binalyPoint));
  return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
  Fixed res;
  ssize_t divideFrom;

  if (other.getRawBits() == 0)
    throw std::range_error("Divided by zero.");
  divideFrom = _rawBits * (1 << _binalyPoint);
  res.setRawBits(divideFrom / other.getRawBits());
  return res;
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

bool Fixed::operator>(const Fixed &other) const
{
  return _rawBits > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) const
{
  return _rawBits < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) const
{
  return _rawBits >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const
{
  return _rawBits <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) const
{
  return _rawBits == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const
{
  return _rawBits != other.getRawBits();
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
  os << fixed.toFloat();
  return (os);
}

/*
** Members
*/

int Fixed::getRawBits(void) const { return _rawBits; }

void Fixed::setRawBits(int const raw) { _rawBits = raw; }

int Fixed::getBinalyPoint(void) const { return _binalyPoint; }

float Fixed::toFloat(void) const
{
  float f;

  f = static_cast<float>(_rawBits);
  f /= 1 << _binalyPoint;
  return f;
}

int Fixed::toInt(void) const { return _rawBits >> _binalyPoint; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  return a.getRawBits() <= b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  return a.getRawBits() >= b.getRawBits() ? a : b;
}
