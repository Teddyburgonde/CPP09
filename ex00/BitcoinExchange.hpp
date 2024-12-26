/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:45:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/24 16:22:15 by tebandam         ###   ########.fr       */
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
bool isValidDate(const std::string &date);
bool ifValidRate(const std::string& rate);

#endif