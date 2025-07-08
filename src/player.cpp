#include "player.h"


Player::Player(const char* path) {
    img = LoadTexture(path);
    rect = { 10, 330,32,32};
    velocity = { 0, 0 };
    isOnGround = false;
    src = {32,0,(float)(img.width/8),(float)img.height};
};

Player::~Player(){
    UnloadTexture(img);
}

void Player::Update(float dt, float gravity, float jumpSpeed, float moveSpeed) {
    if (IsKeyDown(KEY_RIGHT)) velocity.x = moveSpeed;
    else if (IsKeyDown(KEY_LEFT)) velocity.x = -moveSpeed;
    else velocity.x = 0;

    if (IsKeyPressed(KEY_SPACE) && isOnGround) {
        velocity.y = jumpSpeed;
        isOnGround = false;
    }

    velocity.y += gravity * dt;
    rect.x += velocity.x * dt;
    rect.y += velocity.y * dt;
}

 void Player::ResolvePlatformCollision(const Rectangle& platform) {
    if (CheckCollisionRecs(rect, platform) && velocity.y >= 0) {
       
        rect.y = platform.y - rect.height;
        velocity.y = 0;
        isOnGround = true;
    
    }


}

void Player::Draw() const {
    float scale = 2.0f; // or any other factor
    Rectangle dest = {
        rect.x,
        rect.y,
        rect.width * scale,
        rect.height * scale
    };
    // DrawRectangleRec(rect, WHITE);
    DrawTexturePro(img,src,dest,{0,0},0.0f,WHITE);
}

Rectangle Player::GetRect() const {
    return rect;
}

bool Player::IsOnGround() const {
    return isOnGround;
}
