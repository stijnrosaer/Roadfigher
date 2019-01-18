//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_WORLD_H
#define PROJECTGP_WORLD_H

#include "Entity.h"

namespace roadfighter {
class World : public roadfighter::Entity
{
private:
        float speed;

        shared_ptr<roadfighter::Entity> player;
        vector<shared_ptr<roadfighter::Entity>> entities;
        vector<shared_ptr<roadfighter::Entity>> racingCars;

public:
        // constructor
        /**
         * default constructor van world
         */
        World();

        // getters and setters
        /**
         * vraag de playerCar op
         * @return shared entity pointer naar playerCar
         */
        const shared_ptr<Entity>& getPlayer() const;
        /**
         * zet de playerCar
         * @param player shared entity pointer naar playerCar
         */
        void setPlayer(const shared_ptr<Entity>& player);
        /**
         * voeg een entity toe aan entities
         * @param object shared entity pointer naar de toe te voegen entity
         */
        void addEntity(const shared_ptr<Entity>& object);
        /**
         * voeg een racingCar toe aan racingCars
         * @param passingCar shared entity pointer naar de toe te voegen racingCar
         */
        void addRacingCars(const shared_ptr<Entity>& passingCar);

        // functions
        /**
         * teken alle objecten bij gehouden in world
         */
        void draw() override;
        /**
         * update alle objecten bijghouden in word
         * @param speed snelheid van de playerCar
         * @param entities niet gebruikt
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
        /**
         * update elk object na dat de playerCar over de finish is
         * @return true als elk object klaar is om verwijderd te worden
         */
        bool finish() override;
        /**
         * vraag de snelheid op van de playerCar
         * @return snelehid van de playercar
         */
        float getSpeed() override;
        /**
         * verwijder alle objecten die verwijderd moeten worden
         * @return true als correct verwijderd
         */
        bool toDelete() override;
        /**
         * niet gebruikt
         * @param del niet gebruikt
         */
        void setDelete(bool del) override;
        /**
         * verwijder alle items die mogen verwijderd worden als er colission tussen die twee is
         */
        void remCollisions();
};
} // namespace roadfighter

#endif // PROJECTGP_WORLD_H
