//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_ENTITY_H
#define PROJECTGP_ENTITY_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace roadfighter {
    class Entity {
    public:
        static shared_ptr<Entity> createEntity(string name);

    };
}


#endif //PROJECTGP_ENTITY_H
