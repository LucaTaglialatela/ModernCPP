#include "sec11_challenge.h"
#include "sec9_challenge.h"
#include <iostream>

using namespace std;

void print_numbers(const vector<int> &numbers_list, size_t list_size) {
    if (list_size > 0) {
        cout << "[ ";
        for (size_t i {0}; i < list_size; i++) {
            cout << numbers_list.at(i) << ' ';
        }
        cout << ']';
    }
    else {
        cout << "[] - the list is empty" << endl;
    }
}

void add_number(vector<int> &numbers_list) {
    int number;
    cout << "Please enter a number: ";
    cin >> number;
    numbers_list.push_back(number);
    cout << number << " added." << endl;
}

void get_mean(const vector<int> &numbers_list, size_t list_size) {
    if (list_size > 0) {
        double total {0};
        for (size_t i {0}; i < list_size; i++) {
            total += numbers_list.at(i);
        }
        cout << "Mean: " << total / list_size << endl;
    }
    else {
        cout << "Unable to calculate the mean - no data." << endl;
    }
}

void get_smallest(const vector<int> &numbers_list, size_t list_size) {
    if (list_size > 0) {
        int min {numbers_list.at(0)};
        for (size_t i {0}; i < list_size; i++) {
            int cur = numbers_list.at(i);
            if (cur < min) { min = cur; }
        }
        cout << "The smallest number is " << min << endl;
    }
    else {
        cout << "Unable to determine the smallest number - list is empty." << endl;
    }
}

void get_largest(const vector<int> &numbers_list, size_t list_size) {
    if (list_size > 0) {
        int max {numbers_list.at(0)};
        for (size_t i {0}; i < list_size; i++) {
            int cur = numbers_list.at(i);
            if (cur > max) { max = cur; }
        }
        cout << "The largest number is " << max << endl;
    }
    else {
        cout << "Unable to determine the largest number - list is empty." << endl;
    }
}

void section_11_challenge() {
    vector<int> numbers;
    char selection;

    selection = displayMenu();

    while (selection != 'Q') {
        switch (selection) {
            case 'P':
                print_numbers(numbers, numbers.size());
                break;
            case 'A':
                add_number(numbers);
                break;
            case 'M':
                get_mean(numbers, numbers.size());
                break;
            case 'S':
                get_smallest(numbers, numbers.size());
                break;
            case 'L':
                get_largest(numbers, numbers.size());
                break;
            default:
                cout << "Unknown selection, please try again." << endl;
        }

        selection = displayMenu();
    }

    cout << "Goodbye." << endl;
}
