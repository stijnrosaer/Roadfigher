set(LIBRARY_SRC
        src/Entity.cpp src/Factory.cpp src/Bullet.cpp src/PassingCar.cpp src/PlayerCar.cpp src/RacingCar.cpp src/World.cpp
        )

add_library(roadfighter SHARED ${LIBRARY_SRC})
TARGET_INCLUDE_DIRECTORIES(roadfighter PUBLIC roadfighter/include)
