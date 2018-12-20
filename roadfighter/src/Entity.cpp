//
// Created by stijn on 16/11/18.
//

#include "../rf/Entity.h"


roadfighter::Entity::Entity() = default;

roadfighter::Entity::~Entity(){
}

roadfighter::Entity::boundaries roadfighter::Entity::getBounds() {
    return this->bounds;
}

bool roadfighter::Entity::collision(vector<shared_ptr<roadfighter::Entity>> entities) {
    bool collision = false;
    for (auto &item : entities){
        // top left collides
        if (this->bounds.tlLoc.first > item->getBounds().tlLoc.first &&
            this->bounds.tlLoc.first < item->getBounds().brLoc.first &&
            this->bounds.tlLoc.second < item->getBounds().tlLoc.second &&
            this->bounds.tlLoc.second > item->getBounds().brLoc.second){
            collision = true;

            //bottom right collides;
        } else if(this->bounds.brLoc.first > item->getBounds().tlLoc.first &&
                  this->bounds.brLoc.first < item->getBounds().brLoc.first &&
                  this->bounds.brLoc.second < item->getBounds().tlLoc.second &&
                  this->bounds.brLoc.second > item->getBounds().brLoc.second){
            collision = true;

            //top right collides
        }else if(this->bounds.brLoc.first > item->getBounds().tlLoc.first &&
                 this->bounds.brLoc.first < item->getBounds().brLoc.first &&
                 this->bounds.tlLoc.second < item->getBounds().tlLoc.second &&
                 this->bounds.tlLoc.second > item->getBounds().brLoc.second) {
            collision = true;

            //bottom left collides
        }else if(this->bounds.tlLoc.first > item->getBounds().tlLoc.first &&
                 this->bounds.tlLoc.first < item->getBounds().brLoc.first &&
                 this->bounds.brLoc.second < item->getBounds().tlLoc.second &&
                 this->bounds.brLoc.second > item->getBounds().brLoc.second) {
            collision = true;
        }
    }

    return collision;

};

