#ifndef _SEC10_CHALLENGE_H_
#define _SEC10_CHALLENGE_H_

#include <string>

std::string encrypt(std::string message, std::string alphabet, std::string key);

std::string decrypt(std::string message, std::string alphabet, std::string key);

void section_10_challenge();

#endif // _SEC10_CHALLENGE_H_