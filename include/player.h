#pragma once
#include "raylib.h"

class Player {
public:
    Player(const char* path= "assets/run_right.png");
    void Update(float dt, float gravity, float jumpSpeed, float moveSpeed);
    void ResolvePlatformCollision(const Rectangle& platform);
    void Draw() const;
    Rectangle GetRect() const;
    bool IsOnGround() const;

    ~Player();

private:
    Rectangle rect;
    Vector2 velocity;
    bool isOnGround;
    Texture2D img;
    Rectangle src;
   
};
