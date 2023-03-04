#include <iostream>
#include <string>
#include "../Headers/Operators.h"

// Function that returns if a character is a Operators
bool Operators(char c) {
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':
    case '<':
    case '>':
    case '!':
      return 1;
    default:
      return 0;
  }
}