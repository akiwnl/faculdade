#pragma once

#include "Interface.hpp"

class KeyBase: public virtual Key{
  Keyboard* keyboard;
  Symbol symbol;
  public:
    KeyBase(Symbol);

    Symbol getSymbol();

    void setKeyboard(Keyboard*);
    Keyboard* getKeyboard();
};

class KeyDigitK: public KeyBase, public KeyDigit{
  Digit digit;

  public:
    KeyDigitK(Symbol, Digit);

    Digit getDigit();

    void press();
};


class KeyOperatorK: public KeyBase, public KeyOperator{
  Operator operator_;

  public:
    KeyOperatorK(Symbol, Operator);

    Operator getOperator();

    void press();
};


class KeyControlK: public KeyBase, public KeyControl{
  Control control;

  public:
    KeyControlK(Symbol, Control);

    Control getControl();

    void press();
};