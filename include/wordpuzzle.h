#pragma once
#include "puzzle.h"

// Derived class for Language / Reading puzzles (Lexical Processing dept.)
class WordPuzzle : public Puzzle {
public:
    WordPuzzle(const std::string& question,
               const std::string choicesArr[4],
               int correctIndex);

    void display() const override;
    bool checkAnswer(int playerChoice) const override;
};
