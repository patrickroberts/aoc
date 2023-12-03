cmake_minimum_required(VERSION 3.26)

project(
  Aoc
  VERSION 1.0.0
  LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  boost_mp11
  GIT_REPOSITORY https://github.com/boostorg/mp11.git
  GIT_TAG boost-1.83.0)
FetchContent_MakeAvailable(boost_mp11)

add_library(aoc INTERFACE)
target_link_libraries(aoc INTERFACE boost_mp11)
target_compile_features(aoc INTERFACE cxx_std_23)
target_compile_options(aoc INTERFACE -Wall -Werror -Wextra -pedantic
                                     -ftemplate-backtrace-limit=0)
target_include_directories(aoc INTERFACE "${PROJECT_SOURCE_DIR}/include")

function(aoc_puzzle_input YEAR DAY)
  file(DOWNLOAD https://adventofcode.com/${YEAR}/day/${DAY}/input
       "${PROJECT_SOURCE_DIR}/puzzle/${YEAR}/day/${DAY}/input.txt"
       HTTPHEADER "Cookie: session=$ENV{AOC_SESSION_COOKIE}")
endfunction()

function(aoc_answer YEAR DAY PART KIND)
  set(TARGET aoc_${YEAR}_day_${DAY}_part_${PART}_${KIND})

  if(KIND STREQUAL "example")
    # try to use example input for part
    set(AOC_INPUT
        "${PROJECT_SOURCE_DIR}/example/${YEAR}/day/${DAY}/part/${PART}/input.txt"
    )
    if(NOT EXISTS "${AOC_INPUT}")
      # otherwise use example input for day
      set(AOC_INPUT
          "${PROJECT_SOURCE_DIR}/example/${YEAR}/day/${DAY}/input.txt")

      # create input file if it doesn't exist yet
      if(NOT EXISTS "${AOC_INPUT}")
        file(WRITE "${AOC_INPUT}" "\n")
      endif()
    endif()

    # reconfigure if example input file is modified
    set_property(
      DIRECTORY
      APPEND
      PROPERTY CMAKE_CONFIGURE_DEPENDS "${AOC_INPUT}")
  else()
    # use downloaded puzzle input for day
    set(AOC_INPUT "${PROJECT_SOURCE_DIR}/puzzle/${YEAR}/day/${DAY}/input.txt")
  endif()

  # format input for target
  file(READ "${AOC_INPUT}" AOC_INPUT)
  string(REGEX REPLACE "([^\n]*)\n" "\n\"\\1\"" AOC_INPUT "${AOC_INPUT}")
  string(REPLACE "\"\n\"" "\",\n\"" AOC_INPUT "${AOC_INPUT}")

  # set solution header file for target
  set(AOC_SOLUTION solution/${YEAR}/day/${DAY}/part/${PART}.hpp)
  if(NOT EXISTS "${PROJECT_SOURCE_DIR}/include/${AOC_SOLUTION}")
    configure_file("${PROJECT_SOURCE_DIR}/solution.hpp.in"
                   "${PROJECT_SOURCE_DIR}/include/${AOC_SOLUTION}" COPYONLY)
  endif()

  # set source file for target
  set(AOC_ANSWER
      "${PROJECT_SOURCE_DIR}/answer/${YEAR}/day/${DAY}/part/${PART}/${KIND}.cpp"
  )
  configure_file("${PROJECT_SOURCE_DIR}/answer.cpp.in" "${AOC_ANSWER}" @ONLY)
  add_executable(${TARGET} "${AOC_ANSWER}")
  target_link_libraries(${TARGET} PRIVATE aoc)
  # convenience target to compile and run executable
  add_custom_target(run_${TARGET} COMMAND ${TARGET})
endfunction()

function(aoc_part YEAR DAY PART)
  aoc_answer(${YEAR} ${DAY} ${PART} example)
  aoc_answer(${YEAR} ${DAY} ${PART} puzzle)
endfunction()

function(aoc_day YEAR DAY)
  # downloads puzzle input for day
  aoc_puzzle_input(${YEAR} ${DAY})

  aoc_part(${YEAR} ${DAY} 1)
  aoc_part(${YEAR} ${DAY} 2)
endfunction()

aoc_day(2023 1)
aoc_day(2023 2)
