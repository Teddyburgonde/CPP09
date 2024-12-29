/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:33:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/12/29 09:44:43 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cctype>
#include <stack>
#include <sstream>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		float calculateRPN(std::string rpnExpression);
};

#endif