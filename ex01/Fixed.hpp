/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:08:27 by ywake             #+#    #+#             */
/*   Updated: 2022/02/10 14:32:22 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
private:
  static const int _binalyPoint = 8;
  int _rawBits;

public:
  Fixed(void);
  Fixed(const Fixed &copy);
  Fixed(const int integer);
  Fixed(const float fraction);

  ~Fixed();

  Fixed &operator=(const Fixed &copy);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat( void ) const;
  int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
