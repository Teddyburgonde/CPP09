/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:20:49 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/09 22:33:56 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Checks whether a string is a positive integer
bool isValidNumber(const std::string& str) 
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

void processInputs(int argc, char* argv[], std::vector<int>& vector, std::deque<int>& deque) 
{
    for (int i = 1; i < argc; ++i) 
    {
        std::string arg = argv[i];

        // Vérifier avec la fonction isValidNumber
        if (isValidNumber(arg)) 
        {
            // Convertir l'argument en entier
            int num = std::atoi(arg.c_str());
            vector.push_back(num); // Ajouter dans vector
            deque.push_back(num);  // Ajouter dans deque
        }
    }
}

void createPairs(const std::vector<int>& inputVector, std::vector<std::pair<int, int> >& pairs) 
{
    for (size_t i = 0; i < inputVector.size(); i += 2) 
    {
        int a = inputVector[i];
        int b;
        if (i + 1 < inputVector.size())
            b = inputVector[i + 1];
        else 
            b = -1;
        pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b))); // Créer une paire (min, max)
    }
}
