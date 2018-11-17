//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_ENTITY_H
#define PROJECTGP_ENTITY_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Transformation.h"

using namespace std;

namespace roadfighter {
    class Entity {
    private:

    public:
        // constructor
        Entity();

        static shared_ptr<roadfighter::Entity> createEntity(string name);

        // getters and setters


    };
}


#endif //PROJECTGP_ENTITY_H
