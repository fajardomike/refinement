#include "wordpuzzle.h"
#include <iostream>

// Constructor: delegates to parent Puzzle constructor via initializer list
WordPuzzle::WordPuzzle(const std::string& question,
                       const std::string choicesArr[4],
                       int correctIndex)
    : Puzzle(question, choicesArr, correctIndex) {}

// Displays [Lexical Processing] department label, then question and choices A-D
void WordPuzzle::display() const {
    std::cout << "\n[Lexical Processing]\n";
    std::cout << question << "\n";
    std::cout << "A. " << choices[0] << "\n";
    std::cout << "B. " << choices[1] << "\n";
    std::cout << "C. " << choices[2] << "\n";
    std::cout << "D. " << choices[3] << "\n";
}

// Returns true if playerChoice matches the stored correct index
bool WordPuzzle::checkAnswer(int playerChoice) const {
    return playerChoice == correctIndex;
}

// Returns a bank of 8 hardcoded word puzzles:
// mix of vocabulary definitions, anagrams, and word analogies
std::vector<WordPuzzle> WordPuzzle::getBank() {
    std::vector<WordPuzzle> bank;

    // --- Vocabulary Definitions ---

    // Q1: correct index 1 (B. Short-lived)
    {
        const std::string choices[4] = {"Permanent", "Short-lived", "Colorful", "Loud"};
        bank.emplace_back("What does ephemeral mean?", choices, 1);
    }

    // Q2: correct index 2 (C. Contract)
    {
        const std::string choices[4] = {"Grow", "Stretch", "Contract", "Inflate"};
        bank.emplace_back("Which word means the opposite of expand?", choices, 2);
    }

    // Q3: correct index 0 (A. Verbose)
    {
        const std::string choices[4] = {"Verbose", "Concise", "Mute", "Hasty"};
        bank.emplace_back("Which word means using more words than necessary?", choices, 0);
    }

    // Q4: correct index 3 (D. Benevolent)
    {
        const std::string choices[4] = {"Hostile", "Greedy", "Timid", "Benevolent"};
        bank.emplace_back("Which word best describes a kind and generous person?", choices, 3);
    }

    // --- Anagrams ---

    // Q5: correct index 0 (A. BRAIN)
    {
        const std::string choices[4] = {"BRAIN", "TRAIN", "GRAIN", "DRAIN"};
        bank.emplace_back("Unscramble: RNBIA", choices, 0);
    }

    // Q6: correct index 2 (C. STONE)
    {
        const std::string choices[4] = {"TONES", "ONSET", "STONE", "NOTES"};
        bank.emplace_back("Unscramble: TSEON", choices, 2);
    }

    // --- Word Analogies ---

    // Q7: correct index 3 (D. Night)
    {
        const std::string choices[4] = {"Sun", "Warm", "Morning", "Night"};
        bank.emplace_back("Hot is to Cold as Day is to ___", choices, 3);
    }

    // Q8: correct index 1 (B. Author)
    {
        const std::string choices[4] = {"Canvas", "Author", "Instrument", "Studio"};
        bank.emplace_back("Painter is to Painting as Writer is to ___", choices, 1);
    }

    return bank;
}
