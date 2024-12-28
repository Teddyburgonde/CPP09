#include <iostream>
#include <cctype>
#include <stack>
#include <sstream>


float stringToFloat(const std::string& str) 
{
    std::stringstream ss(str);
    float value;

	// Convert 
    ss >> value; 

    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Invalid float format: " + str);
    return value;
}


bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

float	performOperation(int firstOperant, int secondOperant, char op)
{
	int result;

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

int	main()
{
	std::stack<float> stk;
	std::string token;
	std::string rpnExpression = "10 2 8 * + 3 -";
	std::istringstream iss(rpnExpression);
	float result;

	try 
	{
		while (iss >> token)
		{
			if (isdigit(token[0]))
			{
				stringToFloat(token);
				stk.push(stringToFloat(token));
			}
			else if (isOperator(token[0]) == true)
			{
				if (stk.size() < 2)
					throw std::runtime_error("Error: Not enough operators");
				float second = stk.top(); stk.pop();
				float first = stk.top(); stk.pop();
				result = performOperation(first, second, token[0]);
				stk.push(result);
			}
			else
				throw std::runtime_error("Error: Invalid token");
		}
		if (stk.size() != 1) // protect
			throw std::runtime_error("Error: Invalid RPN expression");
		result = stk.top();
		std::cout << "result :" << result << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
        return 1;
	}

}

