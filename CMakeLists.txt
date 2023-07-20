cmake_minimum_required(VERSION 3.10)
project(Queue C)

# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add all source files to the variable
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/queue.c
    main.c
)

# Create the executable
add_executable(main_app ${SOURCES})