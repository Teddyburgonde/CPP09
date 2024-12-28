#include <iostream>
#include <cctype>
#include <stack>
#include <sstream>

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
	std::string rpnExpression = "3 4 +";
	std::istringstream iss(rpnExpression);


	while (iss >> token)
	{
		if (isdigit(token[0]))
		{
			std::cout << token[0] << " c'est un digit " << std::endl;
		}
	}

}

