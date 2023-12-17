#include <iostream>
#include "myArray.cpp"

int main() {
    int* myArray;
    size_t size = 10; // Change this to the desired size of your array.
    
    myArray = myArray::initializeArray(size);
    
    std::cout << "Array: ";
    myArray::printArray(myArray, size);
    
    int minVal = myArray::findMin(myArray, size);
    int maxVal = myArray::findMax(myArray, size);
    
    std::cout << "Minimum: " << minVal << std::endl;
    std::cout << "Maximum: " << maxVal << std::endl;

    if (nullptr != myArray) {
      delete[] myArray;
      myArray = nullptr;
    }
    
    return 0;
}
