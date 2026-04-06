#include "sciencepuzzle.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor: passes all arguments up to the parent Puzzle class
SciencePuzzle::SciencePuzzle(const std::string& question,
                             const std::string choicesArr[4],
                             int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// display(): prints the department label, then the question and choices A-D
void SciencePuzzle::display() const {
    std::vector<std::string> opts = getOptions();
    std::cout << "\n[Biotech & Wellness]\n";
    std::cout << getQuestion() << "\n\n";
    std::cout << "  A. " << opts[0] << "\n";
    std::cout << "  B. " << opts[1] << "\n";
    std::cout << "  C. " << opts[2] << "\n";
    std::cout << "  D. " << opts[3] << "\n\n";
}

// checkAnswer(): returns true if the player's choice matches the correct index
bool SciencePuzzle::checkAnswer(int playerChoice) const {
    return playerChoice == correctIndex;
}