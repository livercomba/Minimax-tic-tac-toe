#ifndef IO_H 
#define IO_H

#include "types.h"
#include <string>

class ConsoleIO {
public:
    virtual void write(const std::string& txt) = 0;
    virtual Coord read() = 0;
};

class RealIO : public ConsoleIO {
public:
    Coord read() override;  
    void write(const std::string& txt) override;
};

class StubIO : public ConsoleIO {
public:
    Coords inputs;
    std::size_t nextInput = 0;
    StubIO(const Coords& input);
    Coord read() override;
    void write(const std::string& txt) override;
};



#endif
