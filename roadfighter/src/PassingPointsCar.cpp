//
// Created by stijn on 16/11/18.
//

#include "../rf/PassingPointsCar.h"
#include "../../utils/include/Random.h"

roadfighter::PassingPointsCar::PassingPointsCar() {}

roadfighter::PassingPointsCar::~PassingPointsCar() {}

bool roadfighter::PassingPointsCar::playerNoRespawn()
{
        callObserver(pointsCar);
        return true;
}
