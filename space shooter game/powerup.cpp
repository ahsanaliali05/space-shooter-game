#include "PowerUp.h"

// --- PowerUp Base Class ---
PowerUp::PowerUp(Vector2 p) : pos(p), speed(100.0f) {}

PowerUp::~PowerUp() {}

void PowerUp::Update(float dt) {
    pos.y += speed * dt;
}

// --- HealthPowerUp ---
HealthPowerUp::HealthPowerUp(Vector2 p) : PowerUp(p) {}

HealthPowerUp::~HealthPowerUp() {}

void HealthPowerUp::Apply(Player& pl) {
    pl.Heal(pl.maxHealth * 0.33f);
}

void HealthPowerUp::Draw() const {
    DrawCircleV(pos, 10, GREEN);
}

// --- BulletPowerUp ---
BulletPowerUp::BulletPowerUp(Vector2 p) : PowerUp(p) {}

BulletPowerUp::~BulletPowerUp() {}

void BulletPowerUp::Apply(Player& pl) {
    pl.UpgradeBullet();
}

void BulletPowerUp::Draw() const {
    DrawCircleV(pos, 10, PURPLE);
}

// --- SpeedPowerUp ---
SpeedPowerUp::SpeedPowerUp(Vector2 p) : PowerUp(p) {}

SpeedPowerUp::~SpeedPowerUp() {}

void SpeedPowerUp::Apply(Player& pl) {
    pl.ActivateSpeedBoost();
}

void SpeedPowerUp::Draw() const {
    DrawCircleV(pos, 10, SKYBLUE);
}
