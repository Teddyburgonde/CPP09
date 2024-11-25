/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:14:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/11/25 11:54:24 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


//2011-01-03 | 3


// if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
// {
//         return false;
// }


int main()
{
	int	i;

	i = 0;
	std::ifstream file("input.txt"); // Creation d'un objet ifstream pour ouvrir et lire le fichier

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1; 
	}
	std::string line; // variable pour stocker chaque ligne lue.
	while (std::getline(file, line))
	{
		if (line)
	}



	
	while (std::getline(file, line)) // Boucle qui lit le fichier ligne par ligne jusqu'à la fin du fichier
	{
		if (std::isdigit(line[i]) || line[i] == '-' || line[i] == '|')
		{
			std::cout << line << std::endl;
		}
		i++;
	}
	 // Ferme le fichier après avoir fini de le lire
    file.close();
	return 0;
}