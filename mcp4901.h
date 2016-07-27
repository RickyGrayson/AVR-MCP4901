#ifndef DRUM_MACHINE_MCP4901_H
#define DRUM_MACHINE_MCP4901_H

#include <avr/io.h>

namespace MCP4901 {
    void initialize(volatile uint8_t *ssPort, uint8_t ssPin);
    void write(uint8_t output);
    void setVrefBuffer(bool buffer);
    void set2xGain(bool gain);
    void setShutDown(bool shutDown);
}

#endif