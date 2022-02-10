/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:22:11 by ywake             #+#    #+#             */
/*   Updated: 2022/02/10 16:21:36 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

void subject(void)
{
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;

  std::cout << a << std::endl;
  std::cout << b << std::endl;

  std::cout << Fixed::max( a, b ) << std::endl;
}

void myTest(void)
{
  Fixed a(5.05f);
  Fixed const b(2);

  std::cout << std::endl << "myTest" << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  std::cout << "(a > b): " << (a > b) << std::endl;
  std::cout << "(a < b): " << (a < b) << std::endl;
  std::cout << "(a >= b): " << (a >= b) << std::endl;
  std::cout << "(a <= b): " << (a <= b) << std::endl;
  std::cout << "(a == b): " << (a == b) << std::endl;
  std::cout << "(a != b): " << (a != b) << std::endl;

  std::cout << "min: " << Fixed::min( a, b ) << std::endl;
}

int main()
{
  subject();
  myTest();
  return 0;
}
