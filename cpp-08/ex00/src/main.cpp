/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 07:33:00 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/17 22:04:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "../include/easyfind.hpp"

template <typename T>
void printContainer(T& container, std::string const& name) {
  std::cout << "Content of " << name << ": { ";
  for (typename T::iterator it = container.begin(); it != container.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << "}" << std::endl;
}

template <typename T>
void testEasyFind(T& container, int toFind) {
  try {
    std::cout << "Searching for " << toFind << "... ";
    typename T::iterator result = easyfind(container, toFind);
    std::cout << "\033[32mFound!\033[0m Value pointed by iterator: " << *result << std::endl;
  } catch (std::exception& e) {
    std::cout << "\033[31mError:\033[0m " << e.what() << " (" << toFind << ")" << std::endl;
  }
}

int main(void) {
  {
    std::cout << "\n========== TEST WITH STD::VECTOR ==========" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) vec.push_back(i * 10);
    printContainer(vec, "Vector");
    testEasyFind(vec, 20); // Should succeed
    testEasyFind(vec, 42); // Should fail
  }

  {
    std::cout << "\n========== TEST WITH STD::LIST ==========" << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; i++) lst.push_back(i * 5);
    printContainer(lst, "List");
    testEasyFind(lst, 15); // Should succeed
    testEasyFind(lst, -5); // Should fail
  }

  {
    std::cout << "\n========== TEST WITH STD::DEQUE ==========" << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 5; i++) deq.push_front(i);
    printContainer(deq, "Deque");
    testEasyFind(deq, 3); // Should succeed
    testEasyFind(deq, 10); // Should fail
  }

  {
    std::cout << "\n========== TEST WITH CONST CONTAINER ==========" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) vec.push_back(i);
    const std::vector<int> constVec = vec; // Copy to make it const
    
    std::cout << "Content of Const Vector: { 0 1 2 3 4 }" << std::endl;
    
    try {
      std::cout << "Searching for 2 in const container... ";
      std::vector<int>::const_iterator result = easyfind(constVec, 2);
      std::cout << "\033[32mFound!\033[0m Value pointed by iterator: " << *result << std::endl;
    } catch (std::exception& e) {
      std::cout << "\033[31mError:\033[0m " << e.what() << std::endl;
    }
  }

  {
    std::cout << "\n========== TEST WITH EMPTY CONTAINER ==========" << std::endl;
    std::vector<int> emptyVec;
    printContainer(emptyVec, "Empty Vector");
    testEasyFind(emptyVec, 1); // Should fail
  }

  {
    std::cout << "\n========== TEST WITH DUPLICATES AND MUTATION ==========" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(20);
    vec.push_back(40);
    printContainer(vec, "Vector with duplicates");
    try {
      std::cout << "Searching for 20 (should return first occurrence)... ";
      std::vector<int>::iterator result = easyfind(vec, 20);
      std::cout << "\033[32mFound!\033[0m Value: " << *result << std::endl;
      
      std::cout << "Mutating the found value to 42..." << std::endl;
      *result = 42;
      printContainer(vec, "Vector after mutation");
    } catch (std::exception& e) {
      std::cout << "\033[31mError:\033[0m " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  return 0;
}
