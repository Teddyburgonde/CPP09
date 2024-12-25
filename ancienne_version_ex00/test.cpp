/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:52:18 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/25 13:27:47 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <type_traits>

bool verifLength(const std::string &date)
{
	if (date.size() != 10)
    {
        std::cout << "Error: Incorrect length" << std::endl;
        return false;
    }
	return true;
}

bool	verifSeparator(const std::string &date)
{
	if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: Incorrect separators" << std::endl;
        return false;
    }
	return true;
}

bool	verifNumericSegments(const std::string &date)
{
	int yearLength = 4;
    int monthLength = 2;
    int dayLength = 2;

    // Check year
    for (int i = 0; i < yearLength; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: Year contains non-numeric characters";
            return false;
        }
    }

    // Check month
    for (int i = 5; i < 5 + monthLength; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: Month contains non-numeric characters";
            return false;
        }
    }

    // Check day
    for (int i = 8; i < 8 + dayLength; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: Day contains non-numeric characters";
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

bool isValidDayRange(int year, int month, const std::string &date, std::string &errorMessage)
{
    int day = 0;

    for (int i = 8; i <= 9; ++i)
        day = day * 10 + (date[i] - '0'); 
    if (day < 1 || day > 31)
    {
        errorMessage = "Error: Day out of range (1-31)";
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        errorMessage = "Error: Day exceeds maximum for month";
        return false;
    }
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap && day > 29)
        {
            errorMessage = "Error: Day exceeds maximum for February in a leap year";
            return false;
        }
        if (!isLeap && day > 28)
        {
            errorMessage = "Error: Day exceeds maximum for February in a non-leap year";
            return false;
        }
    }
    return true;
}

// YYYY-MM-DD
bool isValidRange(const std::string &date, std::string &errorMessage)
{
    int year = 0;
    int month = 0;

    for (int i = 0; i < 4; ++i)
        year = year * 10 + (date[i] - '0');
    if (year < 1900 || year > 2100)
    {
        errorMessage = "Error: Year out of range (1900-2100)";
        return false;
    }
    for (int i = 5; i <= 6; ++i)
        month = month * 10 + (date[i] - '0');
    if (month < 1 || month > 12)
    {
        errorMessage = "Error: Month out of range (1-12)";
        return false;
    }
    for (int i = 5; i <= 6; ++i)
        month = month * 10 + (date[i] - '0');
    if (month < 1 || month > 12)
    {
        errorMessage = "Error: Month out of range (1-12)";
        return false;
    }
    // Day management
    if (isValidDayRange(year, month, date, errorMessage) == false)
        return false;
    return true;
    
}

int main()
{
    std::string date = "2023-05-ab" ;
    std::string errorMessage;
    
    if (isValidDate(date) && isValidRange(date, errorMessage))
    {
        std::cout << "Date is valid!" << std::endl;
    }
    else 
    {
        std::cout << errorMessage << std::endl;
    }
    return 0;
}


