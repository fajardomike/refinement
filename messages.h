#pragma once
#include <string>
#include <vector>

// MEMBER 7: Populate these arrays in messages.cpp with Lumon-flavored strings.
// At least 6 strings per array recommended.

extern const std::vector<std::string> CORRECT_MESSAGES;
extern const std::vector<std::string> WRONG_MESSAGES;
extern const std::vector<std::string> DAY_END_MESSAGES;
extern const std::vector<std::string> WAFFLE_PARTY_LINES;
extern const std::vector<std::string> TERMINATED_LINES;

// Returns a random message from the given vector
std::string getRandomMessage(const std::vector<std::string>& messages);
