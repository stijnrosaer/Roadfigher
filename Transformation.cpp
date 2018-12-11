//
// Created by stijn on 15/11/18.
//

#include "Transformation.h"

std::pair<float, float> Transformation::transformTo2DWorldSpace(const std::pair<float, float> &co, float width, float height) {
    float x_n = (width/8)*(co.first+4);
    float y_n = -(height/6)*(co.second-3);

    return {x_n, y_n};
}
