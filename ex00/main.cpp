/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:14:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/02 21:28:46 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// la ligne 
// "2011-01-03 | 3" a exactement 14 caractères

bool isValidLine(const std::string& line)
{
	if (line.size() < 14)
		return false;
	if (line[4] != '-' || line[7] != '-')
		return false;
	for(int i = 0; i <= 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if(!isdigit(line[i]))
			return false;
	}
	return true;
}

bool isValidDate(const std::string& line)
{
	std::string yearStr = line.substr(0, 4);
	std::string monthStr = line.substr(5, 2);
	std::string dayStr = line.substr(8, 2);

	int year = atoi(yearStr.c_str());
	int month = atoi(monthStr.c_str());
	int day = atoi(dayStr.c_str());

	if (month < 1 || month > 12)
		return (false);
		// Tableau des jours maximums par mois (non bissextile)
    int maxDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeapYear)
			maxDaysInMonth[1] = 29;
	}
	if (day < 1 || day > maxDaysInMonth[month - 1])
		return false;
	return true;
}

int main()
{
	std::ifstream file("input.txt"); // Creation d'un objet ifstream pour ouvrir et lire le fichier

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1; 
	}
	std::string line; // variable pour stocker chaque ligne lue.
	while (std::getline(file, line)) // Boucle qui lit le fichier ligne par ligne jusqu'à la fin du fichier
	{
		if (!isValidLine(line) || !isValidDate(line))
		{
			std::cout << "Invalid line: " << line << std::endl;
			continue;
		}
		std::cout << "Valid line: " << line << std::endl; // Affiche les lignes valides
	}
	 // Ferme le fichier après avoir fini de le lire
    file.close();
	return 0;
}