//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_ENTITY_H
#define PROJECTGP_ENTITY_H

#include <iostream>
#include <vector>
#include <memory>
#include "../../Transformation.h"

using namespace std;

namespace roadfighter  {
    class Entity : public enable_shared_from_this<Entity> {
    private:

    public:
        // constructor
        Entity();
        virtual ~Entity();

        // getters and setters
        virtual void draw() = 0;
        virtual void update(int speed) = 0;
        virtual float getSpeed() = 0;


    };
}


#endif //PROJECTGP_ENTITY_H
