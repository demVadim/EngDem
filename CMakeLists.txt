cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME EngDem)

add_subdirectory(EngDemCore)
add_subdirectory(EngDemEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EngDemEditor)