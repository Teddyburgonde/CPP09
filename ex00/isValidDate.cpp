/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidDate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/24 16:23:03 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp" 

static  bool verifLength(const std::string &date)
{
	if (date.size() != 10)
    {
        std::cout << "Error: Incorrect length" << std::endl;
        return false;
    }
	return true;
}

static bool	verifSeparator(const std::string &date)
{
	if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: Incorrect separators" << std::endl;
        return false;
    }
	return true;
}

static bool	verifNumericSegments(const std::string &date)
{
	int yearLength = 4;
    int monthLength = 2;
    int dayLength = 2;

    // Check year
    for (int i = 0; i < yearLength; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: Year contains non-numeric characters" << std::endl;
            return false;
        }
    }

    // Check month
    for (int i = 5; i < 5 + monthLength; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: Month contains non-numeric characters" << std::endl;
            return false;
        }
    }

    // Check day
    for (int i = 8; i < 8 + dayLength; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: Day contains non-numeric characters" << std::endl;
            return false;
        }
    }
	return true;
}
bool isValidDate(const std::string &date)
{
    if (verifLength(date) == false || verifSeparator(date) == false || verifNumericSegments(date) == false)
		return false;
    return true;
}
