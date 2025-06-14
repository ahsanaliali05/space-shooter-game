// Boss.cpp
#include "Boss.h"
#include "raylib.h"

Boss::Boss() : Enemy(380, 0), hp(200), moveRight(true), shootTimer(0.0f) {
    pos = { 380, 50 };
}
Boss::~Boss() {}

void Boss::Update(float dt) {

    if (moveRight)
        pos.x += 150 * dt;
    else
        pos.x -= 150 * dt;

    if (pos.x < 0)
    {
        pos.x = 0; moveRight = true;
    }
    if (pos.x > 760)
    {
        pos.x = 760; moveRight = false;
    }
    shootTimer -= dt;
}

bool Boss::CanShoot() const
{
    return shootTimer <= 0;
}
void Boss::ResetShootTimer()
{
    shootTimer = 1.2f;
}

void Boss::Draw(Texture2D texture) const {
    DrawRectangleV(pos, { 40, 40 }, DARKPURPLE);
    DrawTexture(texture, pos.x - 40.0f, pos.y - 40.0f, WHITE);
    DrawText(TextFormat("Boss HP: %d", hp), 10, 60, 20, MAROON);
}