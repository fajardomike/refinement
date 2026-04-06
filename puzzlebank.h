#pragma once
#include "puzzle.h"
#include "department.h"
#include <vector>

// MEMBER 1: Implement puzzlebank.cpp
// Holds and serves puzzles per department.
// Puzzles are loaded from each derived class's getBank() method.
class PuzzleBank {
public:
    PuzzleBank();
    ~PuzzleBank();

    // Load all puzzles from the three derived banks
    void loadAll();

    // Get 3 random non-repeating puzzles for a given department
    // Returns pointers to Puzzle (demonstrates polymorphism)
    std::vector<Puzzle*> getPuzzlesForDay(Department dept);

private:
    std::vector<Puzzle*> mathPuzzles;
    std::vector<Puzzle*> wordPuzzles;
    std::vector<Puzzle*> sciencePuzzles;
};
