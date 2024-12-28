## CPP09

# ex00

J'ai utilisé une map pour stocker chaque parti :

2009-01-02,0

Après la séparation a la virgule :

date = 2009-01-02
rate = 0

Si on passe par un iterator
it->first sera égal a la valeur de date.
it->second sera égal a la valeur de rate.

Parsing :

J'ai fait un parsing sur la date et rate. 
bool isValidDate(const std::string &date, std::string &errorMessage);
bool isValidRate(const std::string& rate, std::string &errorMessage);

La fonction processInputFile : 

1. Ouvrir le fichier d'entrée
std::ifstream

2. Lire le fichier ligne par ligne
std::getline

3. Separer la date et la valeur 
std::isstringstream iss
std::getline;

4. Nettoyer les espaces inutiles
Créer une function trim.

5. Valider la date
isValidDate
 
6. Vaider la rate 
isValidRate

7. Convertir la valeur en nombre.

8. Trouver la date correspondante dans les donnes bitcoin.

9. Calculer la valeur du Bitcoin
echangeRate * rate;

10. Afficher le résultat.

11. Fermer le fichier. 
