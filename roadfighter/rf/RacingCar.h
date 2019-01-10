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
    enum direction
    {
        up,
        down,
        left,
        right,
        slow
    };
        float speed;
        float relativeSpeed;

        bool del;

    void moveRacingCar(direction dir);


public:
        // constructor
        RacingCar();

        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
        void setLoc(location loc);
        float getSpeed() override;
        void setDelete(bool del) override;
        bool toDelete() override;
};
} // namespace roadfighter

#endif // PROJECTGP_RACINGCAR_H
