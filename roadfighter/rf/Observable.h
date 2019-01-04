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
    std::vector<std::weak_ptr<Observer>> observers;

public:
    virtual ~Observable();

    void addObserver(std::weak_ptr<Observer> observer);
    void callObserver(action act);
    void removeAllObserver();
};


#endif //PROJECTGP_OBSERVABLE_H
