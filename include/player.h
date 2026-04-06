#pragma once
#include <string>
#include <iostream>

// MEMBER 2: Implement player.cpp
class Player {
public:
    Player(const std::string& name);

    // Getters
    std::string getName() const;
    int getScore() const;
    float getQuota() const;        // Returns 0.0 to 100.0

    // Setters / modifiers
    void addScore(int points);
    void setQuota(float quota);
    void resetDailyScore();

    // Overloaded << for clean terminal display of player stats
    friend std::ostream& operator<<(std::ostream& os, const Player& p);

private:
    std::string name;
    int score;
    float quota;   // Overall quota percentage (0-100)
};
