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

namespace roadfighter {
    class Entity {
    private:

    public:
        // constructor
        Entity();

        // getters and setters
        virtual void draw() = 0;
        virtual void update() = 0;


    };
}


#endif //PROJECTGP_ENTITY_H
