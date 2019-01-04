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
        virtual ~Observable();

        void addObserver(std::shared_ptr<Observer> observer);
        void callObserver(action act);
        void removeAllObserver();
};

#endif // PROJECTGP_OBSERVABLE_H
