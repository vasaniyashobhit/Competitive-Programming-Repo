#include <iostream>  // For input/output operations
#include <vector>    // For using std::vector (dynamic array)
#include <random>    // For the modern C++ random number library
#include <limits>    // For std::numeric_limits

using namespace std;

int main() {
    int arraySize;
    int minVal, maxVal;

    // Get array size from user
    cout << "Enter the desired size of the array: ";
    cin >> arraySize;


    // Get min and max values from user
    cout << "Enter the minimum value (a) for random numbers: ";
    cin >> minVal;
    cout << "Enter the maximum value (b) for random numbers: ";
    cin >> maxVal;


    // Create a vector (dynamic array) to store the random numbers
    vector<int> randomArray(arraySize);

    // Initialize the random number generator
    // Using random_device for a good quality seed, falling back to time if not available
    random_device rd;
    mt19937 gen(rd());

    // Define a uniform integer distribution for the desired range [minVal, maxVal]
    uniform_int_distribution<> distr(minVal, maxVal);

    // Fill the array with random numbers
    for (int i = 0; i < arraySize; ++i) {
        randomArray[i] = distr(gen);
    }

    // Print the generated array
    cout << "\nGenerated array of random numbers:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << randomArray[i] << " ";
    }
    cout << endl;

    return 0;
}