//
// Created by stijn on 15/11/18.
//

#ifndef PROJECTGP_TRANSFORMATION_H
#define PROJECTGP_TRANSFORMATION_H


struct coordinate{
    float x;
    float y;

    coordinate(float x_co, float y_co){
        x = x_co;
        y = y_co;
    }
};

class Transformation {
private:

    static Transformation* trans;

public:
    virtual ~Transformation();
    static Transformation* Instance();
    coordinate transformTo2DWorldSpace(coordinate & co, float width, float height);

protected:
    Transformation();

};


#endif //PROJECTGP_TRANSFORMATION_H
