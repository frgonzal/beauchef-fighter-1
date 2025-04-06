cmake_minimum_required(VERSION 3.20)

project(beauchef_fighter CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory( "external/nothofagus" )
add_subdirectory( "external/rusty_audio")

file (GLOB_RECURSE SOURCE "source/*.cpp")
add_executable(beauchef_fighter ${SOURCE})

set_property(TARGET beauchef_fighter PROPERTY CXX_STANDARD 20)

target_include_directories(beauchef_fighter PRIVATE 
    "include"
    ${NOTHOFAGUS_INCLUDE}
    ${RUSTY_AUDIO_INCLUDE}
)

target_link_libraries(beauchef_fighter PRIVATE 
    nothofagus 
    rusty_audio
)