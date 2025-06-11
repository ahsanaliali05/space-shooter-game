// Boss.h
#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"

class Boss : public Enemy {
public:
    int hp;
    bool moveRight;
    float shootTimer;

    Boss();
    ~Boss();

    void Update(float dt) override;
    void Draw() const override;
    bool CanShoot() const;
    void ResetShootTimer();
};

#endif

