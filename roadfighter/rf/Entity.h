//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_ENTITY_H
#define PROJECTGP_ENTITY_H

#include "../../utils/include/Random.h"
#include "../../utils/include/Transformation.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace roadfighter {
class Entity
{
        struct boundaries
        {
                location loc;
                float width;
                float height;
                location tlLoc;
                location brLoc;
        };

protected:
        boundaries bounds;

public:
        // constructor
        /**
         * default constructor van een entity
         */
        Entity();
        /**
         * destructor van een entity
         */
        virtual ~Entity();

        /**
         * teken de entity
         */
        virtual void draw() = 0;
        /**
         * update de entity ten opzichte van snelheid en andere entities
         * @param speed sneleheid van de speler
         * @param entities entities waarmee rekening gehouden moet worden
         */
        virtual void update(float speed, vector<shared_ptr<Entity>> entities) = 0;
        /**
         * geef de snelheid van de entity
         * @return snelheid
         */
        virtual float getSpeed() = 0;
        /**
         * geef of een entity verwijderd moet worden
         * @return true als het te verwijderen is
         */
        virtual bool toDelete() = 0;
        /**
         * set of het item verwijderd moet worden
         * @param del true als het verwijderd moet worden
         */
        virtual void setDelete(bool del) = 0;
        /**
         * update de entity wanneer de speler de finish bereikt heeft
         * @return true als de entity klaar is om afgesloten te worden
         */
        virtual bool finish() = 0;
        /**
         * geef of de speler terug gezet moet worden na een botsing
         * @return true als de speler opnieuw moet beginnen
         */
        virtual bool playerNoRespawn();
        /**
         * geef de bounds van de entity
         * @return bounds die locaties bevatten, breedte en hoogt
         */
        boundaries getBounds();
        /**
         * zet de locaties van de entity
         * @param bounds bounds die locaties bevatten, breedte en hoogte
         */
        void setBounds(const boundaries& bounds);
        /**
         * controleert of een entity een botsinig heeft met andere entities
         * @param entities te controleren entities
         * @return geeft een shared pointer terug naar de entity waarmee gebotst is
         */
        shared_ptr<roadfighter::Entity> collision(vector<shared_ptr<roadfighter::Entity>> entities);
};
} // namespace roadfighter

#endif // PROJECTGP_ENTITY_H
