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

        /**
         * beweeg de passingCar op het speelveld
         */
        void movePassingCar();

public:
        // constructor
        /**
         * deflaut constructor van passing car
         */
        PassingCar();
        /**
         * destructor van PassingCar
         */
        ~PassingCar() override;

        // functions
        /**
         * teken de passing car
         */
        void draw() override = 0;
        /**
         * update de passingCar
         * @param speed snelheid van de player
         * @param entities entities waarmee rekening te houden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
        /**
         * voer actie uit wanneer een speler niet opnieuw moet beginnen
         * @return true als speler niet opnieuw moet beginnen
         */
        bool playerNoRespawn() override = 0;
        /**
         * update de Passing car op een andere manier wanneer de speler de finish bereikt heeft
         * @return true als passingCar klaar is met updaten en mag afgesloten worden
         */
        bool finish() override;
        /**
         * zet de locatie van de passingCar
         * @param loc de te zetten top left locatie
         */
        void setLoc(location loc);
        /**
         * vraag de effectieve snelheid van de passing car op
         * @return effectieve snelheid
         */
        float getSpeed() override;

        /**
         * zet of de passing car verwijderd mag worden
         * @param del true als het verwijderd moet worden
         */
        void setDelete(bool del) override = 0;
        /**
         * vraag op of de passingCar verwijderd moet worden
         * @return true als te verwijderen
         */
        bool toDelete() override;
};
} // namespace roadfighter

#endif // PROJECTGP_PASSINGCAR_H
