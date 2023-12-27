#include "KeyboardK.hpp"
#include "cstring"

void KeyboardK::addKey(Key *key) {

  for(int i = 0; i < this->keysCount; i++)
    if(this->keys[i]==key) throw "Repeated key!";

  this->keys[this->keysCount++] = key;
  key->setKeyboard(this);
}

void KeyboardK::removeKey(Key *) {
}


Key *KeyboardK::findKey(Symbol symbol) {
  for (char i = 0; i < this->keysCount; i++)
    if (strcmp(symbol,this->keys[i]->getSymbol()))
      return this->keys[i];

  throw "Key not found!";
}

void KeyboardK::setCpu(Cpu *cpu) { this->cpu = cpu; }

Cpu *KeyboardK::getCpu() { return this->cpu; }
