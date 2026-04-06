#include "mathpuzzle.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor: Calls parent Puzzle constructor via initializer list
MathPuzzle::MathPuzzle(const std::string& question, const std::string choicesArr[4], int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// display(): Prints department label then question and choices A-D
void MathPuzzle::display() const {
    std::vector<std::string> opts = getOptions();
    std::cout << "\n[Macrodata Refinement]\n";
    std::cout << getQuestion() << "\n\n";
    std::cout << "  A. " << opts[0] << "\n";
    std::cout << "  B. " << opts[1] << "\n";
    std::cout << "  C. " << opts[2] << "\n";
    std::cout << "  D. " << opts[3] << "\n\n";
}

// checkAnswer(): Returns true if playerChoice equals correctIndex
bool MathPuzzle::checkAnswer(int playerChoice) const {
    return playerChoice == correctIndex;
}
