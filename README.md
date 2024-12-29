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
# ex01

# Guide pour Réussir l’Exercice Reverse Polish Notation (RPN)

Ce guide vise à vous aider à résoudre rapidement et efficacement l’exercice sur la **Reverse Polish Notation (RPN)**. Suivez les étapes ci-dessous et évitez les erreurs courantes.

---

## 1. Comprendre l’Exercice
- **Objectif :** Écrire un programme qui évalue une expression mathématique en notation polonaise inversée (RPN).
- **Principes :**
  - Les opérandes (nombres) sont empilés dans une structure de pile (stack).
  - Les opérateurs (`+`, `-`, `*`, `/`) appliquent des opérations sur les deux derniers éléments de la pile.

---

## 2. Architecture du Code

### 2.1 Classe **RPN**

#### Constructeurs et Destructeurs
- **`RPN::RPN()`** et **`RPN::~RPN()`** : Constructeur et destructeur par défaut.
- **`RPN::RPN(const RPN &other)`** : Constructeur de copie (inutile dans cet exercice mais inclus pour le respect des règles).
- **`RPN &RPN::operator=(const RPN &other)`** : Opérateur d’affectation.

#### Fonction Principale : `calculateRPN`
- **Entrée :** Une chaîne de caractères contenant l’expression RPN.
- **Sortie :** Le résultat final sous forme de `float`.
- **Logique :**
  - Parcourir les tokens (mots ou caractères) de l’expression.
  - Empiler les nombres.
  - Appliquer les opérateurs sur les deux derniers nombres empilés.
  - Retourner le résultat final.

---

## 3. Fonctions Importantes

### 3.1 **`stringToFloat`**
- Convertit une chaîne de caractères en `float`.
- Lève une exception en cas de format invalide.
- Exemple :
  ```cpp
  float value = stringToFloat("3.14"); // Retourne 3.14
  ```

### 3.2 **`isOperator`**
- Vérifie si un caractère est un opérateur valide (`+`, `-`, `*`, `/`).
- Retourne `true` ou `false`.

### 3.3 **`performOperation`**
- Applique un opérateur (également appelé "operation") sur deux opérandes.
- Gestion des cas spéciaux comme la division par zéro.
- Exemple :
  ```cpp
  float result = performOperation(5, 2, '*'); // Retourne 10
  ```

### 3.4 **`isValidNumber`**
- Vérifie si une chaîne représente un nombre valide.
- Retourne `true` ou `false`.

### 3.5 **`validateToken`**
- Vérifie si un token est soit un nombre valide, soit un opérateur valide.
- Lève une exception en cas d’erreur.
- Exemple :
  ```cpp
  validateToken("3.14"); // OK
  validateToken("abc"); // Lève une exception
  ```

---

## 4. Étapes Clés du Programme
1. **Lire l’expression :**
   - Utilise `std::istringstream` pour lire les tokens de la chaîne d’expression.

2. **Valider chaque token :**
   - Utilise `validateToken` pour éviter les erreurs (ex. : caractères non valides).

3. **Traiter les nombres et les opérateurs :**
   - **Nombres :** Empile-les dans la pile.
   - **Opérateurs :**
     - Dépile les deux derniers nombres.
     - Applique l’opération.
     - Empile le résultat.

4. **Vérifier la pile :**
   - En fin de traitement, la pile doit contenir exactement un élément (le résultat).
   - Sinon, lève une exception pour signaler une expression invalide.

---

## 5. Cas d’Utilisation

### Exemple 1 : **Expression Simple**
- Entrée : `"3 4 +"`
- Étapes :
  1. Empile `3`.
  2. Empile `4`.
  3. Additionne `3 + 4 = 7`.
  4. Empile `7`.
- Sortie : `7`

### Exemple 2 : **Expression Complexe**
- Entrée : `"5 1 2 + 4 * + 3 -"`
- Étapes :
  1. Empile `5`.
  2. Empile `1`.
  3. Empile `2`.
  4. Additionne `1 + 2 = 3`, empile `3`.
  5. Empile `4`.
  6. Multiplie `3 * 4 = 12`, empile `12`.
  7. Additionne `5 + 12 = 17`, empile `17`.
  8. Empile `3`.
  9. Soustrait `17 - 3 = 14`.
- Sortie : `14`

### Exemple 3 : **Erreur - Token Invalide**
- Entrée : `"3 4 a +"`
- Sortie : `Error: Unexpected token 'a'`

### Exemple 4 : **Erreur - Manque d’opérandes**
- Entrée : `"3 +"`
- Sortie : `Error: Not enough operators`

---

## 6. Conseils pour Réussir
1. **Vérifiez chaque token :** Utilisez `validateToken` pour éviter des erreurs de traitement.
2. **Testez avec des cas simples :** Commencez avec des expressions courtes et augmentez progressivement la complexité.
3. **Gérez les erreurs :** Ajoutez des messages explicites pour faciliter le débogage.
4. **Comprenez le fonctionnement de la pile :** Visualisez chaque étape pour comprendre comment les éléments sont empilés et dépilés.

---

Bonne chance ! Si vous avez des questions, n’hésitez pas à demander de l’aide. 😊


