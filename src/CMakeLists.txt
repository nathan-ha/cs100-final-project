
cmake_minimum_required(VERSION 3.20)

add_library(simpleLibrary
   # add .cpp files here
   characters/character.cpp
   characters/skeleton.cpp
   characters/thief.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_executable(runBuild
  main.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})
target_link_libraries(runBuild simpleLibrary)


