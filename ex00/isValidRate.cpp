/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidRate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/28 10:13:24 by tebandam         ###   ########.fr       */
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
		return false; // Conversion failure
	}
	// Check that the entire string has been converted
	if (!ss.eof())
	{
		errorMessage = "Error: Rate contains extra characters.";
        return false;
	}
	return true;
}
