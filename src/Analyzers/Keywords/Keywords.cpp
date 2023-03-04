#include <iostream>
#include <string>
#include "Keywords.h"

// Function that returns if a character is a keyword
bool Keywords(std::string str) {
  if (str == "if" ||
    str == "else" ||
    str == "while" ||
    str == "do" ||
    str == "for" ||
    str == "switch" ||
    str == "case" ||
    str == "break" ||
    str == "continue" ||
    str == "return" ||
    str == "cout" ||
    str == "endl" ||
    // not sure if these should be here
    str == "int" ||
    str == "string" ||
    str == "bool" ||
    str == "char" ||
    str == "double") {
    return 1;
  } else {
    return 0;
  }
}