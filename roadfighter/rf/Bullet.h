//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public Entity {
        struct boundaries{
            pair<float, float> loc;
            float width;
            float height;
            pair<float, float> tlLoc;
            pair<float, float> brLoc;
        };
    protected:
        boundaries bounds;

        float speed;
        float relativeSpeed;

    public:
        // constructor
        Bullet();


        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override = 0;

        void setLoc(const pair<float, float> &loc);
        float getSpeed() override;

        bool toDelete() override;

    };
}

#endif //PROJECTGP_BULLET_H
