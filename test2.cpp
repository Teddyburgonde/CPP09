

#include <ctime> // Pour std::clock
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
        std::deque<int> final_deque;

        // Vérifier si argv[1] demande des nombres aléatoires
        if (std::string(argv[1]) == "random") 
        {
            int count = (argc > 2) ? std::atoi(argv[2]) : 100; // Nombre de nombres à générer
            int range = (argc > 3) ? std::atoi(argv[3]) : 1000; // Plage des nombres

            if (count <= 0 || range <= 0) {
                throw std::runtime_error("Error: Invalid count or range for random generation.");
            }

            std::srand(std::time(0)); // Initialisation de la graine pour les nombres aléatoires
            for (int i = 0; i < count; ++i) 
            {
                int num = std::rand() % range;
                vector.push_back(num);
                deque.push_back(num);
            }
        } 
        else 
        {
            // Sinon, lire les nombres depuis argv
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

        // Reste du code pour former des paires, trier et insérer...

        // Étape 3 : Former des paires
        for (size_t i = 0; i < vector.size(); i += 2) 
        {
            int a = vector[i];
            int b = (i + 1 < vector.size()) ? vector[i + 1] : -1;
            even.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
        }

        // Étape 5 : Envoyer les mins dans final_vector et final_deque
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
            final_vector.push_back(it->first);
            final_deque.push_back(it->first);
        }

        // Mesurer le temps pour le tri de final_vector
        std::clock_t start_vector = std::clock();
        std::sort(final_vector.begin(), final_vector.end());
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
            std::vector<int>::iterator pos_vector = std::lower_bound(final_vector.begin(), final_vector.end(), it->second);
            final_vector.insert(pos_vector, it->second);
        }
        std::clock_t end_vector = std::clock();
        double time_vector = 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;

        // Mesurer le temps pour le tri de final_deque
        std::clock_t start_deque = std::clock();
        std::sort(final_deque.begin(), final_deque.end());
        for (std::vector<std::pair<int, int> >::const_iterator it = even.begin(); it != even.end(); ++it) 
        {
            std::deque<int>::iterator pos_deque = std::lower_bound(final_deque.begin(), final_deque.end(), it->second);
            final_deque.insert(pos_deque, it->second);
        }
        std::clock_t end_deque = std::clock();
        double time_deque = 1000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

        // Affichage des résultats
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
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
