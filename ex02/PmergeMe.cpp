/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:20:49 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/10 14:01:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
}

PmergeMe::~PmergeMe() 
{
}

PmergeMe::PmergeMe(const PmergeMe& other) 
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other) 
    {
        this->vector = other.vector;
        this->deque = other.deque;
        this->even = other.even;
        this->final_vector = other.final_vector;
        this->final_deque = other.final_deque;
        this->time_vector = other.time_vector;
        this->time_deque = other.time_deque;
        this->start_vector = other.start_vector;
        this->end_vector = other.end_vector;
        this->start_deque = other.start_deque;
        this->end_deque = other.end_deque;
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
            throw std::runtime_error("Error: Non-numeric character found in input: " + str);
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
    for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != pairs.end(); ++it) 
    {
        vector.push_back(it->first); // Ajouter les mins (it->first) dans vectorOut
        deque.push_back(it->first);  // Ajouter les mins (it->first) dans dequeOut
    }
}

void PmergeMe::insertMaxs() 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
    {
        // Trouver la position d'insertion pour le "max" (it->second)
        std::vector<int>::iterator pos = std::lower_bound(final_vector.begin(), final_vector.end(), it->second);
        // Insérer le "max" à la position correcte
        final_vector.insert(pos, it->second);
    }
}

void sortAndInsertMaxs() 
{
    // Trier le deque
    std::sort(sortedDeque.begin(), sortedDeque.end());

    // Insérer les "max" des paires
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) 
    {
        // Trouver la position d'insertion pour le "max" (it->second)
        std::deque<int>::iterator pos = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), it->second);
        // Insérer le "max" à la position correcte
        sortedDeque.insert(pos, it->second);
    }
}

void removeMinusOne()
{
    // Vérifier si le premier élément est -1 dans les deux conteneurs
    if (!vector.empty() && vector.front() == -1)
        vector.erase(vector.begin()); // Supprimer -1 du vecteur

    if (!deque.empty() && deque.front() == -1)
        deque.erase(deque.begin()); // Supprimer -1 du deque
}



