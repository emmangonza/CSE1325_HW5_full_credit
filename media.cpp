#include <iostream>
#include <string>
using namespace std;

Media::Media(string media) : _media{media} {}

string Media::to_string() {
  return _media;
}
