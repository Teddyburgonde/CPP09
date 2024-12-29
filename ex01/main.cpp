/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:34:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/29 09:45:49 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	float result;

	if (argc != 2 || std::string(argv[1]).empty())
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return 1;
	}
	std::string rpnExpression = argv[1];
	try 
	{
		RPN rpnCalculator;
		result = rpnCalculator.calculateRPN(rpnExpression);
		std::cout << result << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
        return 1;
	}
	return 0;
}