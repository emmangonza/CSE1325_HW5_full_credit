#include "library.h"
#include "publication.h"
#include "enums.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  Library library;

  int cmd = -1;
  while (cmd != 0) {
    cout << endl << endl;
    cout << "=================================" << endl;
    cout << "CSE1325 Library Management System" << endl;
    cout << "=================================" << endl;
    cout << endl;
    cout << "Publications" << endl;
    cout << "------------" << endl;
    cout << "(1) Add publication" << endl;
    cout << "(2) List all publications" << endl;
    cout << "(3) Check out publication" << endl;
    cout << "(4) Check in publication" << endl;
    cout << endl;
    cout << "Utility" << endl;
    cout << "-------" << endl;
    cout << "(9) Help" << endl;
    cout << "(0) Exit" << endl;
    cout << endl;

    cout << "Command? ";
    cin >> cmd;
    cin.ignore();


    if (cmd == 1) {
      string title, author, copyright, isbn;
      int temp;
      Genre genre;
      Media media;
      Age age;

      cout << "Title? ";
      getline(cin, title);

      cout << "Author? ";
      getline(cin, author);

      cout << "Copyright date? ";
      getline(cin, copyright);

      for (int i = 0; i < genres.size(); ++i)
        cout << "  " << i << ") " << genres[i] << endl;
      cout << "Genre? ";
      cin >> temp;
      genre = (Genre) temp;
      cin.ignore();

      for (int i = 0; i < medias.size(); ++i)
        cout << "  " << i << ") " << medias[i] << endl;
      cout << "Media? ";
      cin >> temp;
      media = (Media) temp;
      cin.ignore();

      for (int i = 0; i < ages.size(); ++i)
        cout << "  " << i << ") " << ages[i] << endl;
      cout << "Age? ";
      cin >> temp;
      age = (Age) temp;
      cin.ignore();

      cout << "ISBN? ";
      getline(cin, isbn);

      try {
        library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));
      } catch (Publication::Invalid_transaction e) {
        cerr << "Unable to add" << endl;
      }

   }
   if (cmd >= 2 && cmd <= 4) {
      cout << endl;
      cout << "----------------------------" << endl;
      cout << "List of Library Publications" << endl;
      cout << "----------------------------" << endl;
      for (int i=0; i<library.number_of_publications(); ++i)
        cout << i << ") " << library.publication_to_string(i) << endl;

   }
   if (cmd == 3) {
      int pub;
      string pat;
      string pat_phone;

      cout << "Publication number? ";
      cin >> pub;
      cin.ignore();

      cout << "Patron name? ";
      getline(cin, pat);
      cout << "Patron phone? ";
      getline(cin, pat_phone);

      try {
        library.check_out(pub, pat, pat_phone);
      } catch (Publication::Invalid_transaction e) {
        cerr << "ERROR: That publication is already checked out!" << endl;
      }

   }
   if (cmd == 4) {
      int pub;
      cout << "Publication number? ";
      cin >> pub;
      cin.ignore();

      try {
        library.check_in(pub);
      } catch (Publication::Invalid_transaction e) {
        cerr << "ERROR: That publication is already checked in!" << endl;
      }

   }
   if (cmd == 9) {
      cout << "Try harder." << endl;

   }
   if (cmd == 99) {
     library.easter_egg();
   }
   if (cmd < 0 || (4 < cmd && cmd < 9) || (9 < cmd && cmd < 99) || (99 < cmd)) { // Invalid command
     cerr << "**** Invalid command - type 9 for help" << endl << endl;
   }
  }
}
