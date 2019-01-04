#include "Game.h"
#include "Transformation.h"
#include <iostream>

using namespace std;

int main()
{
        auto g = make_shared<Game>();
        g->run();

        return 0;
}
