cmake_minimum_required(VERSION 3.10.2)
project(projectGP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall")





# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
set(SRC main.cpp
        Random.cpp Random.h
        Transformation.cpp Transformation.h
        roadfighter/src/Entity.cpp roadfighter/include/Entity.h
        roadfighter/src/PlayerCar.cpp roadfighter/include/PlayerCar.h
        roadfighter/src/RacingCar.cpp roadfighter/include/RacingCar.h
        roadfighter/src/PassingCar.cpp roadfighter/include/PassingCar.h
        roadfighter/src/Bullet.cpp roadfighter/include/Bullet.h
        roadfighter/src/World.cpp roadfighter/include/World.h
        Game.cpp Game.h
        roadfighterSFML/src/PlayerCarSFML.cpp roadfighterSFML/include/PlayerCarSFML.h
        roadfighterSFML/src/RacingCarSFML.cpp roadfighterSFML/include/RacingCarSFML.h
        roadfighterSFML/src/PassingCarSFML.cpp roadfighterSFML/include/PassingCarSFML.h
        roadfighterSFML/src/BulletSFML.cpp roadfighterSFML/include/BulletSFML.h roadfighter/src/Factory.cpp roadfighter/include/Factory.h roadfighterSFML/src/FactorySFML.cpp roadfighterSFML/include/FactorySFML.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
add_executable(fighter ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(fighter ${SFML_LIBRARIES})








