# Stopwatch

A lightweight header-only C++ stopwatch and run recorder utility.

## Features

- Millisecond precision timing
- Pause/resume support
- Human-readable formatting
- Multiple run recording
- Header-only
- No dependencies


## Usage

```cpp
#include "Stopwatch/Stopwatch.h"

jTools::Stopwatch timer;

timer.start();

// work

timer.stop();

std::cout << timer.toString();
```

## Requirements

C++17 or newer
CMake 3.15+

## License

MIT