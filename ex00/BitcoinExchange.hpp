/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:45:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/27 14:23:10 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

std::map<std::string, float> readAndStockDataInFile();
bool isValidDate(const std::string &date, std::string &errorMessage);
bool isValidRate(const std::string& rate);
std::string trim(const std::string& str);

#endif