#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "Bullet.h"

class PlayerBullet : public Bullet {
public:
    PlayerBullet(Vector2 p);
    void Update(float dt) override;
    void Draw() const override;
    bool IsFromPlayer() const override;
};

#endif

