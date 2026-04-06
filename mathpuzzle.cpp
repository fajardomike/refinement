#include "mathpuzzle.h"
#include <iostream>
#include <vector>
#include <string>

// 1. Constructor: Calls parent Puzzle constructor via initializer list
MathPuzzle::MathPuzzle(const std::string& question, const std::string choicesArr[4], int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// 2. display(): Prints department label then question and choices A-D
void MathPuzzle::display() const {
    std::cout << "\n[Macrodata Refinement]\n";
    std::cout << question << "\n\n";
    std::cout << "  A. " << choices[0] << "\n";
    std::cout << "  B. " << choices[1] << "\n";
    std::cout << "  C. " << choices[2] << "\n";
    std::cout << "  D. " << choices[3] << "\n\n";
}

// 3. checkAnswer(): Returns true if playerChoice equals correctIndex
bool MathPuzzle::checkAnswer(int playerChoice) const {
    return playerChoice == correctIndex;
}

// 4. getBank(): Returns a vector with 8 math questions
std::vector<MathPuzzle> MathPuzzle::getBank() {
    std::vector<MathPuzzle> bank;

    // Question 1 (From Project Spec)
    std::string c1[4] = {"49", "56", "98", "77"};
    bank.push_back(MathPuzzle("What is 7 x 14?", c1, 2));  // C. 98

    // Question 2 (Arithmetic)
    std::string c2[4] = {"11", "16", "10", "13"};
    bank.push_back(MathPuzzle("Evaluate 5 + 3 * 2:", c2, 0)); // A. 11

    // Question 3 (Basic Algebra)
    std::string c3[4] = {"3", "5", "10", "15"};
    bank.push_back(MathPuzzle("Solve for x: 3x - 5 = 10", c3, 1)); // B. 5

    // Question 4 (Sequence)
    std::string c4[4] = {"24", "30", "32", "64"};
    bank.push_back(MathPuzzle("What is the next number in the sequence: 2, 4, 8, 16...", c4, 2)); // C. 32

    // Question 5 (Arithmetic)
    std::string c5[4] = {"10", "20", "25", "50"};
    bank.push_back(MathPuzzle("Solve: 100 / (4 + 6)", c5, 0)); // A. 10

    // Question 6 (Percentages/Algebra)
    std::string c6[4] = {"20", "30", "40", "50"};
    bank.push_back(MathPuzzle("What is 15% of 200?", c6, 1)); // B. 30

    // Question 7 (Roots)
    std::string c7[4] = {"10", "11", "12", "14"};
    bank.push_back(MathPuzzle("What is the square root of 144?", c7, 2)); // C. 12

    // Question 8 (Exponents)
    std::string c8[4] = {"10", "16", "25", "32"};
    bank.push_back(MathPuzzle("What is 2^5?", c8, 3)); // D. 32

    return bank;
}
