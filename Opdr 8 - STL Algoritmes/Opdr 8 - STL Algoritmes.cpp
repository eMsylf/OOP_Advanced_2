#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

template <typename T>
void printVector(std::vector<T> vector) {
    std::cout << "==== Print Vector ====" << std::endl;
    for (T element : vector)
    {
        std::cout << element << std::endl;
    }
    std::cout << "==== End Of Vector ====" << std::endl;
}

int main() {
    std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE kopie van deze vector)
    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
        std::cout << "1)" << std::endl;
    {
        // Kopieer de vector
        std::vector<std::string> coloursCopy_1(colours.size());
        std::copy(colours.begin(), colours.end(), coloursCopy_1.begin());
        printVector(coloursCopy_1);

        // Sorteer de kopie vector op alfabetische volgorde
        std::sort(coloursCopy_1.begin(), coloursCopy_1.end());
        printVector(coloursCopy_1);

        // Zoek op waar "purple" in de vector staat
        std::vector<std::string>::iterator indexOfPurple = std::find(coloursCopy_1.begin(), coloursCopy_1.end(), "purple");

        // Kopieer alles tot aan "purple" naar een nieuwe vector
        std::vector<std::string> coloursBeforePurple(colours.size());
        std::copy(coloursCopy_1.begin(), indexOfPurple, coloursBeforePurple.begin());
        printVector(coloursBeforePurple);

        // Kopieer alles na "purple" naar een nieuwe vector
        std::vector<std::string> coloursAfterPurple(colours.size());
        std::reverse_copy(indexOfPurple + 1, coloursCopy_1.end(), coloursAfterPurple.begin());
        printVector(coloursAfterPurple);

        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 2) alle elementen UPPERCASE te maken.
        std::cout << "2)" << std::endl;
        std::vector<std::string> coloursCopy_2(colours.size());
        std::copy(colours.begin(), colours.end(), coloursCopy_2.begin());

        for (std::string &element : coloursCopy_2) {
            std::transform(element.begin(), element.end(), element.begin(), ::toupper);
        }
        printVector(coloursCopy_2);
    }
    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 3) alle dubbele te verwijderen
        std::cout << "3)" << std::endl;

        // Kopieer de vector
        std::vector<std::string> coloursCopy_3(colours.size());
        std::copy(colours.begin(), colours.end(), coloursCopy_3.begin());
        printVector(coloursCopy_3);

        // Verwijder alle duplicaten
        std::sort(coloursCopy_3.begin(), coloursCopy_3.end());
        coloursCopy_3.erase(unique(coloursCopy_3.begin(), coloursCopy_3.end()), coloursCopy_3.end());
        printVector(coloursCopy_3);
    }

    std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE kopie van deze vector)
    // 1) alle negatieve elementen te verwijderen
    std::cout << "1)" << std::endl;
    std::vector<double> numbers1(numbers.size());
    std::copy(numbers.begin(), numbers.end(), numbers1.begin());
    for (auto it = numbers1.begin(); it != numbers1.end(); ++it) {
        if (*it < 0)
            it = numbers1.erase(it);
    }
    printVector(numbers1);

    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    std::cout << "2)" << std::endl;
    std::vector<double> numbers2(numbers.size());
    std::copy(numbers.begin(), numbers.end(), numbers2.begin());
    

    // 3) 
    std::cout << "3)" << std::endl;
    std::vector<double> numbers3(numbers.size());
    std::copy(numbers.begin(), numbers.end(), numbers3.begin());
    //de som, 
    double sum = std::accumulate(numbers3.begin(), numbers3.end(), 0.00);
    std::cout << "Som: " << sum << std::endl;
    //het gemiddelde, 
    double average = sum / numbers.size();
    std::cout << "Gemiddelde: " << average << std::endl;
    //en het product van alle getallen te berekenen
    double product = std::accumulate(numbers3.begin(), numbers3.end(), 1.00, std::multiplies<double>());
    std::cout << "Product: " << product << std::endl;

    return 0;
}