#pragma once
#include "puzzle.h"

// Derived class for Math / Logic puzzles (Macrodata Refinement dept.)
// MEMBER 4: Implement mathpuzzle.cpp and hardcode 8 questions in getBank()
class MathPuzzle : public Puzzle {
public:
    MathPuzzle(const std::string& question,
               const std::string choicesArr[4],
               int correctIndex);

    void display() const override;
    bool checkAnswer(int playerChoice) const override;

    // Returns a vector of 8 hardcoded MathPuzzle questions
    // Implement this in mathpuzzle.cpp
    static std::vector<MathPuzzle> getBank();
};
