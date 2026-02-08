/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 07:33:00 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/08 08:36:23 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "../include/easyfind.hpp"

#define CONTAINER_TEST_MAX 5

template <typename T>
void printContainer(T& container, std::string const& name) {
  std::cout << "Content of " << name << ": ";
  for (typename T::iterator it = container.begin(); it != container.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void testEasyFind(T& container, int toFind) {
  try {
    typename T::iterator result = easyfind(container, toFind);
    std::cout << "Found: " << *result << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

int main(void) {
  {
    std::cout << "=== VECTOR ===" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < CONTAINER_TEST_MAX; i++) vec.push_back(i);
    printContainer(vec, "Vector");
    testEasyFind(vec, 1);
    testEasyFind(vec, 10);
    std::cout << std::endl;
  }

  {
    std::cout << "=== LIST ===" << std::endl;
    std::list<int> lst;
    for (int i = 0; i < CONTAINER_TEST_MAX; i++) lst.push_back(i);
    printContainer(lst, "List");
    testEasyFind(lst, 2);
    testEasyFind(lst, -2);
    std::cout << std::endl;
  }

  {
    std::cout << "=== DEQUE ===" << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < CONTAINER_TEST_MAX; i++) deq.push_back(i);
    printContainer(deq, "Deque");
    testEasyFind(deq, 3);
    testEasyFind(deq, 100);
    std::cout << std::endl;
  }

  return 0;
}
