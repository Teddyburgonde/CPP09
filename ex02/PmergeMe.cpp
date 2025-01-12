/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:20:49 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/12 08:52:31 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()  : time_vector(0), time_deque(0), start_vector(0), end_vector(0), start_deque(0), end_deque(0)
{
   
}

PmergeMe::~PmergeMe() 
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : vector(other.vector), deque(other.deque), even(other.even), 
      final_vector(other.final_vector), final_deque(other.final_deque),
      time_vector(other.time_vector), time_deque(other.time_deque),
      start_vector(other.start_vector), end_vector(other.end_vector),
      start_deque(other.start_deque), end_deque(other.end_deque) 
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other) {
        vector = other.vector;
        deque = other.deque;
        even = other.even;
        final_vector = other.final_vector;
        final_deque = other.final_deque;
        time_vector = other.time_vector;
        time_deque = other.time_deque;
        start_vector = other.start_vector;
        end_vector = other.end_vector;
        start_deque = other.start_deque;
        end_deque = other.end_deque;
    }
    return *this;
}


// Checks whether a string is a positive integer
bool PmergeMe::isValidNumber(const std::string& str) 
{
    if (str.empty())
        throw std::runtime_error("Error: Empty string is not a valid number.");
    for (size_t i = 0; i < str.size(); ++i) 
    {
        if (!isdigit(str[i]))
            throw std::runtime_error("Error");
    }
    return true;
}

void PmergeMe::processInputs(int argc, char* argv[]) 
{
    for (int i = 1; i < argc; ++i) 
    {
        std::string arg = argv[i];

        if (isValidNumber(arg)) 
        {
            int num = std::atoi(arg.c_str());
            vector.push_back(num);
            deque.push_back(num);
        }
    }
}

void PmergeMe::createPairs() 
{
    for (size_t i = 0; i < vector.size(); i += 2) 
    {
        int a = vector[i];
        int b;
        if (i + 1 < vector.size())
            b = vector[i + 1];
        else 
            b = -1;
        even.push_back(std::make_pair(std::min(a, b), std::max(a, b))); // Créer une paire (min, max)
    }
}

void PmergeMe::extractMins() 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
    {
        final_vector.push_back(it->first);
        final_deque.push_back(it->first);
    }
}

void PmergeMe::insertMaxs() 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
    {
        std::vector<int>::iterator pos = std::lower_bound(final_vector.begin(), final_vector.end(), it->second);
        final_vector.insert(pos, it->second);
    }
}

void PmergeMe::sortAndInsertMaxs() 
{
    std::sort(final_deque.begin(), final_deque.end());

    for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
    {
        std::deque<int>::iterator pos = std::lower_bound(final_deque.begin(), final_deque.end(), it->second);
        final_deque.insert(pos, it->second);
    }
}

void PmergeMe::removeMinusOne()
{
    if (!final_vector.empty() && final_vector.front() == -1)
        final_vector.erase(final_vector.begin());

    if (!final_deque.empty() && final_deque.front() == -1)
        final_deque.erase(final_deque.begin());
}

void PmergeMe::startVectorTimer() 
{
    start_vector = clock();
}

void PmergeMe::stopVectorTimer() 
{
    end_vector = clock();
    time_vector = 1000000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;
}

void PmergeMe::startDequeTimer() 
{
    start_deque = clock();
}

void PmergeMe::stopDequeTimer() 
{
    end_deque = clock();
    time_deque = 1000000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;
}

void PmergeMe::sortFinalVector() 
{
    std::sort(final_vector.begin(), final_vector.end());
}

void PmergeMe::displayFinalResults() const 
{
    std::cout << "After sorted vector: ";
    for (std::vector<int>::const_iterator it = final_vector.begin(); it != final_vector.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After sorted deque: ";
    for (std::deque<int>::const_iterator it = final_deque.begin(); it != final_deque.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayExecutionTime() const 
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to sort and insert using std::vector: " << time_vector << " us" << std::endl;
    std::cout << "Time to sort and insert using std::deque: " << time_deque << " us" << std::endl;
}
