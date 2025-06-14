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


    Texture2D playerTexture = LoadTexture("spaceship3.png");

        
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
        // AHSAN update hoga agar zinda ho aur game over na ho
        if (!gameOver && AHSAN.IsAlive()) {
            AHSAN.Update(dt);
        }

        // Shooting ke liye timer reduce ho raha hai
        playerShootTimer -= dt;

        // Space dabane pe AHSAN shoot karega agar cooldown khatam ho gaya ho
        if (IsKeyDown(KEY_SPACE) && playerShootTimer <= 0 && !gameOver && AHSAN.IsAlive()) {
            playerShootTimer = 0.2f; // Shooting cooldown reset
            // Bullet Level 1: Sirf center se fire hoga
            if (AHSAN.bulletLevel == 1) {
                bullets.push_back(new PlayerBullet(Vector2{ AHSAN.pos.x + 10.0f, AHSAN.pos.y }, 400.0f));
            }
            // Bullet Level 2: Dono ends se fire hoga
            else if (AHSAN.bulletLevel == 2) {
                bullets.push_back(new PlayerBullet(Vector2{ AHSAN.pos.x, AHSAN.pos.y }, 400.0f));
                bullets.push_back(new PlayerBullet(Vector2{ AHSAN.pos.x + 20.0f, AHSAN.pos.y }, 400.0f));
            }
            // Bullet Level 3+: Left, center, aur right tino se fire hoga
            else if (AHSAN.bulletLevel >= 3) {
                bullets.push_back(new PlayerBullet(Vector2{ AHSAN.pos.x, AHSAN.pos.y }, 400.0f));
                bullets.push_back(new PlayerBullet(Vector2{ AHSAN.pos.x + 10.0f, AHSAN.pos.y }, 400.0f));
                bullets.push_back(new PlayerBullet(Vector2{ AHSAN.pos.x + 20.0f, AHSAN.pos.y }, 400.0f));
            }
        }


        // Enemies aur power-ups spawn honge based on level aur random chance
        if (!gameOver && AHSAN.IsAlive()) {
            int spawnChance = GetRandomValue(0, 40);

            if (level == 1 && spawnChance == 0) {
                enemies.push_back(new Enemy(GetRandomValue(0, 780), 100));
            }
            else if (level == 2 && GetRandomValue(0, 30) == 0) {
                enemies.push_back(new Enemy(GetRandomValue(0, 780), 200));
            }

            // Power-ups randomly spawn honge
            if (GetRandomValue(0, 60) == 0) {
                int powerUpType = GetRandomValue(1, 3);
                int xPos = GetRandomValue(20, 780);
                Vector2 powerUpPos = { xPos, 0.0f };

                if (powerUpType == 1)
                    powerUps.push_back(new HealthPowerUp(powerUpPos));
                else if (powerUpType == 2)
                    powerUps.push_back(new BulletPowerUp(powerUpPos));
                else
                    powerUps.push_back(new SpeedPowerUp(powerUpPos));
            }
        }

        // Level 3 pe boss spawn hoga
        if (level == 3 && boss == nullptr && AHSAN.IsAlive()) {
            boss = new Boss();
        }

        // Boss shooting karega agar ready ho
        if (boss && boss->CanShoot() && AHSAN.IsAlive()) {
            boss->ResetShootTimer();
            bullets.push_back(new BossBullet(Vector2{ boss->pos.x + 20.0f, boss->pos.y }, 300.0f));
        }

        // Saare bullets, enemies, powerUps, boss update honge
        for (int i = 0; i < bullets.size(); i++)
            bullets[i]->Update(dt);
        for (int i = 0; i < enemies.size(); i++)
            enemies[i]->Update(dt);
        for (int i = 0; i < powerUps.size(); i++)
            powerUps[i]->Update(dt);
        if (boss)
            boss->Update(dt);

        // Bullet collisions aur deletion handle karna
        for (int i = bullets.size() - 1; i >= 0; i--) {
            if (!bullets[i]->active) {
                delete bullets[i];
                bullets.delete_at(i);
                continue;
            }

            bool removed = false;

            // Agar bullet AHSAN ne fire ki hai
            if (bullets[i]->IsFromPlayer()) {
                // Check enemy collision
                for (int j = enemies.size() - 1; j >= 0; j--) {
                    if (CheckCollisionCircles(bullets[i]->pos, 5.0f, enemies[j]->pos, 12.0f)) {
                        delete enemies[j];
                        enemies.delete_at(j);
                        bullets[i]->active = false;
                        kills++;
                        removed = true;
                        break;
                    }
                }

                // Boss collision
                if (!removed && boss && CheckCollisionCircles(bullets[i]->pos, 5.0f, boss->pos, 20.0f)) {
                    boss->hp -= 10;
                    bullets[i]->active = false;

                    if (boss->hp <= 0) {
                        delete boss;
                        boss = nullptr;
                        gameOver = true;
                    }
                }
            }
            // boss bullet hits AHSAN
            else if (CheckCollisionCircles(bullets[i]->pos, 5.0f, AHSAN.pos, 10.0f) && AHSAN.IsAlive()) {
                AHSAN.TakeDamage();
                bullets[i]->active = false;
            }
        }

        // Enemy hits AHSAN
        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (CheckCollisionCircles(enemies[i]->pos, 10.0f, AHSAN.pos, 15.0f) && AHSAN.IsAlive()) {
                AHSAN.TakeDamage();
                delete enemies[i];
                enemies.delete_at(i);
            }
        }

        // Power-up pick up hone par effect apply hoga
        for (int i = powerUps.size() - 1; i >= 0; i--) {
            if (CheckCollision(powerUps[i], AHSAN) && AHSAN.IsAlive()) {
                powerUps[i]->Apply(AHSAN);
                delete powerUps[i];
                powerUps.delete_at(i);
            }
        }

        // Level progression: kills ke basis par level change hoga
        if (level == 1 && kills >= 10 && AHSAN.IsAlive()) {
            for (int i = 0; i < enemies.size(); i++)
            {
                delete enemies[i];
            }
            enemies.clear();
            level = 2;
        }
        else if (level == 2 && kills >= 25 && AHSAN.IsAlive()) {
            for (int i = 0; i < enemies.size(); i++)
            {
                delete enemies[i];
            }
            enemies.clear();
            level = 3;
        }

        // AHSAN mar gaya to game over
        if (!AHSAN.IsAlive() && !gameOver) {
            gameOver = true;
        }

        // ---------------- Drawing Section ----------------

        if (AHSAN.IsAlive())
            AHSAN.Draw(playerTexture);

        for (int i = 0; i < bullets.size(); i++) {
            if (bullets[i]->active)
                bullets[i]->Draw();
        }

        for (int i = 0; i < enemies.size(); i++)
            enemies[i]->Draw(playerTexture);

        for (int i = 0; i < powerUps.size(); i++)
            powerUps[i]->Draw();

        if (boss)
            boss->Draw(playerTexture);

        // Health bar draw kar rahe hain
        AHSAN.DrawHealthBar();

        // Info texts
        DrawText(TextFormat("Bullet Lv: %d", AHSAN.bulletLevel), 550, 10, 20, YELLOW);
        DrawText(TextFormat("Kills: %d", kills), 10, 10, 20, GREEN);
        DrawText(TextFormat("Level: %d", level), 700, 10, 20, SKYBLUE);

        // Speed boost ka timer show kar rahe hain
        if (AHSAN.isSpeedBoosted) {
            long remaining = std::chrono::duration_cast<std::chrono::seconds>(
                AHSAN.speedBoostEndTime - std::chrono::steady_clock::now()
            ).count();
            DrawText(TextFormat("Speed Boost: %lds", remaining), 300, 35, 20, SKYBLUE);
        }

        // Game over screen
        if (gameOver) {
            DrawRectangle(0, 0, 800, 600, Fade(BLACK, 0.5f));
            if (AHSAN.IsAlive())
                DrawText("peak my goat", 320, 250, 40, GREEN);
            else
                DrawText("chalo bohat hogai", 250, 250, 40, RED);
        }
        // Drawing end
        EndDrawing();
    }

    // Cleanup memory: sare dynamically allocated objects delete karo
    for (int i = 0; i < bullets.size(); i++)
    {
        delete bullets[i];
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
    for (int i = 0; i < powerUps.size(); i++)
    {
        delete powerUps[i];
    }
    delete boss;
    // Window close karo
    UnloadTexture(playerTexture);


    CloseWindow();

    return 0;
}
