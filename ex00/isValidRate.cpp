/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidRate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:46 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/12 09:06:00 by teddybandam      ###   ########.fr       */
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
	// Check that the entire string has been converted
	if (!ss.eof())
	{
		errorMessage = "Error: Rate contains extra characters.";
        return false;
	}
	return true;
}
