/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:51:22 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/11 14:32:55 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * Main function
 * This program calculates Bitcoin values based on exchange rates stored in a fixed file ("data.csv")
 * and processes an input file provided as a command-line argument.
 *
 * Workflow:
 * 1. Validates that exactly one argument (the input file) is provided.
 * 2. Loads Bitcoin exchange rates from the fixed file "data.csv".
 * 3. Processes the input file to compute Bitcoin values for the given dates and amounts.
 * 4. Handles errors such as missing files, invalid input format, or incorrect arguments.
 *
 * Usage:
 * ./btc <input_file>
 * Example:
 * ./btc input.txt
 */
 
int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
         	throw std::runtime_error("Error: could not open file.");
        BitcoinExchange btcExchange;

        btcExchange.readBitcoinData();
        btcExchange.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
