#include "sec6_challenge.h"
#include <iostream>

using namespace std;

void section_6_challenge() {
    int number_small_rooms {0};
    int number_large_rooms {0};
    double cost {0.0};
    double tax {0.0};
    const double small_room_price {25};
    const double large_room_price {35};
    const double tax_rate {0.06};
    const int validity_duration {30};

    cout << "Please enter the number of small rooms: " << endl;
    
    cin >> number_small_rooms;
    
    cout << "Please enter the number of large rooms: " << endl;

    cin >> number_large_rooms;

    cout << "Price per small room: " << small_room_price << endl;

    cout << "Price per large room: " << large_room_price << endl;

    cost = number_small_rooms * small_room_price + number_large_rooms * large_room_price;

    cout << "Cost: " << cost << endl;
    
    tax = cost * tax_rate;

    cout << "Tax: " << tax << endl;
    
    cout << "======================================" << endl;

    cout << "Total: " << cost + tax << endl;
    
    cout << "This estimate is valid for " << validity_duration << " days." << endl;

    return;
}