
#include "CalculatorK.hpp"


void CalculatorK::setDisplay(Display* display){
  this->display = display;

if(this->cpu!=nullptr) this->cpu->setDisplay(display);
  }
Display* CalculatorK::getDisplay(){
  return this->display;
  } 
void CalculatorK::setCpu(Cpu* cpu){
  this->cpu = cpu;

  }
Cpu* CalculatorK::getCpu(){
  return cpu;
  }
void CalculatorK::setKeyboard(Keyboard* keyboard){
  this->keyboard = keyboard;

}
Keyboard* CalculatorK::getKeyboard(){
  return keyboard;
  }
