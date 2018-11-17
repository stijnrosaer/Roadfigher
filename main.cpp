#include <iostream>
#include "Transformation.h"
#include "Game.h"

using namespace std;

int main(){
    Game g;
    g.run();


    coordinate a(3,-1);
    coordinate b = Transformation::Instance()->transformTo2DWorldSpace(a, 40, 30);

    return 0;
}
