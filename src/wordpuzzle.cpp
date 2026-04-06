#include "wordpuzzle.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor: delegates to parent Puzzle constructor via initializer list
WordPuzzle::WordPuzzle(const std::string& question,
                       const std::string choicesArr[4],
                       int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// Displays [Lexical Processing] department label, then question and choices A-D
void WordPuzzle::display() const {
    std::vector<std::string> opts = getOptions();
    std::cout << "\n[Lexical Processing]\n";
    std::cout << getQuestion() << "\n\n";
    std::cout << "  A. " << opts[0] << "\n";
    std::cout << "  B. " << opts[1] << "\n";
    std::cout << "  C. " << opts[2] << "\n";
    std::cout << "  D. " << opts[3] << "\n\n";
}

// Returns true if playerChoice matches the stored correct index
bool WordPuzzle::checkAnswer(int playerChoice) const {
    return playerChoice == correctIndex;
}
