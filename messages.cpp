#include "messages.h"

#include <cstdlib>  // rand

// Lumon-flavored message pools.
// Tone: dry, corporate, slightly eerie.

const std::vector<std::string> CORRECT_MESSAGES = {
    "Your compliance is noted and rewarded.",
    "Correct. Please enjoy a brief moment of approved satisfaction.",
    "Accuracy recorded. The work recognizes you.",
    "Affirmed. Your output remains within acceptable variance.",
    "Well done. Your instincts appear properly conditioned.",
    "Correct response received. Continue without celebration."
};

const std::vector<std::string> WRONG_MESSAGES = {
    "This error has been logged. Kier remains hopeful.",
    "Incorrect. A brief recalibration has been scheduled internally.",
    "That choice was not optimal. Please realign with company values.",
    "Wrong. The numbers did not consent to that interpretation.",
    "Inaccuracy detected. Your future self will appreciate improvement.",
    "Incorrect response. Please refrain from forming attachments to guesses."
};

const std::vector<std::string> DAY_END_MESSAGES = {
    "The work continues. Tomorrow brings new tasks.",
    "Your day concludes. Please leave your thoughts in the designated bin.",
    "A satisfactory amount of refinement has occurred.",
    "Rest is permitted. Reflection is discouraged.",
    "Your progress has been assessed. The results are proprietary.",
    "End of day. Return refreshed and appropriately blank."
};

const std::vector<std::string> WAFFLE_PARTY_LINES = {
    "A waffle party has been authorized. You have earned it.",
    "Please accept these waffles as a symbolic substitute for freedom.",
    "Syrup rations unlocked. Joy levels may now exceed baseline.",
    "Congratulations. The celebration will proceed in a controlled manner."
};

const std::vector<std::string> TERMINATED_LINES = {
    "Your performance was insufficient. Your innie will be reassigned.",
    "Termination approved. Please step away from the terminal.",
    "Your access has been revoked. The work will continue without you.",
    "You are no longer required. Thank you for your service to the numbers."
};

std::string getRandomMessage(const std::vector<std::string>& messages) {
    if (messages.empty()) return "";
    return messages[std::rand() % messages.size()];
}
