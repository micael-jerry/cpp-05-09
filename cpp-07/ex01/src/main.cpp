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
  int len = sizeof(intArray) / sizeof(int);

  std::cout << "Original: ";
  iter(intArray, len, printInt);
  std::cout << std::endl;

  std::cout << "Incrementing values..." << std::endl;
  iter(intArray, len, incrementInt);

  std::cout << "Modified: ";
  iter(intArray, len, printInt);
  std::cout << std::endl << std::endl;

  std::cout << "=== Test 2: String Array ===" << std::endl;
  std::string strArray[] = {"Hello", "World", "42", "C++"};
  int strLen = sizeof(strArray) / sizeof(std::string);

  std::cout << "Strings: ";
  iter(strArray, strLen, printString);
  std::cout << std::endl << std::endl;

  return 0;
}
