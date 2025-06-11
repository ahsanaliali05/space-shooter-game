// PowerUp.cpp
#include "PowerUp.h"

PowerUp::PowerUp(Vector2 p) : pos(p), speed(100) {}
PowerUp::~PowerUp() {}

void PowerUp::Update(float dt)
{
	pos.y += speed * dt;
}

HealthPowerUp::HealthPowerUp(Vector2 p) : PowerUp(p) {}
HealthPowerUp::~HealthPowerUp() {}
void HealthPowerUp::Apply(Player& pl)
{
	pl.AddLife();
}
void HealthPowerUp::Draw() const
{
	DrawCircleV(pos, 10, GREEN);
}

BulletPowerUp::BulletPowerUp(Vector2 p) : PowerUp(p) {}
BulletPowerUp::~BulletPowerUp() {}
void BulletPowerUp::Apply(Player& pl)
{
	pl.UpgradeBullet();
}
void BulletPowerUp::Draw() const
{
	DrawCircleV(pos, 10, PURPLE);
}
