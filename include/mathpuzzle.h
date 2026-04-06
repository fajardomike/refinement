#pragma once
#include "puzzle.h"

// Derived class for Math / Logic puzzles (Macrodata Refinement dept.)
class MathPuzzle : public Puzzle {
public:
    MathPuzzle(const std::string& question,
               const std::string choicesArr[4],
               int correctIndex);

    void display() const override;
    bool checkAnswer(int playerChoice) const override;
};
