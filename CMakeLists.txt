cmake_minimum_required(VERSION 3.8)
project(FlyJoyride)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Test)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(SOURCE_FILES main.cpp Game.cpp Game.h Window.cpp Window.h Character.cpp Character.h
        Block.cpp Block.h BlockFactory.cpp BlockFactory.h
        Enemy.cpp Enemy.h EnemyFactory.cpp EnemyFactory.h
        Observer.h Subject.h Achievement.cpp Achievement.h DisplayElement.h)
add_executable(FlyJoyride ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})

set(EXECUTABLE_NAME ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif ()