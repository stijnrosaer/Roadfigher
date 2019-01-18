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

        /**
         * beweeg de racingCar
         * @param dir richting waar in te bewegen
         */
        void moveRacingCar(direction dir);

public:
        // constructor
        /**
         * default constructor van racingCar
         */
        RacingCar();

        // functions
        /**
         * teken de racingCar
         */
        void draw() override = 0;
        /**
         * update de racingCar op de nodige manier
         * @param speed snelheid van de playerCar
         * @param entities de entitites waar tegen over gecontroleerd moet worden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
        /**
         * update de racing Car na de speler de finish over gaat
         * @return true als de racingCar klaar is om verwijderd te worden
         */
        bool finish() override;
        /**
         * zet de nieuwe top left locatie
         * @param loc de te zetten locatie
         */
        void setLoc(location loc);
        /**
         * vraag de effectieve snelheid op
         * @return effectieve snelheid
         */
        float getSpeed() override;
        /**
         * zet of de racingCar verwijderd moet worden
         * @param del true als te verwijderen
         */
        void setDelete(bool del) override;
        /**
         * vraag op of de racingCar verwijderd moet worden
         * @return true als te verwijderen
         */
        bool toDelete() override;
};
} // namespace roadfighter

#endif // PROJECTGP_RACINGCAR_H
