#pragma once

#include "Interface.hpp"


class BufferDigits{
  private:
  Digit digits[8];

  int digitsCount = 0;

  int decimalSeparator = 0;

  public:
    void addDigit(Digit);
    void setDecimalSeparator();
    float toFloat(Digit*);
    int size();
    bool isEmpty();
    int convertDigitToInt(Digit);
    Digit convertIntToDigit(int);
    void fromFloat(float);
    void show(Display*);
};

class CpuK: public Cpu{
  private:
    Display* display;
    Operator* currentOperator = nullptr;


    BufferDigits operando1;
    BufferDigits operando2;
    float operate(float val1, float val2);



  public:
    Display* getDisplay();
    void setDisplay(Display*);

    void receiveDigit(Digit);
    void receiveOperator(Operator);
    void receiveControl(Control);
};