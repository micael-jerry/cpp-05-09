/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 05:07:02 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/21 05:21:40 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "../include/whatever.hpp"

class Awesome {
public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome const & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void) {
  std::cout << "=== Subject Tests ===" << std::endl;
  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  std::cout << "\n=== Custom Class Tests ===" << std::endl;
  Awesome aw1(2);
  Awesome aw2(4);

  ::swap(aw1, aw2);
  std::cout << "aw1 = " << aw1 << ", aw2 = " << aw2 << std::endl;
  std::cout << "min( aw1, aw2 ) = " << ::min(aw1, aw2) << std::endl;
  std::cout << "max( aw1, aw2 ) = " << ::max(aw1, aw2) << std::endl;

  std::cout << "\n=== Double Tests ===" << std::endl;
  double d1 = 4.2;
  double d2 = 21.42;

  ::swap(d1, d2);
  std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
  std::cout << "min( d1, d2 ) = " << ::min(d1, d2) << std::endl;
  std::cout << "max( d1, d2 ) = " << ::max(d1, d2) << std::endl;

  std::cout << "\n=== Char Tests ===" << std::endl;
  char c1 = 'z';
  char c2 = 'a';

  ::swap(c1, c2);
  std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
  std::cout << "min( c1, c2 ) = " << ::min(c1, c2) << std::endl;
  std::cout << "max( c1, c2 ) = " << ::max(c1, c2) << std::endl;

  return 0;
}