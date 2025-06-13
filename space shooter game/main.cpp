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

   
  /*  CloseWindow();*/

    return 0;
}
