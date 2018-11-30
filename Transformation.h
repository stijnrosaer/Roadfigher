//
// Created by stijn on 15/11/18.
//

#ifndef PROJECTGP_TRANSFORMATION_H
#define PROJECTGP_TRANSFORMATION_H

#include <memory>

class Transformation {
private:

    static std::shared_ptr<Transformation> trans;

public:
    virtual ~Transformation();
    static std::shared_ptr<Transformation> Instance();
    std::pair<float, float> transformTo2DWorldSpace(const std::pair<float, float> & co, float width, float height);
};


#endif //PROJECTGP_TRANSFORMATION_H
