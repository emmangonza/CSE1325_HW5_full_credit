#include <iostream>
#include <string>
using namespace std;

Genre::Genre(string genre) : _genre{genre} {}

string Genre::to_string() {
  return _genre;
}
