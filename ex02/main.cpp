/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:22:19 by teddybandam       #+#    #+#             */
/*   Updated: 2025/01/10 08:56:12 by tebandam         ###   ########.fr       */
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
        std::vector<int> vector;
        std::deque<int> deque;
        std::vector<std::pair<int, int> > even;
        std::vector<int> final_vector;
        std::deque<int> final_deque;
        processInputs(argc, argv, vector, deque);
        createPairs(vector, even);
        extractMins(even, final_vector, final_deque);
        
        clock_t start_vector = clock();
        std::sort(final_vector.begin(), final_vector.end());
        
        insertMaxs(even, final_vector);

        clock_t end_vector = clock();
        double time_vector = 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;

        clock_t start_deque = clock();

        sortAndInsertMaxs(even, final_deque);
        
        clock_t end_deque = clock();
        double time_deque = 1000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;
        
        removeMinusOne(final_vector, final_deque);
        
        printResults(final_vector, "Final sorted vector:");
        printResults(final_deque, "Final sorted deque:");
        std::cout << std::endl;
        
        std::cout << "Time to sort and insert using std::vector: " << time_vector << " ms" << std::endl;
        std::cout << "Time to sort and insert using std::deque: " << time_deque << " ms" << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
