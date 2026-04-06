#include "puzzlebank.h"
#include "mathpuzzle.h"
#include "wordpuzzle.h"
#include "sciencepuzzle.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

PuzzleBank::PuzzleBank() {}

PuzzleBank::~PuzzleBank() {
    for (Puzzle* p : mathPuzzles)    delete p;
    for (Puzzle* p : wordPuzzles)    delete p;
    for (Puzzle* p : sciencePuzzles) delete p;
}

std::vector<Puzzle*> PuzzleBank::loadFromFile(const std::string& filepath, Department dept) {
    std::vector<Puzzle*> puzzles;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filepath << "\n";
        std::exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string parts[6];
        for (int i = 0; i < 6; i++) {
            if (!std::getline(ss, parts[i], '|')) {
                std::cerr << "Error: Malformed line in " << filepath << ": " << line << "\n";
                std::exit(1);
            }
        }

        std::string questionText = parts[0];
        std::string choicesArr[4] = { parts[1], parts[2], parts[3], parts[4] };
        int correctIdx = std::stoi(parts[5]);

        Puzzle* p = nullptr;
        if (dept == Department::MACRODATA) {
            p = new MathPuzzle(questionText, choicesArr, correctIdx);
        } else if (dept == Department::LEXICAL) {
            p = new WordPuzzle(questionText, choicesArr, correctIdx);
        } else {
            p = new SciencePuzzle(questionText, choicesArr, correctIdx);
        }
        puzzles.push_back(p);
    }

    return puzzles;
}

void PuzzleBank::loadAll() {
    mathPuzzles    = loadFromFile("data/math_questions.txt",    Department::MACRODATA);
    wordPuzzles    = loadFromFile("data/word_questions.txt",    Department::LEXICAL);
    sciencePuzzles = loadFromFile("data/science_questions.txt", Department::BIOTECH);
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