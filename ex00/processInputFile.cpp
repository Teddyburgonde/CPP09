/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processInputFile.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:19:27 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/27 14:50:54 by tebandam         ###   ########.fr       */
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
    std::string trimmed;
    std::string errorMessage;
    float   rateFloat;
    
	// Open input file
    std::ifstream inputFile(inputFilePath.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: Could not open file: " + inputFilePath);
	// Read the file
	while (std::getline(inputFile, line)) //! sauter une ligne ou pas ??????????????????????????????????????????????????????????
	{
        // Separate date and rate
		std::istringstream iss(line);
        std::getline(iss, date, '|');

        std::getline(iss, rate);

        // Remove spaces
        trimmed = trim(rate);
        
        // Confirm date
        if (isValidDate(date, errorMessage) ==  false)
            throw std::runtime_error(errorMessage); //! errorMessage ???? faut tester.
        
        // Confirm rate
        if (isValidRate(rate) == false)    
            throw std::runtime_error("Invalid rate"); //! errorMessage ???? faut tester.
        
        // Convert value to float
        rateFloat = std::atof(rate.c_str());

        // Confirm range of rate
        if (rateFloat < 0 || rateFloat > 1000)
        {
            std::cerr << "Error: rate out of range => " << rate << std::endl;
            return ;
        }

        // Find the corresponding date in bitcoin data
        std::map <std::string, float>::const_iterator it = bitcoinData.lower_bound(date);
        if (it == bitcoinData.end() || it->first != date)
        {
            if (it == bitcoinData.begin())
                throw std::runtime_error("Error: date not found in database");
            --it;
            std::string closesDate = it->first;
            float exchangeRate = it->second;
        }
        // Calculating the value of bitcoin
        float valueOfBitcoin =  bitcoinData * rateFloat;

        // display result
        std::cout << closesDate << " => " << rate < " = " << valueOfBitcoin << std::endl;     
        
        // Close the file
        inputFile.close();
    }
}