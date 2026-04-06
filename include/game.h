#pragma once
#include "player.h"
#include "puzzlebank.h"
#include "department.h"
#include <string>
#include <fstream>
#include <cstdio>

// LEAD (Member 3): Implement game.cpp
class Game {
public:
    Game();
    ~Game();

    // Starts and runs the full game session
    void run();

private:
    Player* player;
    PuzzleBank bank;

    // Runs one full day for the given department
    // Returns number of correct answers (0-3)
    int runDay(int dayNumber, Department dept);

    // Calculates overall quota from daily scores
    float calculateQuota(int scores[], int days);

    // Department assigned per day (fixed order)
    static const Department DAY_ORDER[3];

    // --- Save / Load ---
    void saveState(int currentDay, int scores[]);
    bool loadState(std::string& outName, int& outDay, int scores[]);
    void deleteSave();
};
