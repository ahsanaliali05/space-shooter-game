#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Ship.h"
#include <chrono>

using namespace std::chrono;

class Player : public Ship {
public:
    float maxHealth;
    float currentHealth;
    int bulletLevel;
    float speed;
    bool isSpeedBoosted;
    steady_clock::time_point speedBoostEndTime;

    Player();
    ~Player();

    void Update(float dt) override;
    void Draw() const override;
    void DrawHealthBar() const;

    void TakeDamage();
    void Heal(float amount);
    void AddMaxHealth(float amount);
    void UpgradeBullet();
    void ActivateSpeedBoost(int durationSeconds = 30);
    bool IsAlive() const;
};

#endif // PLAYER_H
