#include "io.h"
#include <iostream>
Coord RealIO::read()
{
        int x{}, y{};
        std::cin >> x >> y; 
        return {x, y}; 
}
void RealIO::write(const std::string& txt) {
        std::cout << txt; 
}
