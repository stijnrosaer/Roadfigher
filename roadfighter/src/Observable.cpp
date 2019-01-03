//
// Created by stijn on 3/01/19.
//

#include "../rf/Observable.h"

void Observable::addObserver(std::shared_ptr <Observer> observer) {
    this->observers.push_back(observer);
}

void Observable::callObserver(action act, Observable& caller) {
    for(auto &item : observers){
        item->react(act);
    }

}