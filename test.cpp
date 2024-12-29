
// float stringToFloat(const std::string& str) 
// {
//     std::stringstream ss(str);
//     float value;

// 	// Convert 
//     ss >> value; 

//     if (ss.fail() || !ss.eof())
//         throw std::runtime_error("Invalid float format: " + str);
//     return value;
// }

// bool	isOperator(char c)
// {
// 	if (c == '+' || c == '-' || c == '/' || c == '*')
// 		return true;
// 	return false;
// }

// float	performOperation(float firstOperant, float secondOperant, char op)
// {
// 	float result;

// 	switch (op)
// 	{
// 		case '-':
// 			result = firstOperant - secondOperant;
// 			break;
// 		case '+':
// 			result = firstOperant + secondOperant;
// 			break;
// 		case '*':
// 			result = firstOperant * secondOperant;
// 			break;
// 		case '/':
// 			if (secondOperant == 0)
// 				throw std::runtime_error("Error: Division by 0");
// 			result = firstOperant / secondOperant;
// 			break;
// 		default:
//     		throw std::runtime_error("Error: Invalid operator");
// 	}
// 	return result;
// }

// bool isValidNumber(const std::string& token) 
// {
//     std::istringstream iss(token);
//     float value;
// 	bool isValid;

// 	isValid = (iss >> value) && iss.eof();
//     return isValid;
// }

// void validateToken(const std::string& token) 
// {
//     if (!isValidNumber(token) && !(token.size() == 1 && isOperator(token[0])))
//         throw std::runtime_error("Error: Unexpected token '" + token + "'");
// }


// float calculateRPN(std::string rpnExpression)
// {
// 	std::stack<float> stk;
// 	std::string token;
// 	std::istringstream iss(rpnExpression);
// 	float	result;

// 	while (iss >> token)
// 	{
// 		validateToken(token);
// 		if (isValidNumber(token))
// 			stk.push(stringToFloat(token));
// 		else if (isOperator(token[0]))
// 		{
// 			if (stk.size() < 2)
// 				throw std::runtime_error("Error: Not enough operators");
// 			float second = stk.top(); stk.pop();
// 			float first = stk.top(); stk.pop();
// 			result = performOperation(first, second, token[0]);
// 			stk.push(result);
// 		}
// 	}
// 	if (stk.size() != 1)
// 		throw std::runtime_error("Error: Invalid RPN expression");
// 	result = stk.top();
// 	return result;
// }

// int	main(int argc, char **argv)
// {
// 	float result;

// 	if (argc != 2 || std::string(argv[1]).empty())
// 	{
// 		std::cerr << "Error: Invalid input" << std::endl;
// 		return 1;
// 	}
// 	std::string rpnExpression = argv[1];
// 	try 
// 	{
// 		result = calculateRPN(rpnExpression);
// 		std::cout << result << std::endl;
// 	} 
// 	catch (const std::exception& e) 
// 	{
// 		std::cerr << e.what() << std::endl;
//         return 1;
// 	}
// 	return 0;
// }

