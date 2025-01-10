/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:22:19 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/10 08:42:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
/*
Étape 1 et 2 : Vérifier, convertir et ajouter dans vector et deque
Étape 3 : Former des paires
Étape 5 : Envoyer les mins dans final_vector
Etape 6 : Insertion des max dans final_vector;
Etape 7 : gestion du -1;

*/
int main(int argc, char* argv[]) 
{
    try 
    {
        if (argc < 2)
            throw std::runtime_error("Error: No input provided.");

        // List of containers
        std::vector<int> vector;
        std::deque<int> deque;
        std::vector<std::pair<int, int> > even;
        std::vector<int> final_vector;
        std::deque<int> final_deque;

        // Étape 1 et 2 : Vérifier, convertir et ajouter dans vector et deque
        processInputs(argc, argv, vector, deque);

        // Étape 3 : Former des paires
        createPairs(vector, even);

        // Étape 5 : Envoyer les mins dans final_vector et final_deque
        extractMins(even, final_vector, final_deque);
        
        // mesurer le temps
        clock_t start_vector = clock();
  
        // Etape 5 bis : trie final_vector
        std::sort(final_vector.begin(), final_vector.end());
        
        // Etape 6 : Insertion des max dans final_vector
        insertMaxs(even, final_vector);
        
        // mesurer le temps
        clock_t end_vector = clock();
        double time_vector = 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;
           
        // mesurer le temps
        clock_t start_deque = clock();
        
        // Etape 5 bis : trie final_deque
        sortAndInsertMaxs(even, final_deque);

        // mesurer le temps
        clock_t end_deque = clock();
        double time_deque = 1000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

        // Etape 7 : gestion du -1
        removeMinusOne(final_vector, final_deque);
        
        // Etape 8 : Affichage du résultat final
        printResults(final_vector, "Final sorted vector:");
        printResults(final_deque, "Final sorted deque:");
        std::cout << std::endl;
        
        // Etape 9 : Affichage du temps
        std::cout << "Time to sort and insert using std::vector: " << time_vector << " ms" << std::endl;
        std::cout << "Time to sort and insert using std::deque: " << time_deque << " ms" << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
