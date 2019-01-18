//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"
#include "Observable.h"

namespace roadfighter {
class Bullet : public Entity, public Observable
{
protected:
        float speed;
        float relativeSpeed;

        bool del;

public:
        // constructor
        /**
         * constructor die een bullet aanmaakt
         * @param loc locatie waar de bullet moet gegenereerd worden
         */
        explicit Bullet(location loc);

        // functions
        /**
         * teken de bullet
         */
        void draw() override = 0;

        /**
         * update de locatie van de bullet
         * @param speed snelheid van de speler
         * @param entities entities waar rekening mee gehouden moet worden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        /**
         * versnel de bullet bij het einde van het spel
         * @return true als bullet van het scherm is
         */
        bool finish() override;

        /**
         * wijzig de locatie van de bullet
         * @param loc top left locatie
         */
        void setLoc(location loc);
        /**
         * geeft de effectieve snelheid van de bullet
         * @return effectieve snelheid
         */
        float getSpeed() override;
        /**
         * set of dit item te verwijderen is
         * @param del true al te verwijderen
         */
        void setDelete(bool del) override;
        /**
         * controleert of de bullet af het scherm is en moet verwijderd worden
         * @return true al het verwijderd is
         */
        bool toDelete() override;
        /**
         * beweeg de bullet ten opzichte van de relatieve snelheid
         */
        void moveBullet();
};
} // namespace roadfighter

#endif // PROJECTGP_BULLET_H
