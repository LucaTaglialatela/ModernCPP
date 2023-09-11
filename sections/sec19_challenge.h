#include <string>
#include <vector>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void section_19_challenge_1();

int calculate_score(const std::string &a, const std::string &b);

void section_19_challenge_2();

bool isSubstring(const std::string &a, const std::string &b);

void section_19_challenge_3();
