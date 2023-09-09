#include "sec13_challenge.h"
#include <iostream>
#include <string.h>

using namespace std;

Movie::Movie(string n, string r, int w)
    : name {n}, rating {r}, watched {w} {
}

string Movie::getName() { return name; }

string Movie::getRating() { return rating; }

int Movie::getWatched() { return watched; }

void Movie::incrementWatched() { watched++; }

int Movies::inCollection(string name) {
    for (size_t i {0}; i < movie_collection.size(); i++) {
        int res = stricmp(name.c_str(), movie_collection.at(i).getName().c_str());
        if (res == 0) { return i; }
    }
    return -1;
};

void Movies::addMovie(string name, string rating, int watched) {
    int idx = inCollection(name);
    if (idx == -1) {
        movie_collection.push_back(Movie(name, rating, watched));
    }
    else {
        cout << "Error: Movie already exists in collection.\n" << endl;
    }
};

void Movies::addWatchCount(string name) {
    int idx = inCollection(name);
    if (idx >= 0) {
        movie_collection.at(idx).incrementWatched();
    }
    else {
        cout << "Error: Movie does not exist in collection.\n" << endl;
    }
};

void Movies::display() {
    cout << "The collection of movies:" << endl;
    for (auto movie: movie_collection) {
        cout << "Name: " << movie.getName() << ", rating: " << movie.getRating() << ", times watched: " << movie.getWatched() << endl;
    }
    cout << '\n';
};

void section_13_challenge() {
    Movies movies;

    movies.display();

    // G, PG, PG-13, R
    movies.addMovie("Shrek", "G");
    movies.addMovie("Scary Stories to Tell in the Dark", "R");
    movies.addMovie("Barbarian", "R", 1);

    movies.display();

    movies.addWatchCount("Scary Stories to Tell in the Dark");

    movies.display();

    return;
}