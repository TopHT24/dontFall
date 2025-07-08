#include "raylib.h"
#include "player.h"
#include <vector>
#include "projectile.h"  
#include "sound.h"

const int screenWidth = 688;
const int screenHeight = 432;



int main() {
    InitWindow(screenWidth, screenHeight, "Platformer Rush");
   
    SetTargetFPS(60);

    //background
    Texture2D background = LoadTexture("assets/demo_copy.jpg");

    

    //loading sounds
     Load_Sound();

    Player player;
    Rectangle ship = { -60, 50, 60, 30 };
    float shipSpeed = 100;
    float lastShotTime = 0;
    float timer = 0;

    std::vector<Projectile> bullets;

    //ground
    
    std::vector<Rectangle> platforms = {
        {0, 330, 80, 10}, {210, 320, 70, 10},
        {270,280,40,10},{305,260,30,10},{450, 260, 30, 10}, {480, 275, 90, 10},{620,310,60,10}
    };

    bool gameOver = false;
    bool win = false;
    
    float gravity = 500;
    float jumpSpeed = -250;
    float moveSpeed = 150;

    //background music
    Music song = LoadMusicStream("assets/game.mp3");

    //ground
    

    PlayMusicStream(song);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        timer += dt;

        if (!gameOver && !win) {
            UpdateMusicStream(song);
            player.Update(dt, gravity, jumpSpeed, moveSpeed);

            //collision
            for (auto& plat : platforms){
                player.ResolvePlatformCollision(plat);
            }

            //player falling 
            if(player.GetRect().y > screenHeight )gameOver = true;

            //player reaching destination   
            if (player.GetRect().x > 650) win = true;

            //ship movement 
            ship.x += shipSpeed * dt;
            if (ship.x > screenWidth) ship.x = -60;

            //bullets shooting time
            if ((timer - lastShotTime) >= 1.0f) {
                bullets.push_back({ { ship.x + 30, ship.y + 30 } });
                lastShotTime = timer;
            }

            //player-bullet collision
            for (auto& b : bullets) {
                b.Update(dt);
                if (CheckCollisionPointRec(b.pos, player.GetRect()))
                    gameOver = true;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        player.Draw();
        //drawing walkable platforms
        for (auto& plat : platforms) {
            
              DrawRectangleRec(plat, Fade(GREEN, 0.3f));
            
            
        }

       
        DrawRectangleRec(ship, GRAY);
        for (auto& b : bullets) b.Draw();

        if (gameOver)
         { 
            WaitTime(1.0);
            Play_Sound(SOUND_GAMEOVER);
            
            DrawText("GAME OVER", 250, 200, 30, RED);
            
            
         }
        else if (win) { Play_Sound(SOUND_WIN) ; WaitTime(1.0); DrawText("YOU WIN!", 250, 200, 30, GREEN);}
        else DrawText(TextFormat("Time: %.1f", timer), 10, 10, 20, BLACK);

        EndDrawing();
    }

    UnloadMusicStream(song);
    UnloadTexture(background);
    // UnloadTexture(fire);
    Unload_Sound();
    
    CloseWindow();
    return 0;
}
