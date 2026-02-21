cmake_minimum_required(VERSION 3.20)
project(ASTVisitor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Re-configure when files matching the glob change (new/removed *.cpp)
file(GLOB SOURCES CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")

add_executable(ASTVisitor ${SOURCES})

target_include_directories(ASTVisitor PRIVATE "${INCLUDE_DIR}")

if(MSVC)
    target_compile_options(ASTVisitor PRIVATE /W4 /WX /permissive-)
endif()

# Output: bin/Debug, bin/Release, ...
set_target_properties(ASTVisitor PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_SOURCE_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/bin/RelWithDebInfo"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/bin/MinSizeRel"
)
