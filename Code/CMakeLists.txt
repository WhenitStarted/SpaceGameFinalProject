cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME spaceGame)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp player.cpp player.h Enemy.cpp Enemy.h Laser.cpp Laser.h Button.cpp Button.h Fonts.cpp Fonts.h Rectangle.cpp Rectangle.h States.cpp States.h WindowDialog.cpp WindowDialog.h Game.cpp Game.h Entity.cpp Entity.h MainGame.cpp MainGame.h Node.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h Collision.cpp Collision.h Health.cpp Health.h MainMenu.cpp MainMenu.h Score.cpp Score.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()