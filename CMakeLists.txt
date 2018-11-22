cmake_minimum_required(VERSION 3.10.2)
project(projectGP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")





# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
set(SRC main.cpp
        Random.cpp Random.h
        Transformation.cpp Transformation.h
        roadfighter/Entity.cpp roadfighter/Entity.h
        roadfighter/PlayerCar.cpp roadfighter/PlayerCar.h
        roadfighter/RacingCar.cpp roadfighter/RacingCar.h
        roadfighter/PassingCar.cpp roadfighter/PassingCar.h
        roadfighter/Bullet.cpp roadfighter/Bullet.h
        roadfighter/World.cpp roadfighter/World.h
        Game.cpp Game.h
        roadfighterSFML/PlayerCarSFML.cpp roadfighterSFML/PlayerCarSFML.h
        roadfighterSFML/RacingCarSFML.cpp roadfighterSFML/RacingCarSFML.h
        roadfighterSFML/PassingCarSFML.cpp roadfighterSFML/PassingCarSFML.h
        roadfighterSFML/BulletSFML.cpp roadfighterSFML/BulletSFML.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
add_executable(roadfighter ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(roadfighter ${SFML_LIBRARIES})







