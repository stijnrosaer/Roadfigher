//
// Created by stijn on 29/12/18.
//

#ifndef PROJECTGP_OBSERVABLE_H
#define PROJECTGP_OBSERVABLE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Observer.h"

class Observable {
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addObserver(std::shared_ptr<Observer> observer);
    void callObserver(action act, Observable& caller);
};


#endif //PROJECTGP_OBSERVABLE_H
