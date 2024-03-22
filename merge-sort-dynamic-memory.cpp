#include <iostream>
#include <cmath>

int* MergeSort(int* input, int size);
int* Merge(int left[], int right[], int leftSize, int rightSize);

int main() {
    int toSort[] = {9,10,37,-1,-3,20,10,39};
    int size = 8;
    
    int* sorted = MergeSort(toSort, size);
    
    for (int i = 0; i < size; i++) {
        std::cout << sorted[i] << std::endl;
    }
    
    free(sorted);
    
    return 0;
}

int* MergeSort(int* input, int size){
    int mid = std::floor(size/2);
    
    int leftSize = mid;
    int rightSize = size - mid;
    
    if (size == 1) {
        return input;
    }
    
    int* left;
    int* right;
    
    left = (int*)malloc(leftSize * sizeof(int));
    right = (int*)malloc(rightSize * sizeof(int));
    
    for (int i = 0; i < leftSize; i++) {
        left[i] = input[i];
    }
    
    for (int i = 0; i < rightSize; i++) {
        right[i] = input[mid + i];
    } 
    
    left = MergeSort(left, leftSize);
    right = MergeSort(right, rightSize);
    
    return Merge(left, right, leftSize, rightSize);
}

int* Merge(int left[], int right[], int leftSize, int rightSize){
    
    int leftPointer = 0;
    int rightPointer = 0;
    int resultPointer = 0;
    int* result;
    
    result = (int*)malloc((leftSize + rightSize) * sizeof(int));
    
    while (leftPointer < leftSize && rightPointer < rightSize) {
        if (left[leftPointer] < right[rightPointer]) {
            result[resultPointer] = left[leftPointer];
            leftPointer++;
            resultPointer++;
        }
        else {
            result[resultPointer] = right[rightPointer];
            rightPointer++;
            resultPointer++;
        }
    }
    
    while (leftPointer < leftSize) {
        result[resultPointer] = left[leftPointer];
        leftPointer++;
        resultPointer++;
    }
    
    while (rightPointer < rightSize) {
        result[resultPointer] = right[rightPointer];
        rightPointer++;
        resultPointer++;         
    }
    
    free(left);
    free(right);
    
    return result;
}

