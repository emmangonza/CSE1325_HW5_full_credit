#include <iostream>
#include "publication.h"
using namespace std;

Publication::Publication(std::string title, std::string author, std::string copyright,
  Genre genre, Media media, Age target_age, std::string isbn) : _title{title},
  _author{author}, _copyright{copyright}, _genre{genre}, _media{media},
  _target_age{target_age}, _isbn{isbn} {}

void Publication::check_out(std::string patron_name, std::string patron_phone) {
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

std::string Publication::to_string() {
  return "\"" + _title + "\" by " + _author + ", " + _copyright + " (" +
          _target_age.to_string(); + " " + _media.to_string(); + " " +
          _genre.to_string(); + ") ISBN: " + _isbn + "\nChecked out to " +
          _patron_name + " (" + _patron_phone + ")";
}
