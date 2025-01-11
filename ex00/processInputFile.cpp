/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processInputFile.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:19:27 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/11 14:17:04 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) 
{
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) 
        ++start;

    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1]))
        --end;
    std::string result;
    for (size_t i = start; i < end; ++i) 
        result += str[i];
    return result;
}

/**
 * processInput
 * This function reads a file containing pairs of dates and values, validates the entries,
 * and computes the Bitcoin value based on exchange rates stored in a database (bitcoinData).
 * The results are displayed in a formatted way, and any errors are reported.
 * 
 * @param inputFilePath : path to the input file.
 * @param bitcoinData : map containing Bitcoin exchange rates by date.
 * @throws std::runtime_error : if the file cannot be opened.
 */

void BitcoinExchange::processInput(const std::string &inputFilePath)
{
    std::string line, date, rate, errorMessage;
    float rateFloat, valueOfBitcoin;

    // Open the input file in read mode
    std::ifstream inputFile(inputFilePath.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: Could not open file: " + inputFilePath);

    // Set fixed-point notation for output (optional for formatting)
    std::cout.precision(2);

    // Read the file line by line
    while (std::getline(inputFile, line))
    {
        if (line.empty()) // Skip empty lines
            continue;
         // Skip header line
        if (line == "date | value")
            continue;

        // Split the line into date and rate
        std::istringstream iss(line);
        if (!std::getline(iss, date, '|') || !std::getline(iss, rate)) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Remove spaces
        date = trim(date);
        rate = trim(rate);

        // Validate the date
        if (!isValidDate(date, errorMessage)) 
        {
            std::cerr << errorMessage << " => " << date << std::endl;
            continue;
        }

        // Validate and convert the rate using istringstream
        std::istringstream rateStream(rate);
        if (!(rateStream >> rateFloat) || !rateStream.eof()) 
        {
            std::cerr << "Error: Invalid rate => " << rate << std::endl;
            continue;
        }

        // Confirm range of rate
        if (rateFloat < 0 || rateFloat > 1000) 
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        // Find the corresponding date in bitcoin data
        std::map<std::string, float>::const_iterator it = bitcoinData.lower_bound(date);
        if (it == bitcoinData.end() || it->first != date) 
        {
            if (it == bitcoinData.begin()) 
            {
                std::cerr << "Error: Date not found in database => " << date << std::endl;
                continue;
            }
            --it; // Use the closest previous date
        }

        // Calculate the value of Bitcoin
        valueOfBitcoin = it->second * rateFloat;

        // Display the result
        std::cout << date << " => " << rate << " = " << valueOfBitcoin << std::endl;
    }
    inputFile.close(); // Close the file
}
