//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
class Bullet : public Entity
{
protected:
        float speed;
        float relativeSpeed;

        bool del;

public:
        // constructor
        Bullet(location loc);

        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        void setLoc(location loc);

        float getSpeed() override;
        void setDelete(bool del) override;
        bool toDelete() override;
        void moveBullet();
};
} // namespace roadfighter

#endif // PROJECTGP_BULLET_H
