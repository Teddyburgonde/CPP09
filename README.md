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

# Guide pour Réussir l’Exercice ex00 : Bitcoin Exchange

Ce guide vous explique comment aborder l’exercice **ex00 : Bitcoin Exchange** en C++, afin de manipuler des fichiers, valider des données, et effectuer des calculs avec des taux d’échange.

---

## 1. Comprendre l’Exercice
- **Objectif :** Créer un programme qui analyse un fichier contenant des dates et des taux d’échange pour calculer la valeur équivalente en Bitcoin.
- **Concepts clés :**
  - Manipulation de fichiers avec `std::ifstream`.
  - Validation des dates et des nombres.
  - Calcul dynamique basé sur des données pré-chargées.
  - Utilisation de structures comme `std::map` pour associer les dates aux taux.

---

## 2. Architecture du Code

### 2.1 Structure Principale

#### Fonction **`main`**
- Gère les arguments de ligne de commande.
- Initialise les données Bitcoin en les chargeant dans une `std::map`.
- Appelle la fonction **`processInputFile`** pour lire et analyser le fichier d’entrée.

#### Fonction **`processInputFile`**
- Lit le fichier ligne par ligne.
- Valide les dates et les taux pour chaque ligne.
- Calcule la valeur de Bitcoin à partir des taux valides.
- Affiche les résultats ou les erreurs.

### 2.2 Fonctions Clés

#### **Validation des Données**
- **`isValidDate` :** Valide le format et la portée des dates.
- **`isValidRate` :** Valide les taux en s’assurant qu’ils sont des nombres valides et dans une plage pré-définie.

#### **Gestion des Fichiers**
- **`readAndStockDataInFile` :** Charge les taux de Bitcoin à partir d’un fichier CSV dans une `std::map`.
- **`trim` :** Supprime les espaces inutiles autour des données.

---

## 3. Fonctionnalités Principales

### 3.1 Validation des Dates

#### **`isValidDate`**
- Vérifie que la date suit le format `YYYY-MM-DD`.
- Assure que :
  - La longueur est correcte.
  - Les séparateurs sont bien des tirets (`-`).
  - Les segments (année, mois, jour) sont numériques.
  - Les valeurs sont dans des plages valides (ex. : mois entre 1 et 12, jours adaptés au mois).

#### Exemple d’Utilisation :
```cpp
std::string errorMessage;
if (!isValidDate("2023-06-15", errorMessage)) {
    std::cerr << errorMessage << std::endl;
}
```

---

### 3.2 Validation des Taux

#### **`isValidRate`**
- Assure que les taux sont des nombres valides.
- Vérifie qu’ils ne contiennent pas de caractères invalides.
- Confirme que le taux est compris entre 0 et 1000 (plage définie).

#### Exemple d’Utilisation :
```cpp
std::string errorMessage;
if (!isValidRate("123.45", errorMessage)) {
    std::cerr << errorMessage << std::endl;
}
```

---

### 3.3 Calcul de la Valeur en Bitcoin

#### **`performOperation`**
- Multiplie le taux d’échange par la valeur en Bitcoin pré-chargée dans `std::map`.

#### Exemple d’Utilisation :
```cpp
float valueOfBitcoin = bitcoinData["2023-06-01"] * rate;
```

---

## 4. Exemple de Fonctionnement

### Fichier d’Entrée : `input.txt`
```
2023-06-01 | 2.5
2023-06-03 | 1.2
2023-06-10 | abc
2023-04-31 | 5.0
```

### Fichier des Taux : `data.csv`
```
Date,Exchange Rate
2023-06-01,20000.0
2023-06-03,18000.0
2023-06-10,23000.0
2023-06-04,22000.0
```

### Sortie Attendue :
```
2023-06-01 => 2.5 = 50000.00
2023-06-03 => 1.2 = 21600.00
Error: Rate is not a valid number. => abc
Error: Day out of range (1-31) => 2023-04-31
```

---

## 5. Conseils pour Réussir
1. **Chargez les Données Correctement :** Assurez-vous que les fichiers CSV et d’entrée sont bien formatés.
2. **Validez Toutes les Données :** Utilisez les fonctions de validation pour chaque champ (dates et taux).
3. **Gérez les Erreurs :** Fournissez des messages d’erreur clairs pour faciliter le débogage.
4. **Testez Différents Cas :** Essayez avec des dates en dehors de la plage valide, des taux non numériques, et des lignes vides.

---

Bonne chance ! Si vous avez des questions ou rencontrez des problèmes, n’hésitez pas à demander de l’aide. 😊



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

# ex03

```c
Étape 1 et 2 : Vérifier, convertir et ajouter dans vector et deque
Étape 3 : Former des paires
Étape 4 : Envoyer les mins dans final_vector
Etape 4 bis : trie final_vector
Etape 4 bis : trie final_deque
Etape 5 : Insertion des max dans final_vector
Etape 5 : Insertion des max dans final_vector
Etape 6 : gestion du -1;
Etape 7 : Affichage du résultat final
Etape 8 : Affichage du temps
```


