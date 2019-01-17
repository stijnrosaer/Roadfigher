//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_ENTITY_H
#define PROJECTGP_ENTITY_H

#include "../../Random.h"
#include "../../Transformation.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace roadfighter {
class Entity
{
        struct boundaries
        {
                location loc;
                float width;
                float height;
                location tlLoc;
                location brLoc;
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
        virtual void setDelete(bool del) = 0;
        virtual bool finish() = 0;

        boundaries getBounds();

        void setBounds(const boundaries& bounds);

        shared_ptr<roadfighter::Entity> collision(vector<shared_ptr<roadfighter::Entity>>);
};
} // namespace roadfighter

#endif // PROJECTGP_ENTITY_H
