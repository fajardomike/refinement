#pragma once
#include "player.h"
#include "department.h"
#include <string>

// MEMBER 7: Implement display.cpp
// All terminal output lives here — keeps display logic out of game logic.

// Clears the terminal screen
void clearScreen();

// Prints the Lumon boot screen and prompts for player name, returns it
std::string showBootScreen();

// Prints the department assignment screen for the start of a day
void showDayStart(int day, Department dept);

// Prints the quota bar after each answer
void showQuotaBar(float percent);

// Prints the daily summary at the end of each day
void showDaySummary(int day, int correct, int total, const std::string& message);

// Prints the final waffle party screen
void showWaffleParty(const Player& player);

// Prints the termination notice screen
void showTerminated(const Player& player);
