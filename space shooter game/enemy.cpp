// Enemy.cpp
#include "Enemy.h"
#include "raylib.h"

Enemy::Enemy(float x, float s) : speed(s) {
    pos = { x, 0 };
}
Enemy::~Enemy() {}

void Enemy::Update(float dt)
{
    pos.y += speed * dt;
}
void Enemy::Draw() const { DrawRectangleV(pos, { 20, 20 }, RED); }
