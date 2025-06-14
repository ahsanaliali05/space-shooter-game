#include "Player.h"
#include "raylib.h"
using namespace std::chrono;

Player::Player() : maxHealth(100.0f), currentHealth(100.0f), bulletLevel(1), speed(300.0f), isSpeedBoosted(false) {
    pos = { 390, 550 };
}

Player::~Player() {}

void Player::Update(float dt) {
    float currentSpeed;
    if (isSpeedBoosted) {
        currentSpeed = speed * 2;
    }
    else {
        currentSpeed = speed;
    }

    if (isSpeedBoosted) {
        if (steady_clock::now() >= speedBoostEndTime) {
            isSpeedBoosted = false;
        }
    }

    if (IsKeyDown(KEY_LEFT)) {
        pos.x -= currentSpeed * dt;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        pos.x += currentSpeed * dt;
    }
    if (IsKeyDown(KEY_UP)) {
        pos.y -= currentSpeed * dt;
    }
    if (IsKeyDown(KEY_DOWN)) {
        pos.y += currentSpeed * dt;
    }

    if (pos.y > 580) {
        pos.y = 580;
    }
    else if (pos.y < 0) {
        pos.y = 0;
    }

    if (pos.x < 0) {
        pos.x = 780;
    }
    else if (pos.x > 780) {
        pos.x = 0;
    }
}

void Player::Draw(Texture2D texture ) const {
    DrawRectangleV(pos, { 25, 25 }, BLUE);
    DrawTexture(texture, pos.x-25.0f, pos.y-25.0f, WHITE);
 }




void Player::DrawHealthBar() const {
    float healthBarWidth = 200;
    float healthPercentage = currentHealth / maxHealth;

    Color healthColor;
    if (healthPercentage > 0.66f) {
        healthColor = GREEN;
    }
    else {
        if (healthPercentage > 0.33f) {
            healthColor = YELLOW;
        }
        else {
            healthColor = RED;
        }
    }

    DrawRectangle(300, 10, healthBarWidth, 20, GRAY);
    DrawRectangle(300, 10, healthBarWidth * healthPercentage, 20, healthColor);
    DrawRectangleLines(300, 10, healthBarWidth, 20, WHITE);
}

void Player::TakeDamage() {
    float damage = maxHealth * 0.33f;
    currentHealth -= damage;
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

void Player::Heal(float amount) {
    currentHealth += amount;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}

void Player::AddMaxHealth(float amount) {
    maxHealth += amount;
    currentHealth += amount;
}

void Player::UpgradeBullet() {
    if (bulletLevel < 3) {
        bulletLevel++;
    }
}

void Player::ActivateSpeedBoost(int durationSeconds) {
    isSpeedBoosted = true;
    speedBoostEndTime = steady_clock::now() + seconds(durationSeconds);
}

bool Player::IsAlive() const {
    if (currentHealth > 0) {
        return true;
    }
    else {
        return false;
    }
}
