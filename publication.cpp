#include <iostream>
#include <string>
#include "publication.h"
using namespace std;

Publication::Publication(string title, string author, string copyright,
  Genre genre, Media media, Age target_age, string isbn) : _title{title},
  _author{author}, _copyright{copyright}, _genre{genre}, _media{media},
  _target_age{target_age}, _isbn{isbn} {}

void Publication::check_out(string patron_name, string patron_phone) {
  checked_out = true;
  _patron_name = patron_name;
  _patron_phone = patron_phone;
}

void Publication::check_in() {
  check_out = false;
}

bool Publication::is_checked_out() {
  return checked_out;
}

string Publication::to_string() {
  return "\"" + _title + "\" by " + _author + ", " + _copyright + " (" +
          _target_age.to_string(); + " " + _media.to_string(); + " " +
          _genre.to_string(); + ") ISBN: " + _isbn + "\nChecked out to " +
          _patron_name + " (" + _patron_phone + ")";
}
