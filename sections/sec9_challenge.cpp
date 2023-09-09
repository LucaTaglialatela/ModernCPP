#include "sec9_challenge.h"
#include <iostream>
#include <vector>

using namespace std;

char displayMenu() {
    char selection;

    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";

    cin >> selection;

    cout << endl;

    return toupper(selection);
};

void section_9_challenge() {
    vector<int> numbers;
    char selection;

    selection = displayMenu();

    while (selection != 'q' && selection != 'Q') {
        switch (selection) {
            case 'p':
            case 'P':
                if (numbers.size() > 0) {
                    cout << "[ ";
                    for (auto e: numbers) {
                        cout << e << " ";
                    }
                    cout << "]" << endl;
                }
                else {
                    cout << "[] - the list is empty" << endl;
                }
                break;
            case 'a':
            case 'A':
                int number;
                cout << "Please enter a number: ";
                cin >> number;
                numbers.push_back(number);
                cout << number << " added." << endl;
                break;
            case 'm':
            case 'M':
                if (numbers.size() > 0) {
                    double total {0};
                    for (auto e: numbers) {
                        total += e;
                    }
                    cout << "Mean: " << total / numbers.size() << endl;
                }
                else {
                    cout << "Unable to calculate the mean - no data." << endl;
                }
                break;
            case 's':
            case 'S':
                if (numbers.size() > 0) {
                    int min {numbers.at(0)};
                    for (auto e: numbers) {
                        if (e < min) {
                            min = e;
                        }
                    }
                    cout << "The smallest number is " << min << endl;
                }
                else {
                    cout << "Unable to determine the smallest number - list is empty." << endl;
                }
                break;
            case 'l':
            case 'L':
                if (numbers.size() > 0) {
                    int max {numbers.at(0)};
                    for (auto e: numbers) {
                        if (e > max) {
                            max = e;
                        }
                    }
                    cout << "The largest number is " << max << endl;
                }
                else {
                    cout << "Unable to determine the largest number - list is empty." << endl;
                }
                break;
            default:
                cout << "Unknown selection, please try again." << endl;
        }

        selection = displayMenu();
    }

    cout << "Goodbye." << endl;

    return;
}