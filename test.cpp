#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib> // Pour std::atoi
#include <cctype>  // Pour isdigit
#include <stdexcept> // Pour std::runtime_error
#include <utility> // Pour std::pair
#include <algorithm>

// Fonction pour vérifier si une chaîne est un entier positif
bool isValidNumber(const std::string& str) {
    if (str.empty()) {
        throw std::runtime_error("Error: Empty string is not a valid number.");
    }
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            throw std::runtime_error("Error: Non-numeric character found in input: " + str);
        }
    }
    return true;
}

// Fonction pour afficher les paires
void printPairs(const std::vector<std::pair<int, int> >& pairs) 
{
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
    }
}

int main(int argc, char* argv[]) 
{
    try 
    {
        if (argc < 2) {
            throw std::runtime_error("Error: No input provided.");
        }

        std::vector<int> vector; // Conteneur pour les chiffres
        std::deque<int> deque;   // Conteneur pour les chiffres
        std::vector<std::pair<int, int> > even; // Conteneur pour les paires
        std::vector<int> final_vector;
        std::vector<int> final_deque;

        // Étape 1 et 2 : Vérifier, convertir et ajouter dans vector et deque
        for (int i = 1; i < argc; ++i) 
        {
            std::string arg = argv[i];

            // Vérifier avec la fonction isValidNumber
            if (isValidNumber(arg)) {
                // Convertir l'argument en entier
                int num = std::atoi(arg.c_str());
                vector.push_back(num); // Ajouter dans vector
                deque.push_back(num);  // Ajouter dans deque
            }
        }

        // Étape 3 : Former des paires
        for (size_t i = 0; i < vector.size(); i += 2) 
        {
            int a = vector[i];
            int b = (i + 1 < vector.size()) ? vector[i + 1] : 0; // Gérer les cas impairs
            even.push_back(std::make_pair(std::min(a, b), std::max(a, b))); // Créer une paire (min, max)
        }

        // Affichage des paires
        std::vector<std::pair<int, int> >::const_iterator it = even.begin();
        std::vector<int>::iterator itt = final_vector.begin();

        // Étape 5 : Envoyer les mins dans final_vector
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
            final_vector.push_back(it->first); // Ajouter les mins (it->first) dans final_vector
            final_deque.push_back(it->first);
        }
        // Etape 5 bis : trie final_vector
        std::sort(final_vector.begin(), final_vector.end());
        std::sort(final_deque.begin(), final_deque.end());

        // Affichage des mins vector
        std::cout << "Mins in final_vector:" << std::endl;
        for (std::vector<int>::const_iterator it = final_vector.begin(); it != final_vector.end(); ++it) 
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        // Affichage des mins deque
        std::cout << "Mins in final_deque:" << std::endl;
        for (std::vector<int>::const_iterator it = final_deque.begin(); it != final_deque.end(); ++it) 
        {
            std::cout << *it << " ";
        }
        printPairs(even);
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1; // Retourne une erreur si une exception est levée
    }

    return 0;
}

