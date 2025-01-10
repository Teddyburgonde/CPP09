/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:20:49 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/10 08:40:09 by tebandam         ###   ########.fr       */
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

void extractMins(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& vectorOut, std::deque<int>& dequeOut) 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) 
    {
        vectorOut.push_back(it->first); // Ajouter les mins (it->first) dans vectorOut
        dequeOut.push_back(it->first);  // Ajouter les mins (it->first) dans dequeOut
    }
}

void insertMaxs(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& sortedVector) 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) 
    {
        // Trouver la position d'insertion pour le "max" (it->second)
        std::vector<int>::iterator pos = std::lower_bound(sortedVector.begin(), sortedVector.end(), it->second);
        // Insérer le "max" à la position correcte
        sortedVector.insert(pos, it->second);
    }
}

void sortAndInsertMaxs(const std::vector<std::pair<int, int> >& pairs, std::deque<int>& sortedDeque) 
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

void removeMinusOne(std::vector<int>& vector, std::deque<int>& deque) 
{
    // Vérifier si le premier élément est -1 dans les deux conteneurs
    if (!vector.empty() && vector.front() == -1)
        vector.erase(vector.begin()); // Supprimer -1 du vecteur

    if (!deque.empty() && deque.front() == -1)
        deque.erase(deque.begin()); // Supprimer -1 du deque
}

template <typename Container>
void printResults(const Container& container, const std::string& label) 
{
    std::cout << label << std::endl;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


