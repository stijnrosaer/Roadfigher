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
    class Entity {
        struct boundaries{
            pair<float, float> loc;
            float width;
            float height;
            pair<float, float> tlLoc;
            pair<float, float> brLoc;
        };
    protected:
        boundaries bounds;

    public:
        // constructor
        Entity();
        virtual ~Entity();

        // getters and setters
        virtual void draw() = 0;
        virtual void update(float speed, vector<shared_ptr<Entity>> entities) = 0;
        virtual float getSpeed() = 0;
        virtual bool toDelete() = 0;

        boundaries getBounds();
        bool collision(vector<shared_ptr<roadfighter::Entity>>);



    };
}


#endif //PROJECTGP_ENTITY_H
