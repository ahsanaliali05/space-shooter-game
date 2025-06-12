#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(Vector2 p, float s)
    : Bullet(p, s) {
}

PlayerBullet::~PlayerBullet() {}

void PlayerBullet::Update(float dt) {
    pos.y -= speed * dt;
}

void PlayerBullet::Draw() const {
    DrawCircleV(pos, 5, YELLOW);
}

bool PlayerBullet::IsFromPlayer() const {
    return true;
}
