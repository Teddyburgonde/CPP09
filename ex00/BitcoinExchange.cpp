/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:50:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/23 13:32:57 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

/* Converts a string to a float  */
float stringToFloat(const std::string& str) 
{
    std::stringstream ss(str);
    float value;

	// Convert 
    ss >> value; 

    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Invalid float format: " + str);
    return value;
}


/* Reads data from the file data.csv */
std::map<std::string, float> readAndStockDataInFile()
{
	std::map<std::string, float> _data;
	std::string line;
	std::string date;
	float exchange_rate;
	
	// Open data.csv
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error opening file");
	// Ignore first line
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line); // Creation of a data flow for data manipulation
		std::getline(iss, line, ',');
		
		std::getline(iss, date);

		// Converts a string to a float 
		exchange_rate = stringToFloat(date); 
		_data[line] = exchange_rate;
	}
	return _data;
}

