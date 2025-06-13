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
    Player AHSAN;

                                   // Bullets, enemies aur power-ups ko store karne ke liye dynamic arrays
    Dynamic_array<Bullet*> bullets;
    Dynamic_array<Enemy*> enemies;
    Dynamic_array<PowerUp*> powerUps;
                                     // Boss ka pointer banaya, start mein null hai
    Boss* boss = nullptr;
    bool gameOver = false;
    int kills = 0;     // Enemies kitne mar chuke hain
    int level = 3;     // Game ka current level
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
        // AHSAN update hoga agar zinda ho aur game over na ho
        if (!gameOver && AHSAN.IsAlive()) {
            AHSAN.Update(dt);
        }

        // Shooting ke liye timer reduce ho raha hai
        playerShootTimer -= dt;

        // Space dabane pe AHSAN shoot karega agar cooldown khatam ho gaya ho
        if (IsKeyDown(KEY_SPACE) && playerShootTimer <= 0 && !gameOver && AHSAN.IsAlive()) {
            playerShootTimer = 0.2f; // Shooting cooldown reset


    // Window close karo
       

    CloseWindow();

    return 0;
}
