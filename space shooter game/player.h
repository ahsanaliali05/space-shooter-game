// Player.h
#ifndef PLAYER_H
#define PLAYER_H
#include "Ship.h"

class Player : public Ship {
public:
    int lives;
    int bulletLevel;

    Player();
    ~Player();

    void Update(float dt) override;
    void Draw() const override;

    void AddLife();
    void UpgradeBullet();
};

#endif

