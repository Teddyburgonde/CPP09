/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:20:49 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/04 19:20:57 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int number;
    ss >> number;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid input: not an integer");
    }
    return number;
}
