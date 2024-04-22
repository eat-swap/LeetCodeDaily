#include "defs.h"
#include <iostream>

int main() {
	std::cout << LC240421::validPath(3, {
            {0, 1},
            {1, 2},
            {2, 0},
    }, 0, 2);
	return 0;
}