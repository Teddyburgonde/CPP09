## CPP09

# ex00

# Utilisation de map 

Map est un conteneur avec un principe de clef value. <br>
Aussi c'est un conteneur qui s'alloue automatiquement. <br>
Map est un contener qui est automatiquement triée en ordre croissant. <br>

Exemple : 

```cpp
#include <iostream> 
#include <map> // Include nécessaire pour utiliser map

int	main()
{
	// Declaration d'un conteneur map
	std::map<std::string, double> students;
	
	// Initialisation de map 
	students["Pierre"] = 20.0;
	students["Jean"] = 10.0;
	students["Alice"] = 14.0; // Alice est en premiere position dans la map
	
	// map n'est pas indexées donc ne pas faire cela❗
	/* 
	for (int i = 0; i < students.size(); i++)
	{
		std::cout << students << std::endl;
	}
	*/

	/* Utilisation d'un iterator pour imprimer les valeurs de map */
	
	// Creation d'un type iterator qui peut parcourir un map de ce type.
	std::map<std::string, double>::iterator it; 
	
	// Iterator pointe vers le premier élément de la map.
	for(it = students.begin(); it != students.end(); ++it)
	{
		// Accède à la clé avec it->first  
		// Accède à la valeur associée à la clé it->second 
		std::cout << it->first << " a eu " << it->second << std::endl;
	}
	// La taille de map
	std::cout << "Le nombre de students dans le conteneur : " << students.size() << std::endl;
}
```

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

```c
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

```

# ex01

# Utilisation de stack 

```c
int	main()
{
	std::stack<float> stk;
	float a;
	float b;

	a = 10.5;
	b = 15.5;

	if (stk.empty())
    	std::cout << "La pile est vide !" << std::endl;
	
	stk.push(a);
	// on a push a dans la stack et comme il est seul il est tout en haut de la pile.
	
	std::cout << "La pile contient : " << stk.size() << " éléments." << std::endl;
	stk.push(b);
	/*
		Maintenant apres ce push c'est b qui est tout en haut de la pile.
		Il faut imaginer que c'est comme une pile d'assiette,
		la derniere arriver est au dessus.
	*/

	std::cout << "le sommet de la pile est : " << stk.top() << std::endl;

	std::cout << "La pile contient : " << stk.size() << " éléments." << std::endl;
	// On retire le sommet de la pile
	stk.pop();

	std::cout << "le sommet de la pile est : " << stk.top() << std::endl;
}
```
