#include "sciencepuzzle.h"
#include <iostream>

// Constructor: passes all arguments up to the parent Puzzle class
SciencePuzzle::SciencePuzzle(const std::string& question,
                             const std::string choicesArr[4],
                             int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// display(): prints the department label, then the question and choices A-D
void SciencePuzzle::display() const {
    std::cout << "\n[Biotech & Wellness]\n";
    std::cout << question << "\n\n";
    std::cout << " A. " << choices[0] << "\n";
    std::cout << " B. " << choices[1] << "\n";
    std::cout << " C. " << choices[2] << "\n";
    std::cout << " D. " << choices[3] << "\n\n";
}

// getBank(): returns a vector of 8 science questions
std::vector<SciencePuzzle> SciencePuzzle::getBank() {
    std::vector<SciencePuzzle> bank;

    // Q1 - Element symbol (correct: C = index 2)
    std::string c1[4] = {"Go", "Gd", "Au", "Ag"};
    bank.push_back(SciencePuzzle("What is the chemical symbol for gold?", c1, 2));

    // Q2 - Human chromosomes (correct: C = index 2)
    std::string c2[4] = {"23", "42", "46", "48"};
    bank.push_back(SciencePuzzle("How many chromosomes does a normal human cell have?", c2, 2));

    // Q3 - Water formula (correct: D = index 3)
    std::string c3[4] = {"HO", "H2O2", "OH", "H2O"};
    bank.push_back(SciencePuzzle("What is the chemical formula for water?", c3, 3));

    // Q4 - Red planet (correct: B = index 1)
    std::string c4[4] = {"Venus", "Mars", "Jupiter", "Saturn"};
    bank.push_back(SciencePuzzle("What planet is known as the Red Planet?", c4, 1));

    // Q5 - Photosynthesis (correct: A = index 0)
    std::string c5[4] = {"Oxygen", "Carbon dioxide", "Nitrogen", "Hydrogen"};
    bank.push_back(SciencePuzzle("What gas do plants release during photosynthesis?", c5, 0));

    // Q6 - Boiling point of water (correct: B = index 1)
    std::string c6[4] = {"90 degrees Celsius", "100 degrees Celsius", "110 degrees Celsius", "120 degrees Celsius"};
    bank.push_back(SciencePuzzle("At what temperature does water boil at sea level?", c6, 1));

    // Q7 - Largest organ (correct: D = index 3)
    std::string c7[4] = {"Heart", "Liver", "Brain", "Skin"};
    bank.push_back(SciencePuzzle("What is the largest organ in the human body?", c7, 3));

    // Q8 - Speed of light (correct: A = index 0)
    std::string c8[4] = {"299,792,458 m/s", "150,000,000 m/s", "3,000,000 m/s", "1,080,000,000 m/s"};
    bank.push_back(SciencePuzzle("What is the approximate speed of light in a vacuum?", c8, 0));

    return bank;
}

// checkAnswer(): returns true if the player's choice matches the correct index
bool SciencePuzzle::checkAnswer(int playerChoice) const {
    return playerChoice == correctIndex;
}