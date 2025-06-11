#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class Bullet {
public:
    Vector2 pos;
    float speed;

    Bullet(Vector2 p, float s);
    virtual ~Bullet();

    virtual void Update(float dt) = 0;
    virtual void Draw() const = 0;
    virtual bool IsFromPlayer() const = 0;

    Vector2 GetPosition() const {
        return pos;
    }
};

#endif

