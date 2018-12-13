//
// Created by stijn on 10/12/18.
//

#ifndef PROJECTGP_SINGLETON_H
#define PROJECTGP_SINGLETON_H

#include <memory>
#include <iostream>

/// information at: https://stackoverflow.com/questions/41328038/singleton-template-as-base-class-in-c

template <typename T>
class Singleton {
protected:
    Singleton() = default;
    ~Singleton() = default;

public:
    static std::shared_ptr<T> getInstance(){
        static std::shared_ptr<T> instance;
        return instance;
    }

    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
};

#endif //PROJECTGP_SINGLETON_H
