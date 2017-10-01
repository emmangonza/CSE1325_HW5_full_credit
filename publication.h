#ifndef __PUBLICATION_H
#define __PUBLICATION_H

#include "enums.h"

#include <iostream>
#include <string>

using namespace std;

class Publication {
  public:
    Publication(string title, string author, string copyright,
                Genre genre, Media media, Age target_age, string isbn);
    void check_out(string patron_name, string patron_phone);
    void check_in();
    bool is_checked_out();
    string to_string();

  private:
    string _title;
    string _author;
    string _copyright;
    Genre _genre;
    Media _media;
    Age _target_age;
    string _isbn;
    bool checked_out;
    string _patron_name;
    string _patron_phone;
};
#endif
