/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:45:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/28 10:07:39 by tebandam         ###   ########.fr       */
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

std::map<std::string, float> readAndStockDataInFile();
void processInputFile(const std::string &inputFilePath, const std::map <std::string, float > &bitcoinData);
bool isValidDate(const std::string &date, std::string &errorMessage);
bool isValidRate(const std::string& rate, std::string &errorMessage);
std::string trim(const std::string& str);

#endif