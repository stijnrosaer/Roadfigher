//
// Created by stijn on 15/11/18.
//

#include "Transformation.h"

Transformation* Transformation::trans = nullptr;

Transformation::Transformation() {}
Transformation::~Transformation() {}

Transformation *Transformation::Instance() {
    if(trans == nullptr){
        trans = new Transformation;
    }
    return trans;
}

coordinate Transformation::transformTo2DWorldSpace(coordinate &co, float width, float height) {
    float x_n = width/8*(co.x+4);
    float y_n = -height/6*(co.y-3);

    return {x_n, y_n};
}
