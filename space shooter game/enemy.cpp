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
void Enemy::Draw(Texture2D texture) const {

    DrawRectangleV(pos, { 20, 20 }, BLUE);
    DrawTexture(texture, pos.x - 20.0f, pos.y - 20.0f, WHITE);
}
