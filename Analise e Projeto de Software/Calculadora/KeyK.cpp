#include "KeyK.hpp"

KeyBase::KeyBase(Symbol symbol) { this->symbol = symbol; }

Symbol KeyBase::getSymbol() { return this->symbol; }

void KeyBase::setKeyboard(Keyboard *keyboard) { this->keyboard = keyboard; }
Keyboard *KeyBase::getKeyboard() { return this->keyboard; }

KeyDigitK::KeyDigitK(Symbol symbol, Digit digit) : KeyBase(symbol) {
  this->digit = digit;
}

Digit KeyDigitK::getDigit() { return this->digit; }

void KeyDigitK::press() {
  this->getKeyboard()->getCpu()->receiveDigit(this->digit);
}

KeyOperatorK::KeyOperatorK(Symbol symbol, Operator operator_)
    : KeyBase(symbol) {
  this->operator_ = operator_;
}

Operator KeyOperatorK::getOperator() { return this->operator_; }

void KeyOperatorK::press() {
  this->getKeyboard()->getCpu()->receiveOperator(this->operator_);
}

KeyControlK::KeyControlK(Symbol symbol, Control control) : KeyBase(symbol) {
  this->control = control;
}

Control KeyControlK::getControl() { return this->control; }

void KeyControlK::press() {
  this->getKeyboard()->getCpu()->receiveControl(this->control);
}
