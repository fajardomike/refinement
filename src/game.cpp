#include "game.h"
#include "display.h"
#include "messages.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

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

// ──────────────────────────────────────────────
// Save / Load helpers
// ──────────────────────────────────────────────

void Game::saveState(int currentDay, int scores[]) {
    std::ofstream out("saves/save.txt");
    if (!out.is_open()) return;
    out << player->getName() << "\n";
    out << currentDay << "\n";
    for (int i = 0; i < 3; i++) out << scores[i] << "\n";
    out.close();
}

bool Game::loadState(std::string& outName, int& outDay, int scores[]) {
    std::ifstream in("saves/save.txt");
    if (!in.is_open()) return false;

    if (!std::getline(in, outName) || outName.empty()) return false;
    if (!(in >> outDay)) return false;
    for (int i = 0; i < 3; i++) {
        if (!(in >> scores[i])) return false;
    }
    return true;
}

void Game::deleteSave() {
    std::remove("saves/save.txt");
}

// ──────────────────────────────────────────────
// Main game loop
// ──────────────────────────────────────────────

void Game::run() {
    // Boot screen — get player name
    std::string name = showBootScreen();

    bank.loadAll();

    int dailyScores[3] = {-1, -1, -1};
    int startDay = 0; // 0-indexed

    // Check for existing save
    std::string savedName;
    int savedDay;
    int savedScores[3];
    if (loadState(savedName, savedDay, savedScores)) {
        std::cout << "A previous session was found for " << savedName << ". Resume? (Y/N): ";
        char choice;
        std::cin >> choice;
        if (toupper(choice) == 'Y') {
            name = savedName;
            startDay = savedDay - 1; // savedDay is 1-based, convert to 0-based
            for (int i = 0; i < 3; i++) dailyScores[i] = savedScores[i];
        } else {
            deleteSave();
        }
    }

    player = new Player(name);

    // Run days (skip already-completed ones)
    for (int i = startDay; i < 3; i++) {
        if (dailyScores[i] >= 0) continue; // already played

        dailyScores[i] = runDay(i + 1, DAY_ORDER[i]);

        // Save after each day
        if (i < 2) { // don't save after the final day
            saveState(i + 2, dailyScores); // next day is i+2 (1-based)
        }
    }

    // Calculate and display final result
    float finalQuota = calculateQuota(dailyScores, 3);
    player->setQuota(finalQuota);

    if (finalQuota >= 70.0f) {
        showWaffleParty(*player);
    } else {
        showTerminated(*player);
    }

    deleteSave();
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
