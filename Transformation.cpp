//
// Created by stijn on 15/11/18.
//

#include "Transformation.h"

location Transformation::to2DWorldSpace(const location& co, float width, float height)
{
        double x_n = (width / 8) * (co.x + 4);
        double y_n = -(height / 6) * (co.y - 3);

        return {x_n, y_n};
}

location Transformation::toPixelSpace(const location& co, float width, float height)
{
        double x_n = ((co.x * 8) / width) - 4;
        double y_n = -((co.y * 6) / height) + 3;

        return {x_n, y_n};
}
