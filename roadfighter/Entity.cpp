//
// Created by stijn on 16/11/18.
//

#include "Entity.h"
#include "PlayerCar.h"
#include "PassingCar.h"
#include "RacingCar.h"
#include "Bullet.h"

shared_ptr<roadfighter::Entity> roadfighter::Entity::createEntity(string name) {
    if (name == "playerCar"){
        return make_shared<roadfighter::PlayerCar>();
    } else if (name == "passingCar"){
        return make_shared<roadfighter::PassingCar>();
    } else if (name == "racingCar"){
        return make_shared<roadfighter::RacingCar>();
    } else if (name == "bulled"){
        return make_shared<roadfighter::Bullet>();
    }
}
