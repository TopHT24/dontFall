#pragma once
#include "raylib.h"

struct Projectile {
    Vector2 pos;
    float speed = 300.0f;

    void Update(float dt) { pos.y += speed * dt; }
    void Draw() const { DrawCircleV(pos, 4, BLUE); }
};
