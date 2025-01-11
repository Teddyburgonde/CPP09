/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:50:22 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/11 07:41:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Constructor */
BitcoinExchange::BitcoinExchange() {}

/* Destructor */
BitcoinExchange::~BitcoinExchange() {}

/* Copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

/* Assignment operator */
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->bitcoinData = other.bitcoinData;
	}
	return *this;
}

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
void BitcoinExchange::readBitcoinData()
{
	std::string rateStr;
	std::string line;
	std::string date;
	float exchange_rate;
	
	
	// Open data.csv
	const std::string filePath = "data.csv";
	std::ifstream file(filePath.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error opening file");
	// Ignore first line
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream iss(line); // Creation of a data flow for data manipulation
		if (!std::getline(iss, date, ',') || !std::getline(iss, rateStr)) 
		{
            std::cerr << "Error: Invalid line format => " << line << std::endl;
            continue;
        }
		date = trim(date); // Apply trimming if necessary
        rateStr = trim(rateStr);

		// Converts a string to a float 
		exchange_rate = stringToFloat(rateStr); 
		bitcoinData[date] = exchange_rate;
	}
	file.close();
}

