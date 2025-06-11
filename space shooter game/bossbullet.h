#ifndef BOSS_BULLET_H
#define BOSS_BULLET_H

#include "Bullet.h"

class BossBullet : public Bullet
{
public:
    BossBullet(Vector2 p);
    void Update(float dt) override;
    void Draw() const override;
    bool IsFromPlayer() const override;
};

#endif

