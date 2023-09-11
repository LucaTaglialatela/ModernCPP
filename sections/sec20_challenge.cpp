#include "sec20_challenge.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <fstream>
#include <algorithm>

// ??
// #include <cctype>
// #include <limits>

using namespace std;

bool isPalindrome(const string &str) {
    deque<char> d;
    for (const auto c: str) {
        if (isalnum(c)) { d.push_back(toupper(c)); }
    }

    while (d.size() >= 2) {
        if (d.front() == d.back()) {
            d.pop_front();
            d.pop_back();
        }
        else {
            return false;
        }
    }

    return true;
}

void section_20_challenge_1() {
    vector<string> test_strings {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore Roma", "A Toyota's a Toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    cout << boolalpha;
    cout << setw(8) << left << "Result" << "String" << endl;
    for (const auto &s: test_strings) {
        cout << setw(8) << left << isPalindrome(s) << s << endl;
    }
    cout << endl;
}

ostream &operator<<(ostream &os, const Song &s) {
    os << setw(20) << left << s.name
       << setw(30) << left << s.artist
       << setw(2) << left << s.rating;
    return os;
}

void display_menu() {
    cout << "\nF - Play first song." << endl;
    cout << "N - Play next song." << endl;
    cout << "P - Play previous song." << endl;
    cout << "A - Add and play a new song at the current location." << endl;
    cout << "L - List the current playlist." << endl;
    cout << "================================" << endl;
    cout << "Enter a selection (Q to quit): " << endl;
}

void play_current_song(const Song &song) {
    cout << "Now playing:" << endl;
    cout << song << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (auto s: playlist) {
        cout << s << endl;
    }
    cout << "Current song:" << endl;
    cout << current_song << endl;
}

Song create_song() {
    string song_name;
    string song_artist;
    int song_rating;

    cout << "Adding and playing new song." << endl;
    cout << "Enter song name: ";
    cin  >> song_name;
    cout << "\nEnter song artist: ";
    cin  >> song_artist;
    cout << "\nEnter song rating: ";
    cin  >> song_rating;
    cout << endl;

    return Song(song_name, song_artist, song_rating);
}

void add_song(list<Song> &playlist, const list<Song>::iterator current_song, const Song &new_song) {
    playlist.insert(current_song, new_song);
}

void section_20_challenge_2() {
    list<Song> playlist {
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}
    };

    list<Song>::iterator current_song {playlist.begin()};

    char selection;
    display_menu();
    cin >> selection;
    cout << endl;
    while (toupper(selection) != 'Q') {
        switch(toupper(selection)) {
            case 'F':
                play_current_song(*current_song);
                break;
            case 'N':
                if (++current_song == playlist.end()) { current_song = playlist.begin(); }
                play_current_song(*current_song);
                break;
            case 'P':
                if (current_song == playlist.begin()) { current_song = playlist.end(); }
                --current_song;
                play_current_song(*current_song);
                break;
            case 'A':
                add_song(playlist, current_song, create_song());
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            default:
                cout << "Invalid option." << endl;
        }
        display_menu();
        cin >> selection;
        cout << endl;
    }

    cout << "Thanks for listening." << endl;
}

void parse_word(string &str) {
    str.erase(remove_if(str.begin(), str.end(),
        [](char c) { return !isalpha(c); }), str.end());

    transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c){ return tolower(c); });
}

void display_word_counts(const map<string, int> &word_counts) {
    cout << setw(20) << left << "Word" << "Count" << endl;
    cout << setw(25) << setfill('-') << "" << endl << setfill(' ');
    for (auto &key: word_counts) {
        cout << setw(20) << left << key.first << key.second << endl;
    }
    cout << endl;
}

void display_word_occurrences(const map<string, set<int>> &word_occurrences) {
    cout << setw(20) << left << "Word" << "Occurrences" << endl;
    cout << setw(31) << setfill('-') << "" << endl << setfill(' ');
    for (auto &key: word_occurrences) {
        cout << setw(20) << left << key.first << "[ ";
        for (auto line_number: key.second) {
            cout << line_number << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void section_20_challenge_3() {
    map<string, int> word_counts;
    map<string, set<int>> word_occurrences;
    ifstream f_in {"./files/sec20_words.txt"};

    if (!f_in) {
        cerr << "Error opening file." << endl;
        return;
    }
    else {
        while (!f_in.eof()) {
            string word;
            f_in >> word;
            parse_word(word);
            word_counts[word]++;
        }
        display_word_counts(word_counts);

        f_in.clear();
        f_in.seekg(0);

        int line_number {1};
        while (!f_in.eof()) {
            string line;
            string word;
            getline(f_in, line);
            stringstream words(line);
            while(words >> word) {
                parse_word(word);
                word_occurrences[word].insert(line_number);
            }
            line_number++;
        }
        display_word_occurrences(word_occurrences);

        f_in.close();
    }

}
