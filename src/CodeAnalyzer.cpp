#include <iostream>
#include <fstream>
#include <vector>

#include "Headers/CodeAnalyzer.h"

// Functions for checking characters
#include "Headers/Characters.h"
#include "Headers/Digits.h"
#include "Headers/Keywords.h"
#include "Headers/Operators.h"
#include "Headers/Separators.h"
#include "Headers/Whitespace.h"

using namespace std;

// Tracks the data and what type it is
class item {
public:
  string value = "";
  string type = "";
};

// Function that goes through the code given
void CodeAnalyzer(ifstream& code) {
  string str;
  char ch;
  bool isQoute = false;

  // Initalizing class
  item currentItem;

  // Goes through the file one letter at a time
  while (code.get(ch)) {
    if (ch == '"') {
			if (isQoute == true) {
				isQoute = false;
				cout << "String "<< str << ch << endl;
				str = "";
			}
			else {
				isQoute = true;
			}
		}
		if (isQoute == true) {
			str += ch;
			continue;
		}
		
    
    // Checks if current character is a space
    if (ch == ' ') {
      // If value is not empty it will print the last item and empty it
      if (currentItem.value != "") {
        cout << currentItem.type << " " << currentItem.value << endl;
        currentItem.value = "";
      }
      continue;
    }

    // Checks if current character is a separator
    if (Separators(ch)) {
      // Checks if current character belongs to previous value
      if (currentItem.value != "") {
        cout << currentItem.type << " " << currentItem.value << endl;
      }

      // Sets the value to the current seperator and the type to 'Seperators'
      currentItem.value = ch;
      currentItem.type = "Separators";
      continue;
    }

    // Checks if current character is a operator
    if (Operators(ch)) {
      // Checks if current character belongs to previous value
      if (currentItem.value != "" && currentItem.type != "Operators") {
        cout << currentItem.type << " " << currentItem.value << endl;
      }

      // Sets the value to the current seperator and the type to 'Operators'
      currentItem.value += ch;
      currentItem.type = "Operators";
      continue;
    }

    // Checks if the current character is a letter or a digit
    if (Characters(ch)) {
      // Checks if current character belongs to previous value
      if (currentItem.value != "" && currentItem.type != "Identifier") {
        if(currentItem.type != "Keyword") {
          cout << currentItem.type << " " << currentItem.value << endl;
          currentItem.value = "";
        }
      }
      
      // By default sets the value to the character and type to Identifier
      currentItem.value += ch;
      currentItem.type = "Identifier";

      // Checks if the curent value is a keyword and set teh type of keywords
      if (Keywords(currentItem.value)) {
				currentItem.type = "Keyword";
        continue;
      }

      continue;
    }

    // Checks if current character is a Digit
    if (Digits(ch) || ch == '.') {
      // Checks if current character belongs to previous value
      if (currentItem.value != "" && currentItem.type != "Real") {
        if (currentItem.type != "Identifier") {
          cout << currentItem.type << " " << currentItem.value << endl;
        }
      }

      // Sets the value to the current seperator and the type to 'Operators'
      currentItem.value += ch;
      // Checks if current type is Identifier and keeps it as one other wise changes it to Real
      if (currentItem.type == "Identifier") {
        currentItem.type = "Identifier";
      } else {
        currentItem.type = "Real"; 
      }
      
      continue;
    }
  };

  // Prints the last item
  cout << currentItem.type << " " << currentItem.value << endl;

  // return 0;
}