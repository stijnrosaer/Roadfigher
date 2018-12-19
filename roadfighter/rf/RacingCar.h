//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_RACINGCAR_H
#define PROJECTGP_RACINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class RacingCar : public roadfighter::Entity {
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
        RacingCar();


        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override = 0;

        void setLoc(const pair<float, float> &loc);
        float getSpeed() override;
        bool toDelete() override;

    };
}

#endif //PROJECTGP_RACINGCAR_H
