cmake_minimum_required(VERSION 2.8.11)
project(test_matrix2x2)

set(source_files
  main.cpp
  vec2.cpp
  matrix2x2.cpp
)

add_executable (${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME})

