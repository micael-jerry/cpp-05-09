/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:59:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/04/03 05:06:10 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define NO_STRUGGLER -1

#include <exception>
#include <string>
#include <utility>
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

std::vector<std::pair<long, long> > extractPairs(
    const std::vector<long> &container);
void sortPairs(std::vector<std::pair<long, long> > &pairs);
std::pair<std::vector<long>, std::vector<long> > extractMainAndPendingChain(
    std::vector<std::pair<long, long> > pairs);
size_t getJacobsthalNumber(size_t n);
std::vector<long> insertPendingElements(std::vector<long> mainChain,
                                        std::vector<long> pendingChain,
                                        long struggler);
std::vector<long> mergeInsertSort(std::vector<long> &container);
}  // namespace pMergeMe

#endif