//
// Created by stijn on 3/01/19.
//

#include "../rf/Observable.h"

void Observable::addObserver(std::shared_ptr <Observer> observer) {
    this->observers.push_back(observer);
}

void Observable::removeAllObserver(){
    observers.clear();
}

void Observable::callObserver(action act) {
    for(std::shared_ptr<Observer> &(item) : observers){
        item->react(act);
    }
}

Observable::~Observable() {
    removeAllObserver();

}
