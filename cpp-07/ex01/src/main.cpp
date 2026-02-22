#include <iostream>
#include <string>

#include "../include/iter.hpp"

void printInt(int &i) { std::cout << i << " "; }

void incrementInt(int &i) { i++; }

void printString(std::string &s) { std::cout << s << " "; }

template <typename T>
void printElement(T &x) {
  std::cout << "[" << x << "] ";
}

template <typename T>
void print(T const &x) {
  std::cout << x << std::endl;
  return;
}

int main(void) {
  std::cout << "=== Test 1: Integer Array ===" << std::endl;
  int intArray[] = {1, 2, 3, 4, 5};

  std::cout << "Original: ";
  iter(intArray, 5, printInt);
  std::cout << std::endl;

  std::cout << "Incrementing values..." << std::endl;
  iter(intArray, 5, incrementInt);

  std::cout << "Modified: ";
  iter(intArray, 5, printInt);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 2: String Array ===" << std::endl;
  std::string strArray[] = {"Hello", "World", "42", "C++"};

  std::cout << "Strings: ";
  iter(strArray, 4, printString);
  std::cout << std::endl << std::endl;

  return 0;
}
