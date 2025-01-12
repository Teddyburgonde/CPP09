/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:45:00 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/12 12:17:47 by tebandam         ###   ########.fr       */
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
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void readBitcoinData();
		void processInput(const std::string &inputFilePath);
		std::string trim(const std::string& str);
		bool isValidDate(const std::string &date, std::string &errorMessage);
};




#endif