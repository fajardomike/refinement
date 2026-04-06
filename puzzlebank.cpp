#include "puzzlebank.h"
#include "mathpuzzle.h"
#include "wordpuzzle.h"
#include "sciencepuzzle.h"
#include <algorithm>
#include <random>

PuzzleBank::PuzzleBank() {}

PuzzleBank::~PuzzleBank() {
    for (Puzzle* p : mathPuzzles)    delete p;
    for (Puzzle* p : wordPuzzles)    delete p;
    for (Puzzle* p : sciencePuzzles) delete p;
}

void PuzzleBank::loadAll() {
    auto mathBank = MathPuzzle::getBank();
    for (auto& puzz : mathBank)
        mathPuzzles.push_back(new MathPuzzle(puzz));
}