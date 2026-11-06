#include "io.h"
#include <iostream>
StubIO::StubIO(Coords input) {
    inputs = std::move(input);
}
Coord StubIO::read() {
    if(nextInput >= inputs.size()) {
        return {-1, -1};
    }
    return inputs[nextInput++]; 

}
void StubIO::write(std::string txt) {
    std::cout << txt; 
}
