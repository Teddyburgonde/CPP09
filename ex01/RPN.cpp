/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:32:31 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/29 09:46:31 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) 
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other) 
{
	(void)other;
	return *this;
}

static float stringToFloat(const std::string& str) 
{
    std::stringstream ss(str);
    float value;

	// Convert 
    ss >> value; 

    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Invalid float format: " + str);
    return value;
}

static bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

static float	performOperation(float firstOperant, float secondOperant, char op)
{
	float result;

	switch (op)
	{
		case '-':
			result = firstOperant - secondOperant;
			break;
		case '+':
			result = firstOperant + secondOperant;
			break;
		case '*':
			result = firstOperant * secondOperant;
			break;
		case '/':
			if (secondOperant == 0)
				throw std::runtime_error("Error: Division by 0");
			result = firstOperant / secondOperant;
			break;
		default:
    		throw std::runtime_error("Error: Invalid operator");
	}
	return result;
}

static bool isValidNumber(const std::string& token) 
{
    std::istringstream iss(token);
    float value;
	bool isValid;

	isValid = (iss >> value) && iss.eof();
    return isValid;
}

static void validateToken(const std::string& token) 
{
    if (!isValidNumber(token) && !(token.size() == 1 && isOperator(token[0])))
        throw std::runtime_error("Error");
}


float RPN::calculateRPN(std::string rpnExpression)
{
	std::stack<float> stk;
	std::string token;
	std::istringstream iss(rpnExpression);
	float	result;

	while (iss >> token)
	{
		validateToken(token);
		if (isValidNumber(token))
			stk.push(stringToFloat(token));
		else if (isOperator(token[0]))
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error: Not enough operators");
			float second = stk.top(); stk.pop();
			float first = stk.top(); stk.pop();
			result = performOperation(first, second, token[0]);
			stk.push(result);
		}
	}
	if (stk.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression");
	result = stk.top();
	return result;
}