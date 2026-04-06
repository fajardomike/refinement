#include "game.h"
#include "display.h"
#include "messages.h"
#include <iostream>
#include <string>

// Fixed department order: Day 1 = Math, Day 2 = Word, Day 3 = Science
const Department Game::DAY_ORDER[3] = {
    Department::MACRODATA,
    Department::LEXICAL,
    Department::BIOTECH
};

Game::Game() : player(nullptr) {}

Game::~Game() {
    delete player;
}

void Game::run() {
    // Boot screen — get player name
    std::string name = showBootScreen();
    player = new Player(name);

    bank.loadAll();

    int dailyScores[3] = {0, 0, 0};

    // Run 3 days
    for (int i = 0; i < 3; i++) {
        dailyScores[i] = runDay(i + 1, DAY_ORDER[i]);
    }

    // Calculate and display final result
    float finalQuota = calculateQuota(dailyScores, 3);
    player->setQuota(finalQuota);

    if (finalQuota >= 70.0f) {
        showWaffleParty(*player);
    } else {
        showTerminated(*player);
    }
}

int Game::runDay(int dayNumber, Department dept) {
    showDayStart(dayNumber, dept);

    std::vector<Puzzle*> puzzles = bank.getPuzzlesForDay(dept);
    int correct = 0;

    for (int i = 0; i < (int)puzzles.size(); i++) {
        // Display puzzle (polymorphic call)
        puzzles[i]->display();

        // Get player input
        char input;
        std::cout << "Your answer (A/B/C/D): ";
        std::cin >> input;
        int choice = toupper(input) - 'A';  // Convert A-D to 0-3

        Puzzle::totalAttempted++;

        if (puzzles[i]->checkAnswer(choice)) {
            correct++;
            std::cout << "\n" << getRandomMessage(CORRECT_MESSAGES) << "\n\n";
        } else {
            std::cout << "\n" << getRandomMessage(WRONG_MESSAGES) << "\n\n";
        }

        // Show quota progress for this day so far
        float dayQuota = (float)correct / puzzles.size() * 100.0f;
        showQuotaBar(dayQuota);
    }

    float dayQuota = (float)correct / puzzles.size() * 100.0f;
    showDaySummary(dayNumber, correct, (int)puzzles.size(),
                   getRandomMessage(DAY_END_MESSAGES));

    return correct;
}

float Game::calculateQuota(int scores[], int days) {
    float total = 0;
    for (int i = 0; i < days; i++) {
        total += (float)scores[i] / 3.0f * 100.0f;
    }
    return total / days;
}
