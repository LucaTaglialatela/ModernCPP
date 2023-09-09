#ifndef _SEC13_CHALLENGE_H_
#define _SEC13_CHALLENGE_H_

#include <string>
#include <vector>

class Movie {
    private:
        std::string name;
        std::string rating; // G, PG, PG-13, R
        int watched;
    
    public:
        Movie(std::string n, std::string r, int w = 0);

        std::string getName();

        std::string getRating();

        int getWatched();

        void incrementWatched();
};

class Movies {
    private:
        std::vector<Movie> movie_collection;
    
    public:
        int inCollection(std::string name);

        void addMovie(std::string name, std::string rating, int watched = 0);

        void addWatchCount(std::string name);

        void display();
};

void section_13_challenge();

#endif // _SEC13_CHALLENGE_H_