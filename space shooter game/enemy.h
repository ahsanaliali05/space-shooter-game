// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include "Ship.h"

class Enemy : public Ship {
public:
    float speed;
    Enemy(float x, float s);
    virtual ~Enemy();
    void Update(float dt) override;
    void Draw(Texture2D texture) const override;
};

#endif

