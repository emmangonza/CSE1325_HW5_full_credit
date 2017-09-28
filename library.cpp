#include <iostream>
#include <vector>
#include <string>
#include "library.h"
#include "publication.h"
using namespace std;

void Library::add_publication(Publication pub) {
  string title, author, copyright, genre, media, age, isbn;

  cout << "Enter the title: ";
  getline(cin, title);
  cout << "Enter the author: ";
  getline(cin, author);
  cout << "Enter the copyright year: ";
  getline(cin, copyright);
  cout << "Enter the genre(book, periodical, newspaper, audio, video): ";
  getline(cin, genre);
  cout << "Enter the media(fiction, non-fiction, self-help, performance): ";
  getline(cin, media);
  cout << "Enter the target age(children, teen, adult, restricted): ";
  getline(cin, age);
  cout << "Enter the isbn number: ";
  getline(cin, isbn);

  Genre pub_genre(genre);
  Media pub_media(media);
  Age pub_age(age);

  pub(title, author, copyright, pub_genre, pub_media, pub_age, isbn);

  publications.push_back(pub);
}

void Library::check_out(int publication_index, string patron_name, string patron_phone) {
  publications[publication_index].check_out(patron_name, patron_phone);
}

void Library::check_in(int publication_index) {
  publications[publication_index].check_in();
}

string Library::publication_to_string(int publication_index) {
  return publications[publication_index].to_string();
}

int number_of_publications() {
  return publications.size();
}
