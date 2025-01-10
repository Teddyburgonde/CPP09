/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:22:19 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/10 20:41:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Step 1 and 2: Validate, convert, and add to vector and deque
Step 3: Create pairs
Step 4: Send the mins to final_vector
Step 4 bis: Sort final_vector
Step 4 bis: Sort final_deque
Step 5: Insert the max values into final_vector
Step 5: Insert the max values into final_deque
Step 6: Handle the -1
Step 7: Display the final result
Step 8: Display the execution time
*/

template <typename Container>
void printResults(const Container& container, const std::string& label) 
{
    std::cout << label << std::endl;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) 
{
    try 
    {
        if (argc < 2)
            throw std::runtime_error("Error: No input provided.");

        std::vector<std::pair<int, int> > even;
        PmergeMe pmerge;

        pmerge.processInputs(argc, argv);
        pmerge.createPairs();
        pmerge.extractMins();
        pmerge.startVectorTimer();
        pmerge.sortFinalVector(); 
        pmerge.insertMaxs();
        pmerge.stopVectorTimer();
        pmerge.startDequeTimer();
        pmerge.sortAndInsertMaxs();
        pmerge.stopDequeTimer();
        pmerge.removeMinusOne();
        pmerge.displayFinalResults();
        pmerge.displayExecutionTime();
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
