#pragma once
#include "raylib.h"
#include "../include/Ball.h"

constexpr int P_WIDTH = 15;
constexpr int P_HEIGHT = 50;
constexpr float P_SPEED = 350.f;

class Player {
public:
  float x, y;
  int keyUp, keyDown;
  Player(float x, float y, int keyUp, int keyDown);
  void update(float delta, const Ball& ball);
  void draw() const;
};
