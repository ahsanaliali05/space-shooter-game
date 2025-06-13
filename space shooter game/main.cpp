#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include "BossBullet.h"
#include "PowerUp.h"
#include "collision.h"
#include "Dynamic_array.h"
#include <ctime>

int main() {
                                          // Game ki window create ho rahi hai (800x600 pixels)
    InitWindow(800, 600, "Shooter with Health Bar System");
                                          // FPS set kar rahe hain taake game smooth chale
    SetTargetFPS(60);
                                           // Player ka object bana rahe hain  AHSAN don
    Player player;

                                   // Bullets, enemies aur power-ups ko store karne ke liye dynamic arrays
    Dynamic_array<Bullet*> bullets;
    Dynamic_array<Enemy*> enemies;
    Dynamic_array<PowerUp*> powerUps;
                                     // Boss ka pointer banaya, start mein null hai
    Boss* boss = nullptr;
    bool gameOver = false;
    int kills = 0;     // Enemies kitne mar chuke hain
    int level = 1;     // Game ka current level
    float playerShootTimer = 0; // Player kab shoot kar sakta hai (cooldown)


    // Main game loop jab tak window close nahi hoti
    while (!WindowShouldClose()) {
        // Frame ka delta time mil raha hai (movement smooth banane ke liye)
        float dt = GetFrameTime();

        // Drawing start kar rahe hain
        BeginDrawing();

        // Har level ka background alag hoga
        if (level == 1)
            ClearBackground(BLACK);
        else if (level == 2)
            ClearBackground(DARKBLUE);
        else
            ClearBackground(DARKGRAY);

       

  /*  CloseWindow();*/

    return 0;
}
