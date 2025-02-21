cmake_minimum_required(VERSION 3.15)
project(ASTVisitor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Add include directories
include_directories(${INCLUDE_DIR})  # Ensures include/ headers are found

# Collect all source files
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

# Create executable
add_executable(ASTVisitor ${SOURCES})

# Set MSVC specific compiler flags
if (MSVC)
    target_compile_options(ASTVisitor PRIVATE /W4 /WX)
endif()

# Set output directory
set_target_properties(ASTVisitor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
