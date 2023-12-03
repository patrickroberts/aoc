# Advent of Code in C++ (Boost.Mp11)

## Setup

```sh
cmake -B build -S . -DAOC_SESSION_COOKIE=...
```

Obtain your value for `AOC_SESSION_COOKIE` by inspecting the `Cookie` HTTP request header your browser sends while logged into https://adventofcode.com. This will be used by CMake to download the puzzle input files for each day during configuration.

You should avoid committing your session cookie, or your puzzle input files.

## Running

```sh
cmake --build build --target run_aoc_2023_day_1_part_1_example
```

```
https://adventofcode.com/2023/day/1
part 1 example = 142
Build finished with exit code 0
```

Have fun!
