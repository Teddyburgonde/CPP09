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


bool isValidNumber(const std::string& str);
void processInputs(int argc, char* argv[], std::vector<int>& vector, std::deque<int>& deque);
void createPairs(const std::vector<int>& inputVector, std::vector<std::pair<int, int> >& pairs);

#endif
