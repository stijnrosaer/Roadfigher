#include <iostream>
#include "Transformation.h"
#include "Game.h"

using namespace std;

int main(){
    auto g = make_shared<Game>() ;
    g->run();

    return 0;
}
