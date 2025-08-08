#include "../include/raylib.h"
#include "../include/Player.h"
#include "../include/Ball.h"

constexpr int FPS = 250;

int main(void)
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(800, 600, "Ping Pong");
  SetTargetFPS(FPS);
  Font font = LoadFont("fonts/Pixeboy.ttf");
  int width = GetScreenWidth();
  int height = GetScreenHeight();
  Player p1(25, height / 2.0f - P_HEIGHT / 2.0f, KEY_W, KEY_S);
  Player p2(width - 25 - P_WIDTH, 600 / 2.0f - P_HEIGHT / 2.0f, KEY_UP, KEY_DOWN);
  Ball b(B_RADIUS);
  unsigned short score1 = 0;
  unsigned short score2 = 0;
  while (!WindowShouldClose())
  {
    width = GetScreenWidth();
    height = GetScreenHeight();
    p2.x = width - 25 - P_WIDTH;
    float delta = GetFrameTime();
    p1.update(delta, b);
    p2.update(delta, b);
    int p = b.update(p1, p2, delta);
    if (p == 1) score2++;
    else if (p == -1) score1++;
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(width/2.0f, 0, 5, height, WHITE);
    p1.draw();
    p2.draw();
    b.draw();
    DrawTextEx(font, TextFormat("%d", score1), (Vector2){ width / 4.0f, 20 }, 40, 2, WHITE);
    DrawTextEx(font, TextFormat("%d", score2), (Vector2){ 3 * width / 4.0f, 20 }, 40, 2, WHITE);
    EndDrawing();
  }
  UnloadFont(font);
  CloseWindow();
  return 0;
}
