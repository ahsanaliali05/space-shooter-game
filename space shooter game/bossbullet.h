#ifndef BOSS_BULLET_H
#define BOSS_BULLET_H

#include "raylib.h"
#include "Bullet.h"  

class BossBullet : public Bullet {
public:
    
    BossBullet(Vector2 p, float s);

    ~BossBullet() override;

    void Update(float dt) override;

    void Draw() const override;

    bool IsFromPlayer() const override;
};

#endif // BOSS_BULLET_H