#pragma once

#include "Interface.hpp"

class CalculatorTests{
    static bool pauseAfterTests;
  public:
    static void setPauseAfterTests(bool);
    static void testDisplay(Display*);
    static void testCpu(Cpu*, Display*);
    static void testKeyboard(Keyboard*);
    static void pause();
};