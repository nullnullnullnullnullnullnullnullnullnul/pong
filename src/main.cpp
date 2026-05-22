#include <raylib.h>

#include "Ball.h"
#include "Player.h"

namespace
{
constexpr int INITIAL_WIDTH = 800;
constexpr int INITIAL_HEIGHT = 600;
constexpr int PADDLE_MARGIN = 25;
constexpr int FPS = 250;
constexpr int SCORE_FONT_SIZE = 40;
constexpr float SCORE_FONT_SPACING = 2.0f;
constexpr float SCORE_Y = 20.0f;
constexpr int DIVIDER_WIDTH = 5;
} // namespace

int main()
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, "Ping Pong");
  SetTargetFPS(FPS);

  Font font = LoadFont("fonts/Pixeboy.ttf");

  int width = GetScreenWidth();
  int height = GetScreenHeight();
  Player p1(PADDLE_MARGIN, height / 2.0f - P_HEIGHT / 2.0f, KEY_W, KEY_S);
  Player p2(width - PADDLE_MARGIN - P_WIDTH, height / 2.0f - P_HEIGHT / 2.0f, KEY_UP, KEY_DOWN);
  Ball b(B_RADIUS);
  unsigned short score1 = 0;
  unsigned short score2 = 0;

  while (!WindowShouldClose()) {
    width = GetScreenWidth();
    height = GetScreenHeight();
    p2.x = width - PADDLE_MARGIN - P_WIDTH;

    float delta = GetFrameTime();
    p1.update(delta, b);
    p2.update(delta, b);
    int point = b.update(p1, p2, delta);
    if (point == 1) {
      ++score2;
    } else if (point == -1) {
      ++score1;
    }

    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(width / 2 - DIVIDER_WIDTH / 2, 0, DIVIDER_WIDTH, height, WHITE);
    p1.draw();
    p2.draw();
    b.draw();
    DrawTextEx(font, TextFormat("%d", score1), Vector2{width / 4.0f, SCORE_Y}, SCORE_FONT_SIZE,
               SCORE_FONT_SPACING, WHITE);
    DrawTextEx(font, TextFormat("%d", score2), Vector2{3 * width / 4.0f, SCORE_Y}, SCORE_FONT_SIZE,
               SCORE_FONT_SPACING, WHITE);
    EndDrawing();
  }

  UnloadFont(font);
  CloseWindow();
  return 0;
}
