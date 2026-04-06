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

    auto wordBank = WordPuzzle::getBank();
    for (auto& puzz : wordBank)
        wordPuzzles.push_back(new WordPuzzle(puzz));

    auto sciBank = SciencePuzzle::getBank();
    for (auto& puzz : sciBank)
        sciencePuzzles.push_back(new SciencePuzzle(puzz));
}

std::vector<Puzzle*> PuzzleBank::getPuzzlesForDay(Department dept) {
    std::vector<Puzzle*>* vec = nullptr;

    if      (dept == Department::MACRODATA) vec = &mathPuzzles;
    else if (dept == Department::LEXICAL)   vec = &wordPuzzles;
    else                                    vec = &sciencePuzzles;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec->begin(), vec->end(), g);

    return std::vector<Puzzle*>(vec->begin(), vec->begin() + 3);
}