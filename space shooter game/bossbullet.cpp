#include "BossBullet.h"

BossBullet::BossBullet(Vector2 p) : Bullet(p, 300) {}

void BossBullet::Update(float dt) {
    pos.y += speed * dt;
}

void BossBullet::Draw() const {
    DrawCircleV(pos, 5, ORANGE);
}

bool BossBullet::IsFromPlayer() const {
    return false;
}
