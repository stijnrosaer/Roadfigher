//
// Created by stijn on 15/11/18.
//

#include "Transformation.h"

std::pair<float, float> Transformation::to2DWorldSpace(const std::pair<float, float> &co, float width, float height) {
    float x_n = (width/8)*(co.first+4);
    float y_n = -(height/6)*(co.second-3);

    return {x_n, y_n};
}

std::pair<float, float>
Transformation::toPixelSpace(const std::pair<float, float> &co, float width, float height) {
    float x_n = ((co.first*8)/width) - 4;
    float y_n = -((co.second*6)/height) + 3;

    return {x_n, y_n};}
