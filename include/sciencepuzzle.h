#pragma once
#include "puzzle.h"

// Derived class for Science puzzles (Biotech & Wellness dept.)
class SciencePuzzle : public Puzzle {
public:
    SciencePuzzle(const std::string& question,
                  const std::string choicesArr[4],
                  int correctIndex);

    void display() const override;
    bool checkAnswer(int playerChoice) const override;
};
