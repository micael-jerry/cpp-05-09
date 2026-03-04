/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 06:14:15 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/22 08:49:26 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

#include "./MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const &other)
    : std::stack<T, Container>(other) {}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(
    MutantStack const &other) {
  if (this != &other) {
    std::stack<T, Container>::operator=(other);
  }
  return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cbegin() const {
  return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cend() const {
  return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() {
  return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend() {
  return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::crbegin() const {
  return this->c.crbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::crend() const {
  return this->c.crend();
}
