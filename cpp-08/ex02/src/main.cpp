/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 06:12:53 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/17 22:04:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "../include/MutantStack.hpp"

int main(void) {
  std::cout << "\n========== TEST 1: SUBJECT TEST (MutantStack) ==========" << std::endl;
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Stack contents: " << std::endl;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }

  std::cout << "\n========== TEST 2: EXPECTED BEHAVIOR WITH std::list ==========" << std::endl;
  std::cout << "(Should display exactly the same results as TEST 1)" << std::endl;
  {
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Top (back): " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    std::cout << "List contents: " << std::endl;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }

  std::cout << "\n========== TEST 3: DIFFERENT ITERATORS ==========" << std::endl;
  {
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++) {
        mstack.push(i * 10);
    }
    
    std::cout << "Normal iterator (bottom to top): ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse iterator (top to bottom): ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << "Const iterator: ";
    const MutantStack<int> const_mstack = mstack;
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\n========== TEST 4: CONST REVERSE ITERATOR ==========" << std::endl;
  {
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++) mstack.push(i);
    const MutantStack<int> const_mstack = mstack;
    std::cout << "Const reverse iterator (top to bottom): ";
    for (MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin(); crit != const_mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\n========== TEST 5: STD::STACK METHODS ==========" << std::endl;
  {
    MutantStack<int> stackMethods;
    std::cout << "Is empty initially? " << (stackMethods.empty() ? "Yes" : "No") << std::endl;
    stackMethods.push(99);
    std::cout << "Pushed 99. Is empty? " << (stackMethods.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << stackMethods.size() << std::endl;
    stackMethods.pop();
    std::cout << "Popped. Is empty? " << (stackMethods.empty() ? "Yes" : "No") << std::endl;
  }
  std::cout << std::endl;

  return 0;
}