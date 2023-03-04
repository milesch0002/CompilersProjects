#include <iostream>
#include <string>
#include "Separators.h"

// Function that returns if a character is a separtors
bool Separators(char c) {
  if (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',' || c == ':') {
    return 1;
  } else {
    return 0;
  }
}