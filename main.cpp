#include <iostream>
#include <string>
#include <fstream>

#include "src/CodeAnalyzer.h"

inline bool exists (const std::string& name) {
  if (FILE *file = fopen(name.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }   
}

int main() {
  if (exists("testCases/code.txt")) {
    std::fstream infile("testCases/code.txt");
    CodeAnalyzer(infile);
  } else {
    std::fstream infile("testCases/test1.txt");
    CodeAnalyzer(infile);
  }

  return 0;
}