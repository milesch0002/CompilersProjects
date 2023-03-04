#include <iostream>
#include <string>

#include "Characters.h"

// Function that returns if a character is a letter
bool Characters(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}