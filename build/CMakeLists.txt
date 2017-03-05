# version of cmake currently installed on my computer
cmake_minimum_required(VERSION 3.5.1)

# why wouldn't we name it as damned?
project(damned)

# automagically detect files
file(GLOB_RECURSE sources ../src/*.cpp ../src/*.hpp)

# our executale's name is the same as the project's name, how lovely!
add_executable(${PROJECT_NAME} ${sources})

# compilation flags
target_compile_options(${PROJECT_NAME} PUBLIC -std=c++14 -O3 -Wall)

target_include_directories(${PROJECT_NAME} PUBLIC ../src)

# see https://github.com/krux02/minimal_cmake_example for this CMakeFile
set(CPACK_PACKAGE_NAME "crispy-octo-couscous")
set(CPACK_PACKAGE_VERSION "0.0.1")
set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)