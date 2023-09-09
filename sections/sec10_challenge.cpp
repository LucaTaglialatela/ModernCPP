#include "sec10_challenge.h"
#include <iostream>

using namespace std;

// Section 10 challenge helper functions
string encrypt(string message, string alphabet, string key) {
    for (size_t i {0}; i < message.length(); i++) {
        size_t idx = alphabet.find(message.at(i));
        if (idx != string::npos)
            message.at(i) = key.at(idx);
    }
    return message;
}

string decrypt(string message, string alphabet, string key) {
    return encrypt(message, key, alphabet);
}

void section_10_challenge() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string message;

    cout << "Enter a secret message: ";

    getline(cin, message);

    cout << "\nEncrypting message..." << endl;

    message = encrypt(message, alphabet, key);

    cout << "\nEncrypted message: " << message << endl;

    cout << "\nDecrypting message..." << endl;

    message = decrypt(message, alphabet, key);

    cout << "\nDecrypted message: " << message << endl;

    return;
}