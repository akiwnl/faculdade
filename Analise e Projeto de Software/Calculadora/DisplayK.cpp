#include "DisplayK.hpp"
#include "Console.hpp"

#include <iostream>
#include <string>

std::string symbols[][5] = { 
  {"████", "█  █", "█  █" , "█  █" , "████"},
  {"   █", "   █", "   █" , "   █" , "   █"},
  {"████", "   █", "████" , "█   " , "████"},
  {"████", "   █", " ███" , "   █" , "████"},
  {"█  █", "█  █", "████" , "   █" , "   █"},
  {"████", "█   ", "████" , "   █" , "████"},
  {"████", "█   ", "████" , "█  █" , "████"},
  {"████", "   █", "   █" , "   █" , "   █"},
  {"████", "█  █", "████" , "█  █" , "████"},
  {"████", "█  █", "████" , "   █" , "████"}
};

void DisplayK::add(Digit digit){
  this->digits[this->digitsCount++] = digit;
  this->show();
}

void DisplayK::setDecimalSeparator(){
  if(this->decimalSeparatorPosition == 0)
    this->decimalSeparatorPosition = this->digitsCount; 
}

void DisplayK::clear(){
  this->digitsCount = 0;
  this->decimalSeparatorPosition = 0;
  this->show();
}

void DisplayK::show(){
  Console::setColor(Color::BG_Green);  
  Console::setColor(Color::FG_Blue);  
  Console::clearScreen();

  for(int i= 0; i< this->digitsCount; i++){ 
    switch(this->digits[i]){
      case ZERO: this->showDigit(0, 1, i+1); break;
      case ONE: this->showDigit(1, 1, i+1); break;
      case TWO: this->showDigit(2, 1, i+1); break;
      case THREE: this->showDigit(3, 1, i+1); break;
      case FOUR: this->showDigit(4, 1, i+1); break;
      case FIVE: this->showDigit(5, 1, i+1); break;
      case SIX: this->showDigit(6, 1, i+1); break;
      case SEVEN: this->showDigit(7, 1, i+1); break;
      case EIGHT: this->showDigit(8, 1, i+1); break;
      case NINE: this->showDigit(9, 1, i+1); break;
      default:
       this->error = true; break;
   }
  }

  this->showControls(1, 0);
}

void DisplayK::showControls(int row, int col){

  Console::setCursor(row, col*6);   std::cout << "▐▚▞▌";

  Console::setCursor(row+1, col*6); std::cout << "▂▂▂▂";

  Console::setCursor(row+2, col*6); std::cout << "╔══";
  Console::setCursor(row+3, col*6); std::cout << "╠══";
  Console::setCursor(row+4, col*6); std::cout << "╚══";
}

void DisplayK::showDigit(int digitIndex, int row, int col){
  for(int i = 0; i < 5; i++){
    Console::setCursor(row+i, col*6);
    std::cout << symbols[digitIndex][i];  
  }
  if(this->decimalSeparatorPosition == col){
   std::cout << "▗";  
  } 
 }

void DisplayK::setMemory(bool enable){ 
    this->memory = enable;
  }

void DisplayK::setNegative(bool enable){ 
    this->negative =  enable;
  }

void DisplayK::setError(bool enable){ 
    this->error = enable;
  }

