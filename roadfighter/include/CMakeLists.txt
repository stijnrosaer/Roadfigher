set(LIB_SRC Bullet.h Entity.h Factory.h PassingCar.h PlayerCar.h World.h RacingCar.h
        ../src/Bullet.cpp ../src/Entity.cpp ../src/Factory.cpp ../src/PassingCar.cpp ../src/PlayerCar.cpp ../src/World.cpp ../src/RacingCar.cpp)

ADD_LIBRARY(Roadfighter SHARED ${LIB_SRC})