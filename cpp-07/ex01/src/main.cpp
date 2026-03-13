#include <iostream>
#include <string>

#include "../include/iter.hpp"

class Awesome {
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }
private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

// Non-const integer printing function
void printInt(int &i) { std::cout << i << " "; }

// Const integer printing function
void printConstInt(int const &i) { std::cout << i << " "; }

// Integer modifying function
void incrementInt(int &i) { i++; }

// String printing function
void printString(std::string const &s) { std::cout << s << " "; }

// Template printing function (const reference)
template <typename T>
void printConstTemplate(T const &x) {
  std::cout << "[" << x << "] ";
}

// Template printing function (non-const reference)
template <typename T>
void printNonConstTemplate(T &x) {
  std::cout << "{" << x << "} ";
}

template <typename T>
void print(T const & x) {
    std::cout << x << " ";
}

int main(void) {
  std::cout << "=== Test 1: Non-const Integer Array ===" << std::endl;
  int intArray[] = {1, 2, 3, 4, 5};

  std::cout << "Original: ";
  iter(intArray, 5, printInt);
  std::cout << std::endl;

  std::cout << "Incrementing values..." << std::endl;
  iter(intArray, 5, incrementInt);

  std::cout << "Modified (print int with printConstInt): ";
  iter(intArray, 5, printConstInt);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 2: Const Integer Array ===" << std::endl;
  int const constIntArray[] = {10, 20, 30, 40, 50};

  std::cout << "Const Array: ";
  iter(constIntArray, 5, printConstInt);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 3: String Array ===" << std::endl;
  std::string strArray[] = {"Hello", "World", "42", "C++"};

  std::cout << "Strings: ";
  iter(strArray, 4, print<std::string>);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 4: Template Function (Non-const) ===" << std::endl;
  iter(intArray, 5, printNonConstTemplate<int>);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 5: Template Function (Const array) ===" << std::endl;
  iter(constIntArray, 5, printConstTemplate<int>);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 6: Class Objects ===" << std::endl;
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter(tab, 5, print<int>);
  std::cout << std::endl;
  iter(tab2, 5, print<Awesome>);
  std::cout << std::endl;

  return 0;
}
