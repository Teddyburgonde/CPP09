/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:22:19 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/09 22:34:18 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
/*
Étape 1 et 2 : Vérifier, convertir et ajouter dans vector et deque
Étape 3 : Former des paires
Étape 5 : Envoyer les mins dans final_vector

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

        
        // Étape 5 : Envoyer les mins dans final_vector
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
            final_vector.push_back(it->first); // Ajouter les mins (it->first) dans final_vector
            final_deque.push_back(it->first);
        }
        // mesurer le temps
        std::clock_t start_vector = std::clock();
        // Etape 5 bis : trie final_vector
        std::sort(final_vector.begin(), final_vector.end());
        // Etape 6 : Insertion des max dans final_vector
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
           // Insertion des max dans final_vector
           std::vector<int>::iterator pos_vector = std::lower_bound(final_vector.begin(), final_vector.end(), it->second);
           final_vector.insert(pos_vector, it->second);
        }
        std::clock_t end_vector = std::clock();
        double time_vector = 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;
           
        // mesurer le temps
        std::clock_t start_deque = std::clock();
         // Etape 5 bis : trie final_deque
        std::sort(final_deque.begin(), final_deque.end());
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
            std::deque<int>::iterator pos_deque = std::lower_bound(final_deque.begin(), final_deque.end(), it->second);
            final_deque.insert(pos_deque, it->second);
        }
        std::clock_t end_deque = std::clock();
        double time_deque = 1000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

        // gestion du -1
        std::vector<int>::const_iterator vec_it = final_vector.begin();
        std::deque<int>::const_iterator deque_it = final_deque.begin();
        if (*vec_it == -1)
        {
            final_vector.erase(vec_it);
            final_deque.erase(deque_it);
        }
        // Affichage du résultat final
        std::cout << "Final sorted vector:" << std::endl;
        for (std::vector<int>::const_iterator it = final_vector.begin(); it != final_vector.end(); ++it) 
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Final sorted deque:" << std::endl;
        for (std::deque<int>::const_iterator it = final_deque.begin(); it != final_deque.end(); ++it) 
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
          // Affichage des temps d'exécution
        std::cout << "Time to sort and insert using std::vector: " << time_vector << " ms" << std::endl;
        std::cout << "Time to sort and insert using std::deque: " << time_deque << " ms" << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
