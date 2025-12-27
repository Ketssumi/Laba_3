cmake_minimum_required(VERSION 3.14)
project(Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Политика для FetchContent
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# Основная программа
add_executable(figures
    src/main.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Octagon.cpp
    src/Array.cpp
)

target_include_directories(figures PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Тесты
enable_testing()

add_executable(figures_tests
    tests/tests_figures.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Octagon.cpp
    src/Array.cpp
)

target_link_libraries(figures_tests
    gtest_main
)

target_include_directories(figures_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Для избежания проблем с кириллицей используем add_test вместо gtest_discover_tests
add_test(NAME AllFiguresTests COMMAND figures_tests)