#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>

bool isPalindrome(const std::string &str);

void section_20_challenge_1();

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name {name}, artist {artist}, rating {rating} {}

    std::string get_name() { return name; }
    
    std::string get_artist() { return artist; }
    
    int get_rating() { return rating; }

    bool operator<(const Song &rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const {
        return this->name == rhs.name;
    }
};

void display_menu();

void play_current_song(const Song &song);

void display_playlist(const std::list<Song> &playlist, const Song &current_song);

Song create_song();

void add_song(std::list<Song> &playlist, const Song &current_song, const Song &new_song);

void section_20_challenge_2();

void parse_word(std::string &str);

void display_word_counts(const std::map<std::string, int> &word_counts);

void display_word_occurrences(const std::map<std::string, std::set<int>> &word_occurrences);

void section_20_challenge_3();
