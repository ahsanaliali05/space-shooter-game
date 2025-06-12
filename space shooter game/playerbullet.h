#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "raylib.h"
#include "Bullet.h"  

class PlayerBullet : public Bullet {
public:
  
    PlayerBullet(Vector2 position, float speed);


    ~PlayerBullet() override;

 
    void Update(float deltaTime) override;
    void Draw() const override;

    bool IsFromPlayer() const override;
};

#endif // PLAYER_BULLET_H