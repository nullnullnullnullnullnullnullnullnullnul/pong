#pragma once

#include <raylib.h>

constexpr float B_RADIUS = 7.f;
constexpr float B_SPEED = 250.f;

class Player;

class Ball
{
public:
  float x, y;
  float speedX, speedY;
  float radius;
  bool resetCooldown;
  float resetTimer;
  float speedMultiplier;

  Ball(float radius);
  void reset();
  bool checkCollisionWithPlayer(const Player &p) const;
  int update(const Player &p1, const Player &p2, float delta);
  void bounce(const Player &p);
  void draw() const;
  float getSpeedMultiplier() const;
};
