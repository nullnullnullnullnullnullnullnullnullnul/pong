# pong

A classic Pong game built in C++17 with [raylib](https://www.raylib.com/).

Two players compete on a resizable window, each controlling a paddle with keyboard inputs. The ball speeds up with every hit, and its bounce angle changes depending on where it strikes the paddle.

## Gameplay

- Player 1 (left): `W` / `S`
- Player 2 (right): `Up Arrow` / `Down Arrow`
- Press `Esc` or close the window to quit.

Scoring happens when the ball passes behind the opponent's paddle. The score is displayed at the top of each half using a custom pixel font.

## Features

- Resizable window with dynamic paddle and ball repositioning.
- Angle-based bounce physics: the ball's deflection angle depends on where it contacts the paddle surface.
- Progressive speed multiplier: both ball and paddle speed increase with each rally hit, rewarding longer exchanges.
- Brief reset cooldown after each point to prevent instant re-scoring.
- Custom pixel font rendering for the score display.

## Project Structure

```
pong/
├── fonts/          # Pixeboy.ttf pixel font
├── include/        # Header files (Ball.h, Player.h, raylib.h)
├── lib/            # Pre-built raylib static library (libraylib.a)
├── src/
│   ├── main.cpp    # Window setup, game loop, rendering, scoring
│   ├── Ball.cpp    # Ball movement, collision detection, bounce physics
│   └── Player.cpp  # Paddle input handling and movement
└── CMakeLists.txt  # CMake build configuration
```

## Building

Requires CMake 3.10+ and a C++17 compiler. The raylib static library is included in `lib/`.

```bash
cmake -B build
cmake --build build
./build/pong
```

### Linux Dependencies

The build links against the following system libraries:

- `GL` (OpenGL)
- `X11`
- `pthread`, `rt`, `dl`, `m`

On Debian/Ubuntu:

```bash
sudo apt install libx11-dev libgl-dev
```

## Technical Details

| Constant   | Value | Description              |
|------------|-------|--------------------------|
| `B_RADIUS` | 7     | Ball radius in pixels    |
| `B_SPEED`  | 250   | Base ball speed (px/s)   |
| `P_WIDTH`  | 15    | Paddle width in pixels   |
| `P_HEIGHT` | 50    | Paddle height in pixels  |
| `P_SPEED`  | 350   | Base paddle speed (px/s) |
| `FPS`      | 250   | Target frame rate        |

## License

No license specified.
