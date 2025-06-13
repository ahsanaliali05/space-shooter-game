#include<raylib.h>

class Bullet {
public:
    Vector2 pos;
    float speed;
    bool active;

    Bullet() : pos({ 0, 0 }), speed(0), active(true) {}
    Bullet(Vector2 p, float s) : pos(p), speed(s), active(true) {}
    virtual ~Bullet() {}

    virtual void Update(float dt) = 0;
    virtual void Draw() const = 0;
    virtual bool IsFromPlayer() const = 0;
};