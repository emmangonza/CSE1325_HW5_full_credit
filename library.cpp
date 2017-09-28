#include <iostream>
#include "library.h"
#include <vector>
#include <string>
using namespace std;

void Library::add_publication(Publication pub) {
  publications.push_back(pub);
}

void Library::check_out(int publication_index, string patron_name, string patron_phone) {
  publications[publication_index].check_out(patron_name, patron_phone);
}

void Library::check_in(int publication_index) {
  publications[publication_index].check_in();
}

string Library::publication_to_string(int publication_index) {
  publications[publication_index].to_string();
}

int number_of_publications() {
  return publications.size();
}
