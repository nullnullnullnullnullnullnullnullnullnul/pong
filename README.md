# pong

[![ci](https://github.com/nullnullnullnullnullnullnullnullnullnul/pong/actions/workflows/ci.yml/badge.svg)](https://github.com/nullnullnullnullnullnullnullnullnullnul/pong/actions/workflows/ci.yml)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![raylib](https://img.shields.io/badge/raylib-5.5%2B-white.svg)](https://www.raylib.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A classic two-player Pong built in C++17 with [raylib](https://www.raylib.com/).

Two players share one keyboard, each controlling a paddle. The ball speeds up with every hit, and its bounce angle depends on where it strikes the paddle.

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

## Build

### Prerequisites

- CMake 3.16+
- A C++17 compiler (GCC 7+, Clang 6+)
- raylib 5.5 or newer

raylib is resolved by CMake in two steps: it first looks for an installed package; if none is found, it falls back to `FetchContent` and downloads raylib from source. The fallback build takes a few minutes but needs no extra setup.

Recommended: install raylib via your package manager so the build picks it up immediately.

| Distro | Command |
| --- | --- |
| Arch | `sudo pacman -S raylib` |
| Debian / Ubuntu | `sudo apt install libraylib-dev libgl1-mesa-dev libx11-dev` |
| Fedora | `sudo dnf install raylib-devel` |
| macOS (brew) | `brew install raylib` |

### Build commands

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/pong
```

The font (`fonts/Pixeboy.ttf`) is loaded from the current working directory, so run the binary from the repository root.

## Technical Details

| Constant   | Value | Description              |
| ---------- | ----- | ------------------------ |
| `B_RADIUS` | 7     | Ball radius in pixels    |
| `B_SPEED`  | 250   | Base ball speed (px/s)   |
| `P_WIDTH`  | 15    | Paddle width in pixels   |
| `P_HEIGHT` | 50    | Paddle height in pixels  |
| `P_SPEED`  | 350   | Base paddle speed (px/s) |
| `FPS`      | 250   | Target frame rate        |

## Quality

```bash
find src include -type f \( -name '*.cpp' -o -name '*.h' \) -print0 \
  | xargs -0 clang-format -i
```

CI enforces `clang-format` and fails on any diff.

## Project Structure

```
pong/
  fonts/           Pixeboy.ttf pixel font
  include/         project headers (Ball.h, Player.h)
  src/
    main.cpp       window setup, game loop, rendering, scoring
    Ball.cpp       ball movement, collision detection, bounce physics
    Player.cpp     paddle input handling and movement
  CMakeLists.txt   CMake build configuration
```

## License

MIT. See [LICENSE](LICENSE).
