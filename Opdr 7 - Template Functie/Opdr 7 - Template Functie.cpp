// Opdr 7 - Template Functie
// Bob Jeltes

#include <iostream>
#include "CustomQueue.h"

template<typename T>
T biggest(T first, T second) {
    if (first > second) return first;
    return second;
}

// Array functies hebben een arrayLength parameter omdat het dynamisch uitzoeken van de length van een array voor strings onmogelijk lijkt
template<typename T>
T* sortArray(T _array[], int arrayLength) {
    //T arrayElement = _array[0];
    for (int i = 0; i < arrayLength; i++)
    {
        //T currentElement = array[i];
        std::cout << "comparing element " << i << std::endl;

        for (int j = i; j > 0 ; j--)
        {
            // Pak het vergeleken element
            T highestItem = _array[j];
            T lowestItem = _array[j-1];

            std::cout << "Compare " << j << ": " << _array[j] << " and " << j - 1 << ": " << _array[j - 1] << std::endl;

            // Check of het dezelfde grootte is
            // Als het hoogst gesorteerde item ook de grootste is, doe niks
            if (lowestItem == highestItem || biggest(lowestItem, highestItem) == highestItem) {
                std::cout << _array[j] << " is in the right spot" << std::endl;
                break;
            }
            // Als het hoogst gesorteerde item ook de kleinste is, verwissel
            else {
                _array[j] = lowestItem;
                _array[j - 1] = highestItem;
                std::cout << lowestItem << " is bigger than " << highestItem << std::endl << "Switch " << j << " and " << j - 1 << std::endl;
                //std::cout << " > " << j << " : " << _array[j] << std::endl;
            }
        }

        std::cout << "New array: " << std::endl;
        for (int i = 0; i < arrayLength; i++)
        {
            std::cout << " " << _array[i] << std::endl;
        }
    }

    return _array;
}

template<typename T>
void printArray(std::string arrayName, T _array[], int arrayLength) {
    std::cout << "==== Print " + arrayName + " ====" << std::endl;
    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << "Element " << i << ": " << _array[i] << std::endl;
    }

    //int arrayLength = sizeof(*_array) / sizeof(_array[0]);
    std::cout
        << "= Array statistics =" << std::endl
        << "Array length: " << arrayLength << std::endl
        << "Array size: " << sizeof(_array) << std::endl
        << "Array unit size: " << sizeof(_array[0]) << std::endl
        << "=====================" << std::endl;
}

int main()
{
    std::cout << std::endl << "=============================" << std::endl << "Floats" << std::endl << "=============================" << std::endl;
    float floatArray[] = { 2.3, 2.5, 3.1, 1.1, 1.1 };
    printArray("Float Array", floatArray, 5);

    float* sortedFloatArray = sortArray(floatArray, 5);
    printArray("Sorted Float Array", sortedFloatArray, 5);

    std::cout << std::endl << "=============================" << std::endl << "Strings" << std::endl <<"=============================" << std::endl;

    std::string stringArray[] = { "a", "aa", "aaa", "a", "a", "a" };
    printArray("String Array", stringArray, 6);

    std::string* sortedStringArray = sortArray(stringArray, 6);
    printArray("Sorted String Array", sortedStringArray, 6);

    CustomQueue<int> customQ;
    int input = 0;
    while (input >= 0) {
        std::cout << "Input a positive integer to add it to the queue" << std::endl;
        std::cin >> input;
        std::cout << "Input: " << input << std::endl;
    }

    /*char chInput;
    while (chInput) {
        std::cout << "Input a 'p' to pop the first number in the queue";
        std::cin >> chInput;
        if (chInput = 'p') {

        }
    }*/
}
