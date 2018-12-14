//
// Created by stijn on 15/11/18.
//

#ifndef PROJECTGP_TRANSFORMATION_H
#define PROJECTGP_TRANSFORMATION_H

#include "Singleton.h"


class Transformation : public Singleton<Transformation> {
private:
    Transformation() = default;;

public:
    std::pair<float, float> transformTo2DWorldSpace(const std::pair<float, float> & co, float width, float height);
    std::pair<float, float> transformToPixelSpace(const std::pair<float, float> & co, float width, float height);
};

#endif //PROJECTGP_TRANSFORMATION_H
