// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
int BinarySearch(std::vector<int>& array, int elementToSearchFor, int left, int right);

int main() {
                            //0,1,2,3,4,5,6,7,8,9,   10
    std::vector<int> array = {1,2,3,4,5,6,7,8,9,100,150};
    int elementToSearchFor = 4;
    int result = BinarySearch(array, elementToSearchFor, 0, array.size());
    
    std::cout << result;
    
    return 0;
}

int BinarySearch(std::vector<int>& array, int elementToSearchFor, int left, int right) {
    int mid = (left + right) / 2;
    if (array[mid] < elementToSearchFor) {
        // element is on the right
        left = mid;
        right = array.size();
        return BinarySearch(array, elementToSearchFor, left, right);
    }
    
    if (array[mid] > elementToSearchFor) {
        // element is on the left
        left = 0;
        right = mid;
        return BinarySearch(array, elementToSearchFor, left, right);
    }
    
    if (array[mid] == elementToSearchFor) {
        return mid;
    }
    
    return 0;
}
