#include "CpuK.hpp"
#include <math.h>
#include "KeyboardK.hpp"


Display *CpuK::getDisplay() { return this->display; }
void CpuK::setDisplay(Display *display) { this->display = display; }

void CpuK::receiveDigit(Digit digit) {
  if (this->display != nullptr) {
    if (this->operando2.isEmpty() && this->currentOperator != nullptr) {
      this->display->clear();
    }
    this->display->add(digit);
  }
  if (this->currentOperator != nullptr) {
    this->operando2.addDigit(digit);
  } else {
    this->operando1.addDigit(digit);
  }
}
void CpuK::receiveOperator(Operator operator_) {
  this->currentOperator = &operator_;
}
void CpuK::receiveControl(Control control) {
  switch (control) {
  case Control::EQUAL:
    // // pega primeiro numero
    // float val1 = this->operando1.toFloat();
    // // pega segundo numero
    // float val2 = this->operando2.toFloat();
    // // calcula o resultado
    // float result = operate(val1, val2);
    // // transforma de volta para digit
    // this->operando1.fromFloat(result);
    // // display clear
    // this->display->clear();
    // // exibe o resultado
    // // for (int i = 0; i < this->operando1.size(); i++) {
    // // }
    break;

  case Control::ON:

    break;

  case Control::OFF:

    break;

  case Control::CLEAR_ERROR:
    break;

  case Control::MEMORY_READ_CLEAR:
    break;

  case Control::MEMORY_SUM:
    break;

  case Control::MEMORY_SUBTRACTION:
    break;

  case Control::DECIMAL_SEPARATOR:
    if (this->currentOperator != nullptr) {
      this->operando2.setDecimalSeparator();
    } else {
      this->operando1.setDecimalSeparator();
    }
    break;

  default:
    throw "Controle nao implementado ainda.";
    break;
  }
}

void BufferDigits::addDigit(Digit digit) {
  this->digits[this->digitsCount++] = digit;
}

int BufferDigits::size() { return this->digitsCount; }

bool BufferDigits::isEmpty() { return this->digitsCount == 0; }

void BufferDigits::setDecimalSeparator() {
  this->decimalSeparator = this->digitsCount;
}

int BufferDigits::convertDigitToInt(Digit digit) {
  switch (digit) {
  case ZERO:
    return 0;
  case ONE:
    return 1;
  case TWO:
    return 2;
  case THREE:
    return 3;
  case FOUR:
    return 4;
  case FIVE:
    return 5;
  case SIX:
    return 6;
  case SEVEN:
    return 7;
  case EIGHT:
    return 8;
  case NINE:
    return 9;
  }

}

Digit BufferDigits::convertIntToDigit(int digit) {
  switch (digit) {
    case 0:
    return ZERO;
    case 1: 
    return ONE;
    case 2:
    return TWO;
    case 3:
    return THREE;
    case 4:
    return FOUR;
    case 5:
    return FIVE;
    case 6:
    return SIX;
    case 7:
    return SEVEN;
    case 8:
    return EIGHT;
    case 9:
    return NINE;
    default:
    throw "digito invalido";
  }
}

float BufferDigits::toFloat(Digit* digits) {
  float result = 0;
  for (int i = 0; i < digitsCount; i++) {
    result = (result * 10) + convertDigitToInt(*(digits+i));
  }
    return result;
}

void BufferDigits::fromFloat(float value_) {
  // this->digitsCount = 0;
  // int value = value_;
  // while (value > 0) {
  //   this->digits[this->digitsCount++] = this->convertIntToDigit(value % 10);
  // }
  // for (int i = 0; i < digitsCount / 2; i++) {
  //   Digit temp = this->digits[i];
  //   digits[i] = digits[digitsCount - 1 - i];
  //   digits[digitsCount - 1 - i] = temp;
  // }

  this->digitsCount = 0;
  float resultado = value_;
  Digit temporary;
  int temp = value_;
  int decTemp = 0;

  for (int i = 0; 1; i++){
    if(resultado - temp == 0){
      break;
    }else{
      resultado *= 10;
      temp = resultado;
      decTemp++;
    }
  }

  while(temp > 0){
    this->digits[this->digitsCount++] = this->convertIntToDigit(temp % 10);
    temp /= 10;
  }
  for(int i = 0; this->digitsCount / 2; i++){
    temporary = this->digits[i];
    this->digits[i] = this->digits[this->digitsCount - 1 - i];
    this->digits[this->digitsCount - 1 - i] = temporary;
  }


}


float CpuK::operate(float val1, float val2) {
  switch (*this->currentOperator) {
  case SUM:
    return val1 + val2;
  default:
    throw "operation not implemented";
  }
}

void BufferDigits::show(Display *display) {}