#pragma once
#include "puzzle.h"
#include <vector>

// Derived class for Language / Reading puzzles (Lexical Processing dept.)
// MEMBER 5: Implement wordpuzzle.cpp and hardcode 8 questions in getBank()
class WordPuzzle : public Puzzle {
public:
    WordPuzzle(const std::string& question,
               const std::string choicesArr[4],
               int correctIndex);

    void display() const override;
    bool checkAnswer(int playerChoice) const override;

    // Returns a vector of 8 hardcoded WordPuzzle questions
    // Implement this in wordpuzzle.cpp
    static std::vector<WordPuzzle> getBank();
};
