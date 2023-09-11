#include "sec19_challenge.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void section_19_challenge_1()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // Unformatted display so you can see how to access the vector elements
    cout << setw(40) << tours.title << endl << endl;
    cout << setw(15) << left << "Country"
         << setw(15) << left << "City"
         << setw(10) << right << "Population"
         << setw(10) << right << "Price" << endl;
    cout << setw(50) << setfill('-') << "" << endl;
    cout << setfill(' ');
    for(Country country: tours.countries) {   // loop through the countries
        bool first_row = true;
        for(City city: country.cities) {       // loop through the cities for each country
            cout << setw(15) << left << (first_row ? country.name : "");
            cout << setw(15) << left << city.name
                 << setw(10) << right << city.population
                 << setw(10) << right << setprecision(2) << fixed << city.cost
                 << endl;
            first_row = false;
        }
    }

    cout << endl << endl;
}

int calculate_score(const string &a, const string &b) {
    int score {0};
    for (int i {0}; i < 5; i++) {
        if (a.at(i) == b.at(i)) { score += 1; }
    }
    return score;
}

void section_19_challenge_2() {
    ifstream f_in {"./files/sec19_responses.txt"};

    if (!f_in) {
        cerr << "Error opening file." << endl;
        return;
    }
    string answer_key;
    getline(f_in, answer_key);

    cout << setw(15) << left << "Student" << "Score" << endl;
    cout << setw(20) << setfill('-') << "" << endl << setfill(' ');
    
    int total_score {0};
    while (!f_in.eof()) {
        string student;
        string student_answer;
        int student_score;

        f_in >> student >> student_answer;
        student_score = calculate_score(answer_key, student_answer);
        total_score += student_score;
        cout << setw(15) << left << student << student_score << endl;
    }
    f_in.close();

    double avg_score {static_cast<double>(total_score) / 5.0};
    cout << setw(20) << setfill('-') << "" << endl << setfill(' ');
    cout << setw(15) << left << "Average score" << avg_score << endl;
}

bool isSubstring(const string &a, const string &b) {
    if (a.length() < b.length()) { return false; }

    if (a.find(b) == string::npos) { return false; }

    return true;
}

void section_19_challenge_3() {
    ifstream f_in {"./files/sec19_romeoandjuliet.txt"};

    if (!f_in) {
        cerr << "Error opening file." << endl;
        return;
    }

    string substr;
    cout << "Enter the substring to search for: ";
    cin >> substr;

    int total_words {0};
    int count {0};
    while(!f_in.eof()) {
        string word;
        f_in >> word;
        total_words++;
        if (isSubstring(word, substr)) { count++; }
    }
    f_in.close();

    cout << "Searched " << total_words << " words..." << endl;
    cout << "The substring " << substr << " was found " << count << " times." << endl;
}