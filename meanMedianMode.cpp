#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

string modeTypeFunction(vector<float>& mode) { // Mode type function
    string modeType;

    if (mode[0] == 0) { // If mode is zero, ends the function
        exit(0);
    }

    switch (mode.size()) { // Determines the mode type via mode vector size
        case 1 : modeType = "Unimodal"; break;
        case 2 : modeType = "Bimodal"; break;
        case 3 : modeType = "Trimodal"; break;
        default : modeType = "Multimodal"; break;
    }

    return modeType;
}

vector<float> modeFunction(vector<float>& numbers) { // Mode function
    int frequency; // Declarations

    int highestFrequency = 2; // Highest frequency to detect is 2

    vector<float> mode; // Vector for modes

    for (int c = 0; c < numbers.size(); c++) { // Mode calculator
        bool usedAlready = false; // Makes sure to not use the same numbers

        for (int d = 0; d < c; d++) {
            if (numbers[c] == numbers[d])
                usedAlready = true;
        }

        if (usedAlready)
            continue;

        frequency = count(numbers.begin(), numbers.end(), numbers[c]); // Frequency calculator

        if (frequency > highestFrequency) { // Gets the mode and puts it in the mode vector
            mode.clear();
            mode.push_back(numbers[c]);
            highestFrequency = frequency;
        }

        else if (frequency == highestFrequency) { // If there are many modes, puts it in the mode vector
            mode.push_back(numbers[c]);
        }
    }

    if (mode.empty()) { // If there are no modes, puts the mode as zero
        mode.push_back(0);
    }

    return mode;
}

float medianFunction(int totalNumbers, vector<float>& numbers) { // Median function
    float median;

    sort(numbers.begin(), numbers.end()); // Sorts the numbers

    if (totalNumbers % 2 == 0) { // If the total of the numbers is even, adds the 2 numbers in the middle and divides both by 2
        median = (numbers[(totalNumbers / 2) - 1] + numbers[(totalNumbers / 2)]) / 2;
    }

    else { // Finds the middle number
        median = numbers[(totalNumbers / 2)];
    }

    return median;
}

float meanFunction(int totalNumbers, vector<float>& numbers) { // Mean function
    float mean;

    float sum = 0;

    for (int b = 0; b < numbers.size(); b++) { // Gets the sum of all numbers
        sum += numbers[b];
    }

    mean = sum / totalNumbers; // Divides the sum to the total numbers to get the mean

    return mean;
}

int main () {
    float mean, median, number; // Declarations

    string modeType;
    string numberString;

    vector<float> mode;
    vector<float> numbers;

    cout << "Mean, median, and mode generator." << endl;

    cout << "\nEnter the set of numbers(enter n if you are done putting numbers): " << endl;

    for (int i = 1; i > 0; i++) { // Infinite loop to ask the user for the numbers
        cout << "Enter number " << i << ": ";
        cin >> numberString;

        if (numberString == "n") // Stops if the user inputs "n"
            break;

        try {
            number = stof(numberString); // Converts the string to float
        }
        catch (invalid_argument&) { // If the user inputs other letters besides n, ignore the input and ask again
            continue;
        }

        numbers.push_back(number); // Stores the numbers in the vector
    }

    cout << endl;

    if (numbers.empty()) { // If there are no numbers in the vector, end the program
        cout << "Invalid set of numbers. Please try again." << endl;
        return 0;
    }

    int totalNumbers = numbers.size(); // Gets the total number for readability

    cout << "\nThe numbers are: ";

    for (int a = 0; a < numbers.size(); a++) { // Prints all the numbers in a readable way
        cout << numbers[a];

        if (a < numbers.size() - 1) 
            cout << ", ";
    }

    cout << endl;
    cout << endl;
    
    mean = meanFunction(totalNumbers, numbers); // Calls the mean function
    cout << "The mean is " << mean << endl;
    
    median = medianFunction(totalNumbers, numbers); // Calls the median function
    cout << "The median is " << median << endl;

    mode = modeFunction(numbers); // Calls the mode function
    cout << "The mode" << (mode.size() > 1 ? "s are " : " is ");

    for (int e = 0; e < mode.size(); e++) { // Prints the mode
        cout << mode[e];

        if (e < mode.size() - 1) 
            cout << ", ";
    }

    modeType = modeTypeFunction(mode); // Prints the mode type
    cout << " - " << modeType << endl;

}

