/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:52:18 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/25 14:31:02 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool verifLength(const std::string &date, std::string &errorMessage)
{
	if (date.size() != 10)
    {
        errorMessage = "Error: Incorrect length";
        return false;
    }
	return true;
}

bool	verifSeparator(const std::string &date, std::string &errorMessage)
{
	if (date[4] != '-' || date[7] != '-')
    {
        errorMessage = "Error: Incorrect separators";
        return false;
    }
	return true;
}

bool	verifNumericSegments(const std::string &date, std::string &errorMessage)
{
	int yearLength = 4;
    int monthLength = 2;
    int dayLength = 2;
    // Check year
    for (int i = 0; i < yearLength; i++)
    {
        if (!isdigit(date[i]))
        {
            errorMessage = "Error: Year contains non-numeric characters";
            return false;
        }
    }
    // Check month
    for (int i = 5; i < 5 + monthLength; i++)
    {
        if (!isdigit(date[i]))
        {
            errorMessage = "Error: Month contains non-numeric characters";
            return false;
        }
    }
    // Check day
    for (int i = 8; i < 8 + dayLength; i++)
    {
        if (!isdigit(date[i]))
        {
            errorMessage = "Error: Day contains non-numeric characters";
            return false;
        }
    }
	return true;
}

bool isDateFormatValid(const std::string &date, std::string &errorMessage)
{
    if (verifLength(date, errorMessage) == false || verifSeparator(date, errorMessage) == false || verifNumericSegments(date, errorMessage) == false)
        return (false);
    return true;
}

bool isValidYearRange(int year, std::string &errorMessage)
{
    if (year < 1900 || year > 2100)
    {
        errorMessage = "Error: Year out of range (1900-2100)";
        return false;
    }
    return true;
}

bool isValidMonthRange(int month, std::string &errorMessage)
{
    if (month < 1 || month > 12)
    {
        errorMessage = "Error: Month out of range (1-12)";
        return false;
    }
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

bool isValidRange(const std::string &date, std::string &errorMessage)
{
    int year = 0;
    int month = 0;

    // Year management
    for (int i = 0; i < 4; ++i)
        year = year * 10 + (date[i] - '0');
    if (isValidYearRange(year, errorMessage) == false)
        return false;
    // Month management
    for (int i = 5; i <= 6; ++i)
        month = month * 10 + (date[i] - '0');
    if (isValidMonthRange(month, errorMessage) == false)
        return false;
    // Day management
    if (isValidDayRange(year, month, date, errorMessage) == false)
        return false;
    return true;
}
bool isValidDate(const std::string &date, std::string &errorMessage)
{
    if (isDateFormatValid(date, errorMessage) == false || isValidRange(date, errorMessage) == false)
		return false;
    return true;
}

// int main()
// {
//     std::string date = "2023-05" ;
//     std::string errorMessage;
    
//     if (isValidDate(date,errorMessage))
//     {
//         std::cout << "Date is valid!" << std::endl;
//     }
//     else 
//     {
//         std::cout << errorMessage << std::endl;
//     }
//     return 0;
// }

#include <vector>
#include <string>
#include <iostream>

// Ta fonction `isValidDate` avec `errorMessage` doit déjà être définie ici.

int main()
{
    // Liste des dates à tester
    std::vector<std::string> dates = {
        "2023-05-20", // Valide
        "2024-02-29", // Valide (année bissextile)
        "2023-02-29", // Invalide (année non bissextile)
        "2023-13-20", // Mois invalide
        "2023-05-32", // Jour invalide
        "2023/05/20", // Format invalide (mauvais séparateur)
        "2023-05",    // Format invalide (longueur incorrecte)
        "1899-05-20", // Année hors plage
        "2023-04-31"  // Jour invalide (Avril a 30 jours)
    };

    // Test de chaque date
    for (const auto &date : dates)
    {
        std::string errorMessage;
        if (isValidDate(date, errorMessage) == true)
        {
            std::cout << date << " => Date is valid!" << std::endl;
        }
        else
        {
            std::cout << date << " => " << errorMessage << std::endl;
        }
    }

    return 0;
}


