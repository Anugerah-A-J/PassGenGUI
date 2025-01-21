cmake_minimum_required(VERSION 3.16)
project(passgen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(passgen
    main.cpp
    passgen.cpp
)

set_target_properties(passgen PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(passgen PRIVATE
    # Qt6::Core
    # Qt6::Gui
    Qt6::Widgets
)

# install(TARGETS gallery
#     BUNDLE  DESTINATION .
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )

# qt_generate_deploy_app_script(
#     TARGET gallery
#     OUTPUT_SCRIPT deploy_script
#     NO_UNSUPPORTED_PLATFORM_ERROR
# )
# install(SCRIPT ${deploy_script})