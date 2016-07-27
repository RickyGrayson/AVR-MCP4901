#AVR MCP4901

MCP4901 DAC functions for AVR platform

#Examples

void initialize(&PORTb, 2); //Sets Slave Select pin to PB2

void write(127); //writes 127 to DAC

void setVrefBuffer(true); //sets Vref Buffer, initializes to false, please refer to MCP4901 datasheet

void set2xGain(false); //sets 2x gain, initializes to false(1x gain), please refer to MCP4901 datasheet

void setShutDown(false); //activates or shutsdown DAC output, initializes to false

#Future updates
* Finalize class versus namespace decision, currently a namespace
* Expand supported devices to relared DACs
* Implement LDAC support
