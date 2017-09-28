#include <iostream>
#include <string>
using namespace std;

Age::Age(string age) : _age{age} {}

string Age::to_string() {
  return _age;
}
