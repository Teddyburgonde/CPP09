/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:51:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/24 16:24:43 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	printMap(std::map<std::string, float> _data)
{
	std::map<std::string, float>::iterator it;
	for(it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	try 
	{
		if (argc != 2)
        	throw std::runtime_error("Error number of arguments");
		std::map<std::string, float> _data;
		_data = readAndStockDataInFile();
		// printMap(_data); // a enlever 
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
