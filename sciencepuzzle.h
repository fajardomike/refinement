#pragma once
#include "puzzle.h"
#include <vector>

// Derived class for Science puzzles (Biotech & Wellness dept.)
// MEMBER 6: Implement sciencepuzzle.cpp and hardcode 8 questions in getBank()
class SciencePuzzle : public Puzzle {
public:
    SciencePuzzle(const std::string& question,
                  const std::string choicesArr[4],
                  int correctIndex);

    void display() const override;
    bool checkAnswer(int playerChoice) const override;

    // Returns a vector of 8 hardcoded SciencePuzzle questions
    // Implement this in sciencepuzzle.cpp
    static std::vector<SciencePuzzle> getBank();
};
