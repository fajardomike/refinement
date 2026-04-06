#include "sciencepuzzle.h"
#include <iostream>

// Constructor: passes all arguments up to the parent Puzzle class
SciencePuzzle::SciencePuzzle(const std::string& question,
                             const std::string choicesArr[4],
                             int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// display(): prints the department label, then the question and choices A-D
void SciencePuzzle::display() const {
    std::cout << "\n[Biotech & Wellness]\n";
    std::cout << question << "\n\n";
    std::cout << " A. " << choices[0] << "\n";
    std::cout << " B. " << choices[1] << "\n";
    std::cout << " C. " << choices[2] << "\n";
    std::cout << " D. " << choices[3] << "\n\n";
}