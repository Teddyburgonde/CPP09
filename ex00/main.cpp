/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:51:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/28 11:28:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	printMap(std::map<std::string, float> _data)
{
	std::map<std::string, float>::iterator it;
	for(it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

int main(int argc, char **argv)
{
    (void)argv;
    try
    {
        if (argc != 2)
         	throw std::runtime_error("Error number of arguments");
        std::map<std::string, float> bitcoinData;
        bitcoinData["2023-06-01"] = 20000.0;
        bitcoinData["2023-06-02"] = 25000.0;
        bitcoinData["2023-12-31"] = 30000.0;
        bitcoinData["2023-06-03"] = 18000.0;
        bitcoinData["2023-06-04"] = 22000.0;
        bitcoinData["2023-06-05"] = 25000.0;
        bitcoinData["2023-06-06"] = 27000.0;
        bitcoinData["2023-06-07"] = 28000.0;
        bitcoinData["2023-06-08"] = 29000.0;
        bitcoinData["2023-04-30"] = 21000.0; // Dernière date valide pour avril
        bitcoinData["2023-06-10"] = 23000.0;
        std::string inputFilePath = "input.txt";
        processInputFile(inputFilePath, bitcoinData);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
