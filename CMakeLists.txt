cmake_minimum_required(VERSION 3.16)
project(cards VERSION 1.0.0)

# Enable testing support
include(CTest)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ standard settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Warning flags
string(APPEND CMAKE_CXX_FLAGS
      " -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion"
      " -Wshadow -Wimplicit-fallthrough -Wextra-semi -Wold-style-cast")

# Enable debug assertions and sanitizers
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -D_GLIBCXX_ASSERTIONS -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

# Find SFML and TGUI
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(TGUI 1 REQUIRED)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "source/*.cpp")

# Executable
add_executable(cards ${SOURCES})

# add_executable(cards egui.cpp switchbutton.cpp statistics.cpp graphics.cpp random.cpp boid.cpp flock.cpp main.cpp)

# Link SFML and TGUI
target_link_libraries(cards sfml-graphics sfml-window sfml-system TGUI::TGUI)