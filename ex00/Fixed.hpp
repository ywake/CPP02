/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:08:27 by ywake             #+#    #+#             */
/*   Updated: 2022/02/10 12:55:23 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
  static const int _width = 8;
  int _rawBits;

public:
  Fixed(void);
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &copy);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
