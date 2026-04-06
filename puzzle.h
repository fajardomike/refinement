#pragma once
#include <string>

// Abstract base class for all puzzle types.
// MathPuzzle, WordPuzzle, and SciencePuzzle must inherit from this.
class Puzzle {
public:
    // Constructor: question text, 4 choices, correct answer index (0-3)
    Puzzle(const std::string& question,
           const std::string choicesArr[4],
           int correctIndex);

    virtual ~Puzzle();

    // Display the question and choices to the terminal
    virtual void display() const = 0;

    // Check if the player's answer (0-3) is correct
    virtual bool checkAnswer(int playerChoice) const = 0;

    // Getters
    std::string getQuestion() const;
    std::string getChoice(int i) const;
    int getCorrectIndex() const;

    // Static counter — tracks total puzzles attempted across all instances
    static int totalAttempted;

protected:
    std::string question;
    std::string choices[4];
    int correctIndex;
};
