// Player.cpp
#include "Player.h"
#include "raylib.h"

Player::Player() : lives(100), bulletLevel(1) {
    pos = { 390, 550 };
}
Player::~Player() {}

void Player::Update(float dt) {
    if (IsKeyDown(KEY_LEFT))
        pos.x -= 300 * dt;
    if (IsKeyDown(KEY_RIGHT))
        pos.x += 300 * dt;
    if (pos.x < 0)
        pos.x = 0;
    if (pos.x > 780)
        pos.x = 780;
}

void Player::Draw() const {
    DrawRectangleV(pos, { 20, 20 }, BLUE);
}

void Player::AddLife() { lives++; }
void Player::UpgradeBullet() { if (bulletLevel < 3) bulletLevel++; }