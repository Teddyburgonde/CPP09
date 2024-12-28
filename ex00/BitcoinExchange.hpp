/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:45:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/28 11:59:12 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> bitcoinData;
		
	public:
		std::map<std::string, float> readAndStockDataInFile();
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
};

void processInputFile(const std::string &inputFilePath, const std::map <std::string, float > &bitcoinData);
std::string trim(const std::string& str);
bool isValidDate(const std::string &date, std::string &errorMessage);
bool isValidRate(const std::string& rate, std::string &errorMessage);

#endif