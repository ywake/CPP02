/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:22:11 by ywake             #+#    #+#             */
/*   Updated: 2022/03/09 14:04:12 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void subject(void)
{
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;

  std::cout << a << std::endl;
  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;
}

void myTest(Fixed a, Fixed b)
{
  std::cout << std::endl << "myTest" << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl << std::endl;

  std::cout << "++a: " << ++a << std::endl;
  std::cout << "--a: " << --a << std::endl;
  std::cout << "a++: " << a++ << std::endl;
  std::cout << "a--: " << a-- << std::endl;
  std::cout << "a: " << a << std::endl << std::endl;

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl << std::endl;

  std::cout << "a + b: " << a + b << std::endl;
  std::cout << "a - b: " << a - b << std::endl;
  std::cout << "a * b: " << a * b << std::endl;
  std::cout << "a / b: " << a / b << std::endl;
  try {
    std::cout << "a / 0: " << a / 0 << std::endl << std::endl;
  } catch (const std::range_error &e) {
    std::cout << e.what() << std::endl << std::endl;
  }

  // 1.1 / -0.3 : 0.000000;

  std::cout << "(a > b): " << (a > b) << std::endl;
  std::cout << "(a < b): " << (a < b) << std::endl;
  std::cout << "(a >= b): " << (a >= b) << std::endl;
  std::cout << "(a <= b): " << (a <= b) << std::endl;
  std::cout << "(a == b): " << (a == b) << std::endl;
  std::cout << "(a != b): " << (a != b) << std::endl << std::endl;

  std::cout << "min: " << Fixed::min(a, b) << std::endl;
}

int main()
{
  subject();
  myTest(Fixed(5.0f), Fixed(2));
  std::cout << std::endl;
  std::cout << "1.1 * -0.3 = " << Fixed(1.1f) * Fixed(-0.3f) << std::endl;
  std::cout << "10.004 * -1 = " << Fixed(10.004f) * Fixed(-1) << std::endl;
  std::cout << "10.004 * -0.8 = " << Fixed(10.004f) * Fixed(-0.8f) << std::endl;
  std::cout << "-10.004 * 0.8 = " << Fixed(-10.004f) * Fixed(0.8f) << std::endl;
  std::cout << "1.1 / -0.3 = " << Fixed(1.1f) / Fixed(-0.3f) << std::endl;
  std::cout << "10.004 / -2 = " << Fixed(10.004f) / Fixed(-2) << std::endl;
  std::cout << "-10.004 / 2 = " << Fixed(-10.004f) / Fixed(2) << std::endl;
  return 0;
}
