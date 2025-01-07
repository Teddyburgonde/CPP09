// Fonction pour afficher les paires
void printPairs(const std::vector<std::pair<int, int> >& pairs) {
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
    }
}
