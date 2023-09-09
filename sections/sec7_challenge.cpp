#include "sec7_challenge.h"
#include <iostream>
#include <vector>

using namespace std;

void section_7_challenge() {
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "Vector1:" << endl;
    cout << vector1.at(0) << " " << vector1.at(1) << endl;
    cout << "Vector1 contains: " << vector1.size() << " elements.\n" << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "Vector2:" << endl;
    cout << vector2.at(0) << " " << vector2.at(1) << endl;
    cout << "Vector2 contains: " << vector2.size() << " elements.\n" << endl;

    vector <vector <int>> vector2d;

    vector2d.push_back(vector1);
    vector2d.push_back(vector2);

    cout << "Vector2d:" << endl;
    cout << vector2d.at(0).at(0) << " " << vector2d.at(0).at(1) << endl;
    cout << vector2d.at(1).at(0) << " " << vector2d.at(1).at(1) << '\n' << endl;

    vector1.at(0) = 1000;

    cout << "Vector2d:" << endl;
    cout << vector2d.at(0).at(0) << " " << vector2d.at(0).at(1) << endl;
    cout << vector2d.at(1).at(0) << " " << vector2d.at(1).at(1) << '\n' << endl;

    cout << "Vector1:" << endl;
    cout << vector1.at(0) << " " << vector1.at(1) << '\n' << endl;
}