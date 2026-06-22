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

See examples/StopwatchExample.cpp for more detailed usage.


## Testing

This project uses GoogleTest for unit testing and CMake + CTest for test execution.

### Build tests

From the project root:

```bash
cmake -S . -B build
cmake --build build --config Debug
```

### Run tests (CTest)

Run the full test suite:
```bash
ctest --test-dir build -C Debug --output-on-failure
```

### Important note about CTest output

This project currently registers one CTest test target:

```bash
StopwatchTests
```

That test executes the full GoogleTest binary, which contains multiple unit tests internally, for example:

 - StopwatchTests.StartsAtZero
 - StopwatchTests.MeasuresElapsedTime
 - StopwatchTests.PauseAndResumeWorks
 - RunRecorderTests.RecordsSingleRun
 - OperatorTests.StopwatchAddition

To see individual test case output, run the executable directly:

```bash
build/Debug/StopwatchTests.exe
```

## Requirements
C++17 or newer
CMake 3.15+
GoogleTest (automatically fetched via CMake FetchContent)

## Project Structure
```
include/
  Stopwatch/
    Stopwatch.h

examples/
  StopwatchExample.cpp

tests/
  StopwatchTests.cpp
```
## License

MIT