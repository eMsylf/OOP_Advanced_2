// Opdr 7 - Template Functie
// Bob Jeltes

#include <iostream>

template<typename T>
T biggest(T first, T second) {
    if (first > second) return first;
    return second;
}

template<typename T>
T* sortArray(T array[]) {
    
    T* newArray = new T[[sizeof(array)]];

    bool sortComplete = false;

    for (int i = 0; i < sizeof(array); i++)
    {
        //T currentElement = array[i];
        std::cout << "comparing element " << i << std::endl;

        for (int j = i; j > 0 ; j--)
        {
            // Pak het vergeleken element
            T lowestItem = array[j];
            T highestItem = array[j-1];

            std::cout << "Compare " << j << " and " << j-1 << std::endl;

            // Check of het dezelfde grootte is
            if (lowestItem == highestItem) {
                break;
            }

            // Als het hoogst gesorteerde item ook de grootste is, doe niks
            if (biggest(lowestItem, highestItem) == highestItem) {
                break;
            }
            // Als het hoogst gesorteerde item ook de kleinste is, verwissel
            else {
                newArray[j] = lowestItem;
                newArray[j - 1] = highestItem;
            }
        }
    }

    return newArray;
}

int main()
{
    int a = 1;
    int b = 2;
    int gimme = biggest(a, b);
    std::cout << gimme << std::endl;

    std::string stringA = "a";
    std::string stringB = "aa";
    std::string gimmeString = biggest(stringA, stringB);
    std::cout << gimmeString << std::endl;

    /*std::srand(NULL);
    std::rand();*/

    float floatArray[] = { 2.3, 2.5, 3.1, 1.1 };
    for (int i = 0; i < 4; i++)
    {
        std::cout << floatArray[i] << std::endl;
    }

    float* sortedFloatArray = sortArray(floatArray);

    for (size_t i = 0; i < sizeof(sortedFloatArray); i++)
    {
        std::cout << sortedFloatArray[i] << std::endl;
    }

    return 0;
}
