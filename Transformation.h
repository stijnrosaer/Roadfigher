//
// Created by stijn on 15/11/18.
//

#ifndef PROJECTGP_TRANSFORMATION_H
#define PROJECTGP_TRANSFORMATION_H

#include "Singleton.h"

struct location{
    double x;
    double y;
};


class Transformation : public Singleton<Transformation> {
private:
    Transformation() = default;;

public:
    location to2DWorldSpace(const location &co, float width, float height);
    location toPixelSpace(const location &co, float width, float height);
};

#endif //PROJECTGP_TRANSFORMATION_H
