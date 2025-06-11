
#include "Collision.h"
#include "raylib.h"

bool CheckCollision(const PowerUp* pu, const Player& pl) {
    return CheckCollisionCircles(pu->pos, 10, pl.pos, 10);
}
s