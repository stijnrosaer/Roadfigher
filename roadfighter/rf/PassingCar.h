//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCAR_H
#define PROJECTGP_PASSINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class PassingCar : public roadfighter::Entity {
    protected:
        float speed;
        float relativeSpeed;

        bool del;

    public:
        // constructor
        PassingCar();

        virtual ~PassingCar();


        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        void setLoc(location loc);

        float getSpeed() override;

        void setDelete(bool del) override;

        bool toDelete() override;

    };
}

#endif //PROJECTGP_PASSINGCAR_H
