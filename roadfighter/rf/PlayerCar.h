//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"
#include "Observable.h"

namespace roadfighter {
class PlayerCar : public roadfighter::Entity, public Observable
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

        int exploding;
        int waitForShoot;

        bool del;

        /**
         * beweeg de PlayerCar op het speelveld in een bepaalde richting
         * @param dir de richting waar in bewogen moet worden
         */
        void movePlayerCar(direction dir);

public:
        // constructor
        /**
         * constructor van PlayerCar
         */
        PlayerCar();

        // functions
        /**
         * teken de playerCar
         */
        void draw() override = 0;
        /**
         * update de PlayerCar
         * @param speed vorige snelheid van de playercar
         * @param entities alle entities waar tegenover gecontroleerd moet worden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
        /**
         * update de playerCar na het bereiken vna de finish
         * @return true als de playerCar klaar is om afgesloten te worden
         */
        bool finish() override;
        /**
         * zet de locatie
         * @param loc de nieuw te zetten center locatie
         */
        void setLoc(location loc);
        /**
         * vraag de snelheid van de playerCar op
         * @return huidige snelheid
         */
        float getSpeed() override;
        /**
         * zet of de playerCar verwijderd moet worden
         * @param del true als verwijderd moet worden
         */
        void setDelete(bool del) override;
        /**
         * vraag op of de playerCar verwijderd moet worden
         * @return true als te verwijderen
         */
        bool toDelete() override;
        /**
         * zet de playerCar terug centraal onderaan met snelheid 0
         */
        void reload();
};
} // namespace roadfighter

#endif // PROJECTGP_PLAYERCAR_H
