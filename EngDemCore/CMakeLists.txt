cmake_minimum_required(VERSION 3.28)

set(EDITOR_PROJECT_NAME EngDemCore)

add_library(${EDITOR_PROJECT_NAME} STATIC
    src/EngDemCore/Utils/test.cpp
    includes/EngDemCore/Utils/test.hpp
)

target_include_directories(${EDITOR_PROJECT_NAME} PUBLIC includes)
target_compile_features(${EDITOR_PROJECT_NAME} PUBLIC cxx_std_17)