// PowerUp.h
#ifndef POWERUP_H
#define POWERUP_H
#include "raylib.h"
#include "Player.h"

class PowerUp {
public:
    Vector2 pos;
    float speed;

    PowerUp(Vector2 p);
    virtual ~PowerUp();

    void Update(float dt);
    virtual void Apply(Player& p) = 0;
    virtual void Draw() const = 0;
};

class HealthPowerUp : public PowerUp {
public:
    HealthPowerUp(Vector2 p);
    ~HealthPowerUp();

    void Apply(Player& pl) override;
    void Draw() const override;
};

class BulletPowerUp : public PowerUp {
public:
    BulletPowerUp(Vector2 p);
    ~BulletPowerUp();

    void Apply(Player& pl) override;
    void Draw() const override;
};

#endif
