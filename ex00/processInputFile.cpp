/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processInputFile.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:19:27 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/28 11:19:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) 
{
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        ++start;
    }

    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }

    // Construction de la chaîne résultat sans `substr`
    std::string result;
    for (size_t i = start; i < end; ++i) 
    {
        result += str[i];
    }

    return result;
}

void processInputFile(const std::string &inputFilePath, const std::map <std::string, float > &bitcoinData)
{
	std::string line;
    std::string date;
    std::string rate;
    std::string errorMessage;
    std::string closesDate;
    float       rateFloat;
    float       valueOfBitcoin;
    
	// Open input file
    std::ifstream inputFile(inputFilePath.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: Could not open file: " + inputFilePath);
    
    // Set fixed-point notation for output
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    // Read the file
    while (std::getline(inputFile, line))
	{
        // Skip empty lines
        if (line.empty())
            continue;
        // Separate date and rate
		std::istringstream iss(line);
        std::getline(iss, date, '|');
        std::getline(iss, rate);

        // Remove spaces
        date = trim(date);
        rate = trim(rate);
        
        // Confirm date
        if (isValidDate(date, errorMessage) ==  false)
        {
            std::cerr << errorMessage << " => " << date << std::endl;
            continue;
            
        }
        // Confirm rate
        if (isValidRate(rate, errorMessage) == false)    
        {
            std::cerr << errorMessage << " => " << rate << std::endl;
            continue;
        }
        // Convert value to float
        rateFloat = std::atof(rate.c_str());

        // Confirm range of rate
        if (rateFloat < 0 || rateFloat > 1000)
        {
            std::cerr << "Error: Rate is out of range (0-1000) => " << rate << std::endl;
            continue;
        }

        // Find the corresponding date in bitcoin data
        std::map <std::string, float>::const_iterator it = bitcoinData.lower_bound(date);
        if (it == bitcoinData.end() || it->first != date)
        {
            if (it == bitcoinData.begin())
            {
                std::cerr << "Error: Date not found in database => " << date << std::endl;
                continue;
            }
            --it;
        }
        // Calculating the value of bitcoin
        valueOfBitcoin =  it->second * rateFloat;

        // display result
        std::cout <<  date << " => " << rate << " = " << valueOfBitcoin << std::endl;     
        
    }
    // Close the file
    inputFile.close();
}