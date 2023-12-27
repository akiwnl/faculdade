#include "CalculatorTests.hpp"

#include "CpuK.hpp"
#include "DisplayK.hpp"
#include "KeyK.hpp"
#include "KeyboardK.hpp"

#include <iostream>

int main() {

  Display *display1 = new DisplayK();

  Cpu *cpu1 = new CpuK();

  // Key *keyOne = new KeyDigitK("1", Digit::ONE);
  // Key *keyOperator = new KeyOperatorK("+", Operator::SUM);
  // Key *keyControl = new KeyControlK("=", Control::EQUAL);

  Keyboard *keyboard1 = new KeyboardK();

  cpu1->setDisplay(display1);
  keyboard1->setCpu(cpu1);

  // keyboard1->addKey(keyOne);
  // keyboard1->addKey(keyOperator);
  // keyboard1->addKey(keyControl);

  // /* Testing... */
  try {
    CalculatorTests::testCpu(cpu1, display1);
  } catch (const char *bolinha) {
    std::cout << bolinha;
  }

  // CalculatorTests::pause();
  // CalculatorTests::setPauseAfterTests(true);

  // CalculatorTests::testDisplay(display1);
  // CalculatorTests::testKeyboard(keyboard1);
}