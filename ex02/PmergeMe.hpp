#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <utility>
#include <algorithm>


bool isValidNumber(const std::string& str);
void processInputs(int argc, char* argv[], std::vector<int>& vector, std::deque<int>& deque);
void createPairs(const std::vector<int>& inputVector, std::vector<std::pair<int, int> >& pairs);
void extractMins(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& vectorOut, std::deque<int>& dequeOut);
void insertMaxs(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& sortedVector);
void sortAndInsertMaxs(const std::vector<std::pair<int, int> >& pairs, std::deque<int>& sortedDeque);
void removeMinusOne(std::vector<int>& vector, std::deque<int>& deque);

template <typename Container>
void printResults(const Container& container, const std::string& label);

#endif
