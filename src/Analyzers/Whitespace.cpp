#include <iostream>
#include <string>
#include "../Headers/Whitespace.h"

// Function that returns if a character is a whitespace
bool Whitespace(char c) {
  return (c == ' ' || c == '\t' || c== '\n');
}