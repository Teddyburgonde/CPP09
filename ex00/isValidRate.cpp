/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidRate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:46 by tebandam          #+#    #+#             */
/*   Updated: 2025/01/11 14:28:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * Validates if the given rate is a valid floating-point number.
 * - Uses a stringstream to attempt conversion from string to float.
 * - Ensures the entire string has been consumed during conversion (no extra characters).
 * - Updates the errorMessage string if the rate is invalid.
 *
 * @param rate The string representing the rate to validate.
 * @param errorMessage Reference to a string for storing an error message if validation fails.
 * @return true if the rate is valid, false otherwise.
 */

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
