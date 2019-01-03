//
// Created by stijn on 3/01/19.
//

#ifndef PROJECTGP_OBSERVER_H
#define PROJECTGP_OBSERVER_H


enum action{
    shoot,
    hitByBullet,
    mv
};

class Observer {
public:
    virtual void react(action act) = 0;

};


#endif //PROJECTGP_OBSERVER_H
