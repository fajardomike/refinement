#include "puzzle.h"
#include <iostream>

// MEMBER 1: Implement all methods below

int Puzzle::totalAttempted = 0;

Puzzle::Puzzle(const std::string& question,
               const std::string choicesArr[4],
               int correctIndex)
    : question(question), correctIndex(correctIndex) {
    for (int i = 0; i < 4; i++) choices[i] = choicesArr[i];
}

Puzzle::~Puzzle() {}

std::string Puzzle::getQuestion() const {
    return question;
}

std::string Puzzle::getChoice(int i) const {
    return choices[i];
}
