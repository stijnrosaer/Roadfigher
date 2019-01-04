//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_RACINGCAR_H
#define PROJECTGP_RACINGCAR_H

#include "Entity.h"

namespace roadfighter {
class RacingCar : public roadfighter::Entity
{
protected:
        float speed;
        float relativeSpeed;

        bool del;

public:
        // constructor
        RacingCar();

        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override = 0;

        void setLoc(const pair<float, float>& loc);

        float getSpeed() override;
        void setDelete(bool del) override;
        bool toDelete() override;
};
} // namespace roadfighter

#endif // PROJECTGP_RACINGCAR_H
