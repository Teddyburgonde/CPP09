/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidRate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:46 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/12 12:17:00 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidRate(const std::string& rate, std::string &errorMessage)
{
	std::stringstream ss(rate);
	float	value;
	
	if (!(ss >> value))
	{
		errorMessage = "Error: Rate is not a valid number.";
		return false;
	}
	if (!ss.eof())
	{
		errorMessage = "Error: Rate contains extra characters.";
        return false;
	}
	return true;
}
