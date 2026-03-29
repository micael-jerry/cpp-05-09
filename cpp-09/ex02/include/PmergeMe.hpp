/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:59:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/28 20:36:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <exception>
#include <string>
#include <vector>

class PmergeMeException : public std::exception {
 private:
  std::string _msg;

 public:
  PmergeMeException(const std::string &msg) : _msg("ERROR: " + msg) {}
  virtual ~PmergeMeException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }
};

namespace pMergeMe {
bool isPositiveNumberStr(const std::string &str);
void argsValidator(int ac, const char *av[]);
std::vector<long> parseArgs(int ac, const char *av[]);
void printContainer(const std::vector<long> &container);

void mergeInsertSort(std::vector<long> &container);
}  // namespace pMergeMe

#endif