#include <iostream>
#include <string>
#include <fstream>

#include "src/Headers/CodeAnalyzer.h"

using namespace std;

inline bool exists (const string& name) {
  if (FILE *file = fopen(name.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }   
}

int main() {
  if (exists("testCases/code.txt")) {
    ifstream infile("testCases/code.txt");
    CodeAnalyzer(infile);
  } else {
    ifstream infile("testCases/test1.txt");
    CodeAnalyzer(infile);
    infile.close();
  }

  return 0;
}