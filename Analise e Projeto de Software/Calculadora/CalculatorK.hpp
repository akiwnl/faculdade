#pragma once
#include "Interface.hpp"

class CalculatorK: public Calculator{
  Keyboard* keyboard;
  Cpu* cpu;
  Display* display;

  public: 
void setDisplay(Display* );
Display* getDisplay(); 
void setCpu(Cpu* );
Cpu* getCpu();
void setKeyboard(Keyboard* );
Keyboard* getKeyboard();
};