cmake_minimum_required(VERSION 3.16)
project(passgen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_link_options(-static-libstdc++ -static-libgcc)
add_executable(passgen
    main.cpp
    passgen.cpp
)

set_target_properties(passgen PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(passgen PRIVATE
    Qt6::Widgets
)

if(MSVC)
  target_compile_options(passgen PRIVATE /W4 /WX)
else()
  target_compile_options(passgen PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()