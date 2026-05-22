#include "Ball.h"

#include <cmath>

#include "Player.h"

Ball::Ball(float radius) : radius(radius)
{
  reset();
}

void Ball::reset()
{
  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();
  x = screenWidth / 2.0f;
  y = screenHeight / 2.0f;
  speedX = (GetRandomValue(0, 1) == 0 ? -1 : 1) * B_SPEED;
  speedY = (GetRandomValue(0, 1) == 0 ? -1 : 1) * B_SPEED;
  resetCooldown = true;
  resetTimer = 0.25f;
  speedMultiplier = 1.0f;
}

bool Ball::checkCollisionWithPlayer(const Player &p) const
{
  return (x - radius <= p.x + P_WIDTH && x + radius >= p.x) &&
         (y + radius >= p.y && y - radius <= p.y + P_HEIGHT);
}

int Ball::update(const Player &p1, const Player &p2, float delta)
{
  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();
  if (resetCooldown) {
    resetTimer -= delta;
    if (resetTimer <= 0.0f) {
      resetCooldown = false;
    } else {
      return 0;
    }
  }
  x += speedX * delta;
  y += speedY * delta;
  if (y - radius <= 0) {
    y = radius;
    speedY *= -1;
  } else if (y + radius >= screenHeight) {
    y = screenHeight - radius;
    speedY *= -1;
  }
  if (checkCollisionWithPlayer(p1)) {
    x = p1.x + P_WIDTH + radius;
    speedX = std::abs(speedX);
    bounce(p1);
  } else if (checkCollisionWithPlayer(p2)) {
    x = p2.x - radius;
    speedX = -std::abs(speedX);
    bounce(p2);
  }
  if (x < 0) {
    reset();
    return 1;
  }
  if (x > screenWidth) {
    reset();
    return -1;
  }
  return 0;
}

void Ball::bounce(const Player &p)
{
  float relativeIntersectY = (p.y + P_HEIGHT / 2.0f) - y;
  float normalizedRelativeIntersectionY = relativeIntersectY / (P_HEIGHT / 2.0f);
  float bounceAngle = normalizedRelativeIntersectionY * (PI / 4);
  speedMultiplier += 0.05f;
  speedY = -B_SPEED * speedMultiplier * std::sin(bounceAngle);
  speedX = (speedX > 0 ? 1 : -1) * B_SPEED * speedMultiplier * std::cos(bounceAngle);
}

void Ball::draw() const
{
  DrawRectangle(static_cast<int>(x - radius), static_cast<int>(y - radius),
                static_cast<int>(2 * radius), static_cast<int>(2 * radius), WHITE);
}

float Ball::getSpeedMultiplier() const
{
  return speedMultiplier;
}
