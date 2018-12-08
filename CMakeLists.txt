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
        Game.cpp Game.h
        roadfighterSFML/src/PlayerCarSFML.cpp roadfighterSFML/include/PlayerCarSFML.h
        roadfighterSFML/src/RacingCarSFML.cpp roadfighterSFML/include/RacingCarSFML.h
        roadfighterSFML/src/PassingCarSFML.cpp roadfighterSFML/include/PassingCarSFML.h
        roadfighterSFML/src/BulletSFML.cpp roadfighterSFML/include/BulletSFML.h roadfighter/src/Factory.cpp roadfighter/include/Factory.h roadfighterSFML/src/FactorySFML.cpp roadfighterSFML/include/FactorySFML.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

set(lib roadfighter/include)
add_subdirectory(roadfighter/include)
INCLUDE_DIRECTORIES(${lib})

# The program we're compiling with the sources set above
add_executable(RoadFighter ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(RoadFighter ${SFML_LIBRARIES})
TARGET_LINK_LIBRARIES(RoadFighter rf)
ADD_DEPENDENCIES(RoadFighter rf)
