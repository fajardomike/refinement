#include "player.h"
#include <iostream>

using namespace std;

Player::Player(const string& name)
    : name(name), score(0), quota(0.0f) {}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

float Player::getQuota() const {
    return quota;
}

void Player::addScore(int points) {
    score += points;
}

void Player::setQuota(float q) {
    quota = q;
}

void Player::resetDailyScore() {
    score = 0;
}

ostream& operator<<(ostream& os, const Player& p) {
    os << "Employee : " << p.name << "\n";
    os << "Score    : " << p.score << "\n";
    os << "Quota    : " << p.quota << "%\n";
    return os;
}