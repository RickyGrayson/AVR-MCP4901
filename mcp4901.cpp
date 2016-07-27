#include "mcp4901.h"

namespace {
    uint8_t settings;
    volatile uint8_t *port;
    uint8_t pin;
}
void MCP4901::initialize(volatile uint8_t *ssPort, uint8_t ssPin) {
    *(ssPort - 1) |= (1 << ssPin);
    *ssPort |= (1 << ssPin);
    DDRB |= (1 << DDB5) | (1 << DDB3);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    port = ssPort;
    pin = ssPin;
    settings = (1 << 6) | (1 << 5);
}
void MCP4901::write(uint8_t output) {
    static uint16_t previousOutput;
    if (output != previousOutput) {
        uint8_t firstByte = settings | (output >> 4);
        uint8_t secondByte = output << 4;
        *port &= ~(1 << pin);//pull SS down for transfer
        SPDR = firstByte;
        while (!(SPSR & (1 << SPIF)));
        SPDR = secondByte;
        while (!(SPSR & (1 << SPIF)));
        *port |= (1 << pin);
    }
    previousOutput = output;   
}
void MCP4901::setVrefBuffer(bool buffer) {
    settings = buffer ? settings | (1 << 6) : settings & ~(1 << 6);
}
void MCP4901::set2xGain(bool gain) {
    settings = gain ? settings & ~(1 << 5) : settings | (1 << 5);
}
void MCP4901::setShutDown(bool shutdown) {
    settings = shutdown ? settings & ~(1 << 4) : settings | (1 << 4);
}