set(LIB_SRC rf/Bullet.h rf/Entity.h rf/Factory.h rf/PassingCar.h rf/PlayerCar.h rf/World.h rf/RacingCar.h rf/PassingNormalCar.h rf/PassingPointsCar.h
        src/Bullet.cpp src/Entity.cpp src/Factory.cpp src/PassingCar.cpp src/PlayerCar.cpp src/World.cpp src/RacingCar.cpp rf/Observable.h src/Observer.cpp rf/Observer.h src/Observable.cpp src/PassingNormalCar.cpp src/PassingPointsCar.cpp)

ADD_LIBRARY(rf SHARED ${LIB_SRC})