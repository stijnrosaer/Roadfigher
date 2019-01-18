//
// Created by stijn on 3/01/19.
//

#ifndef PROJECTGP_OBSERVER_H
#define PROJECTGP_OBSERVER_H

#include <iostream>
#include <memory>

enum action
{
        shoot,
        hitByBullet,
        pointsCar,
        playerRespawn,
        mv
};

class Observer : public std::enable_shared_from_this<Observer>
{
public:
        /**
         * voer actie uit
         * @param act uit te voeren actie
         */
        virtual void react(action act) = 0;
};

#endif // PROJECTGP_OBSERVER_H
