#include "display.h"

#include <ctime>     // time
#include <cstdlib>   // srand
#include <iostream>
#include <limits>

static std::string deptName(Department d) {
    if (d == Department::MACRODATA) return "Macrodata Refinement";
    if (d == Department::LEXICAL) return "Lexical Processing";
    return "Biotech & Wellness";
}

void clearScreen() {
    // Keep it portable: just push previous content off-screen.
    for (int i = 0; i < 40; i++) std::cout << "\n";
}

std::string showBootScreen() {
    clearScreen();

    // Seed randomness once early in the session (used by getRandomMessage()).
    std::srand((unsigned)std::time(nullptr));

    std::cout <<
        "============================================================\n"
        "              L U M O N   I N D U S T R I E S\n"
        "============================================================\n"
        "Terminal Authorization: GRANTED\n"
        "Purpose: REFINEMENT\n"
        "\n"
        "Please enter your name for onboarding.\n"
        "> ";

    std::string name;
    std::getline(std::cin >> std::ws, name);
    if (name.empty()) name = "Employee";

    std::cout << "\nWelcome, " << name << ".\n";
    std::cout << "Your innie is now online.\n";
    std::cout << "Press ENTER to begin.\n";

    std::string dummy;
    std::getline(std::cin, dummy);
    clearScreen();
    return name;
}

void showDayStart(int day, Department dept) {
    clearScreen();

    std::cout <<
        "------------------------------\n"
        "DAY " << day << " ASSIGNMENT\n"
        "------------------------------\n"
        "Department: " << deptName(dept) << "\n"
        "\n"
        "You will complete 3 refinements today.\n"
        "Answer carefully. Metrics are forever.\n"
        "\n";
}

void showQuotaBar(float percent) {
    if (percent < 0.0f) percent = 0.0f;
    if (percent > 100.0f) percent = 100.0f;

    int filled = (int)(percent / 10.0f);
    std::cout << "Quota: [";
    for (int i = 0; i < 10; i++) std::cout << (i < filled ? "#" : "-");
    std::cout << "] " << (int)percent << "%\n\n";
}

void showDaySummary(int day, int correct, int total, const std::string& message) {
    std::cout <<
        "------------------------------\n"
        "DAY " << day << " SUMMARY\n"
        "------------------------------\n"
        "Refinements completed: " << total << "\n"
        "Correct refinements:   " << correct << "\n"
        "Incorrect refinements: " << (total - correct) << "\n"
        "\n"
        "Message: " << message << "\n"
        "\n"
        "Press ENTER to proceed.\n";

    std::string dummy;
    std::getline(std::cin >> std::ws, dummy);
    clearScreen();
}

void showWaffleParty(const Player& player) {
    clearScreen();

    std::cout <<
        "============================================================\n"
        "                  WAFFLE PARTY AUTHORIZED\n"
        "============================================================\n"
        "Your quota has been met.\n"
        "A measured celebration will now occur.\n"
        "\n";

    std::cout << player << "\n";

    std::cout <<
        "Waffles: DISPENSED\n"
        "Joy:     REGULATED\n"
        "Freedom: NOT INCLUDED\n"
        "\n"
        "Press ENTER to exit.\n";

    std::string dummy;
    std::getline(std::cin >> std::ws, dummy);
}

void showTerminated(const Player& player) {
    clearScreen();

    std::cout <<
        "============================================================\n"
        "                   TERMINATION NOTICE\n"
        "============================================================\n"
        "Your quota was not met.\n"
        "Access privileges have been revoked.\n"
        "\n";

    std::cout << player << "\n";

    std::cout <<
        "Please return all thoughts to your supervisor.\n"
        "Press ENTER to exit.\n";

    std::string dummy;
    std::getline(std::cin >> std::ws, dummy);
}

