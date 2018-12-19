//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public Entity {
    protected:
        pair<float, float> loc;

        float speed;
        float relativeSpeed;

    public:
        // constructor
        Bullet();


        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override = 0;

        float getSpeed() override;

        bool toDelete() override;

    };
}

#endif //PROJECTGP_BULLET_H
