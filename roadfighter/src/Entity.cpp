//
// Created by stijn on 16/11/18.
//

#include "../rf/Entity.h"

roadfighter::Entity::Entity() = default;

roadfighter::Entity::~Entity() {}

roadfighter::Entity::boundaries roadfighter::Entity::getBounds() { return this->bounds; }

shared_ptr<roadfighter::Entity> roadfighter::Entity::collision(vector<shared_ptr<roadfighter::Entity>> entities)
{
        bool collision = false;
        for (auto& item : entities) {
                // top left collides
                if (this->bounds.tlLoc.x > item->getBounds().tlLoc.x &&
                    this->bounds.tlLoc.x < item->getBounds().brLoc.x &&
                    this->bounds.tlLoc.y < item->getBounds().tlLoc.y &&
                    this->bounds.tlLoc.y > item->getBounds().brLoc.y) {
                        return item;

                        // bottom right collides;
                } else if (this->bounds.brLoc.x > item->getBounds().tlLoc.x &&
                           this->bounds.brLoc.x < item->getBounds().brLoc.x &&
                           this->bounds.brLoc.y < item->getBounds().tlLoc.y &&
                           this->bounds.brLoc.y > item->getBounds().brLoc.y) {
                        return item;

                        // top right collides
                } else if (this->bounds.brLoc.x > item->getBounds().tlLoc.x &&
                           this->bounds.brLoc.x < item->getBounds().brLoc.x &&
                           this->bounds.tlLoc.y < item->getBounds().tlLoc.y &&
                           this->bounds.tlLoc.y > item->getBounds().brLoc.y) {
                        return item;

                        // bottom left collides
                } else if (this->bounds.tlLoc.x > item->getBounds().tlLoc.x &&
                           this->bounds.tlLoc.x < item->getBounds().brLoc.x &&
                           this->bounds.brLoc.y < item->getBounds().tlLoc.y &&
                           this->bounds.brLoc.y > item->getBounds().brLoc.y) {
                        return item;
                }
        }
        return nullptr;
};
