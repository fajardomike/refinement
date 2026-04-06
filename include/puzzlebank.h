#pragma once
#include "puzzle.h"
#include "department.h"
#include <vector>
#include <string>

// Holds and serves puzzles per department.
// Puzzles are loaded from plain-text data files at runtime.
class PuzzleBank {
public:
    PuzzleBank();
    ~PuzzleBank();

    // Load all puzzles from the three data files
    void loadAll();

    // Get 3 random non-repeating puzzles for a given department
    // Returns pointers to Puzzle (demonstrates polymorphism)
    std::vector<Puzzle*> getPuzzlesForDay(Department dept);

private:
    std::vector<Puzzle*> mathPuzzles;
    std::vector<Puzzle*> wordPuzzles;
    std::vector<Puzzle*> sciencePuzzles;

    // Reads a pipe-delimited question file and returns heap-allocated puzzles
    std::vector<Puzzle*> loadFromFile(const std::string& filepath, Department dept);
};
