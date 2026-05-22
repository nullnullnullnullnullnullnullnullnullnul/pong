#include "Player.h"

#include "Ball.h"

Player::Player(float x, float y, int keyUp, int keyDown)
    : x(x), y(y), keyUp(keyUp), keyDown(keyDown)
{
}

void Player::update(float delta, const Ball &ball)
{
  int screenHeight = GetScreenHeight();
  float currentSpeed = P_SPEED * ball.getSpeedMultiplier();
  if (IsKeyDown(keyUp)) {
    y -= currentSpeed * delta;
  }
  if (IsKeyDown(keyDown)) {
    y += currentSpeed * delta;
  }
  if (y < 0) {
    y = 0;
  } else if (y > screenHeight - P_HEIGHT) {
    y = screenHeight - P_HEIGHT;
  }
}

void Player::draw() const
{
  DrawRectangle(static_cast<int>(x), static_cast<int>(y), P_WIDTH, P_HEIGHT, WHITE);
}
