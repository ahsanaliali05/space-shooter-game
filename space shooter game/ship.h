// Ship.h
#ifndef SHIP_H
#define SHIP_H
#include "raylib.h"

class Ship {
public:
    Vector2 pos;
    Ship();
    virtual ~Ship();

    virtual void Update(float dt) = 0;
    virtual void Draw(Texture2D texture) const = 0;
};

#endif
