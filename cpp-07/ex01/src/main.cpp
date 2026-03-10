#include <iostream>
#include <string>

#include "../include/iter.hpp"

// Non-const integer printing function
void printInt(int &i) { std::cout << i << " "; }

// Const integer printing function
void printConstInt(int const &i) { std::cout << i << " "; }

// Integer modifying function
void incrementInt(int &i) { i++; }

// String printing function
void printString(std::string &s) { std::cout << s << " "; }

// Template printing function
template <typename T>
void printTemplate(T &x) {
  std::cout << "[" << x << "] ";
}

class Awesome {
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }
private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

int main(void) {
  std::cout << "=== Test 1: Non-const Integer Array ===" << std::endl;
  int intArray[] = {1, 2, 3, 4, 5};

  std::cout << "Original: ";
  iter(intArray, 5, printInt);
  std::cout << std::endl;

  std::cout << "Incrementing values..." << std::endl;
  iter(intArray, 5, incrementInt);

  std::cout << "Modified: ";
  iter(intArray, 5, printInt);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 2: Const Integer Array ===" << std::endl;
  int const constIntArray[] = {10, 20, 30, 40, 50};

  std::cout << "Const Array: ";
  iter(constIntArray, 5, printConstInt);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 3: String Array ===" << std::endl;
  std::string strArray[] = {"Hello", "World", "42", "C++"};

  std::cout << "Strings: ";
  iter(strArray, 4, printString);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 4: Template Function (Non-const) ===" << std::endl;
  iter(intArray, 5, printTemplate);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 5: Template Function (Const) ===" << std::endl;
  iter(constIntArray, 5, printTemplate);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 6: Class Objects ===" << std::endl;
  Awesome tab[5];
  iter(tab, 5, printTemplate);
  std::cout << std::endl;

  return 0;
}
