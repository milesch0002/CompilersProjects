#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream file("testCases/test1.txt");

    string str;

    while (getline(file, str)) {
        cout << str;
    }

    return 0;
}