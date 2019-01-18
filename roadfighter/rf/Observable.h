//
// Created by stijn on 29/12/18.
//

#ifndef PROJECTGP_OBSERVABLE_H
#define PROJECTGP_OBSERVABLE_H

#include "Observer.h"
#include <iostream>
#include <memory>
#include <vector>

class Observable
{
        std::vector<std::shared_ptr<Observer>> observers;

public:
        /**
         * destructor van observable
         */
        virtual ~Observable();
        /**
         * voeg een observer toe aan observers
         * @param observer toe te voegen observer
         */
        void addObserver(std::shared_ptr<Observer> observer);
        /**
         * roep alle observers aan om een actie uit te voeren
         * @param act uit te voeren actie
         */
        void callObserver(action act);
        /**
         * verwijder alle observers uit observers
         */
        void removeAllObserver();
};

#endif // PROJECTGP_OBSERVABLE_H
