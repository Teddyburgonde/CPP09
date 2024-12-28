/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidRate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/28 09:59:57 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidRate(const std::string& rate)
{
	std::stringstream ss(rate);
	float	value;
	
	
	if (!(ss >> value))
		return false; // Conversion failure
	// Check that the entire string has been converted
	if (!ss.eof())
        return false;
	return true;
}






















//bool ifValidValue(const std::string& value) {
//    // Check that the input string has the correct length
//    try {
//            std::stof(value);
//        }
//        catch (const std::invalid_argument& e) {
//            // std::cout << e.what() << std::endl;
//            return false;
//        }
//    return true;
//}
