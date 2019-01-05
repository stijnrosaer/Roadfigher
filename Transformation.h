//
// Created by stijn on 15/11/18.
//

#ifndef PROJECTGP_TRANSFORMATION_H
#define PROJECTGP_TRANSFORMATION_H

#include "Singleton.h"

struct location
{
        double x;
        double y;
};

class Transformation : public Singleton<Transformation>
{
private:
        /**
         * constructor voor Transformation
         */
        Transformation() = default;

public:
        /**
         * zet een coordinaat om naar locatie in window
         * @param co coordinaat
         * @param width breedte van de window
         * @param height hoogte van de window
         * @return retrn omgezet coordinaat
         */
        location to2DWorldSpace(const location& co, float width, float height);
        /**
         * zet een coordinaat om naar locatie in assenstalser 3/4
         * @param co coordinaat
         * @param width breedte van de window
         * @param height hoogte van de window
         * @return retrn omgezet coordinaat
         */
        location toPixelSpace(const location& co, float width, float height);
};

#endif // PROJECTGP_TRANSFORMATION_H
