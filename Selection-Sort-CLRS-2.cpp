// Solution to exercise [2.2-2]
// Simple variant to s sort

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

int main() {

	// Initialize an array
    std::vector<int> random_array = {3,2,7,4,8,5}; 
	
    for (int i = 0; i < random_array.size(); i++) {
        int smallest = i; // Set the current element as the smallest
        for (int k = i; k < random_array.size(); k++) { // loop and find the smallest element and save its index
            if (random_array[smallest] > random_array[k]) {
                smallest = k;
            }
        }
        
		// Finally, swap them
        int temp = random_array[i]; 
        random_array[i] = random_array[smallest];
        random_array[smallest] = temp;
    }
	
	// < ------------------- PRINTING UTILITY --------------------->
    for (int i = 0; i < random_array.size(); i++) {
        std::cout << std::endl;
        std::cout << random_array[i];
        std::cout << std::endl;
    }
    return 0;
}
