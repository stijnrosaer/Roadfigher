//
// Created by stijn on 10/12/18.
//

#ifndef PROJECTGP_SINGLETON_H
#define PROJECTGP_SINGLETON_H

#include <memory>
#include <iostream>

/// information at: https://r3dux.org/2011/07/how-to-convert-any-class-to-a-singleton-with-a-template-wrapper-in-c/

template <typename T>
class Singleton {
protected:
    /**
     * constructor voor class template Singleton
     */
    Singleton() = default;
    /**
     * destructor voor Singleton
     */
    ~Singleton() = default;

public:
    /**
     * opvragen van unieke instance
     * @return instance
     */
    static std::shared_ptr<T> getInstance(){
        static std::shared_ptr<T> instance;
        return instance;
    }

    /**
     * vookom copy constructor
     */
    Singleton(Singleton const&) = delete;
    /**
     * voorkom asignment operator overloading
     * @return
     */
    Singleton& operator=(Singleton const&) = delete;
};

#endif //PROJECTGP_SINGLETON_H
