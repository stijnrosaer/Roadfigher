//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCAR_H
#define PROJECTGP_PASSINGCAR_H

#include "Entity.h"
#include "Observable.h"

namespace roadfighter {
class PassingCar : public roadfighter::Entity, public Observable
{
protected:
        float speed;
        float relativeSpeed;

        bool del;

        void movePassingCar();

public:
        // constructor
        PassingCar();

        virtual ~PassingCar();

        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        bool finish() override;

        void setLoc(location loc);
        float getSpeed() override;

        void setDelete(bool del) override = 0;
        bool toDelete() override;
};
} // namespace roadfighter

#endif // PROJECTGP_PASSINGCAR_H
