#include "library.h"
#include "publication.h"
#include "enums.h"
#include "dialogs.h"

#include <iostream>
#include <vector>
#include <string>
#include <gtkmm.h>

using namespace std;

int main(int argc, char *argv[]) {

  Gtk::Main kit(argc, argv);

  Library library;

  string cmd_str = "";
  int cmd_num = -1;
  while (cmd_num != 0) {
    string menu, win_title;
    menu = "=================================\n"
           "CSE1325 Library Management System\n"
           "=================================\n\n"
           "Publications\n"
           "------------\n"
           "(1) Add publication\n"
           "(2) List all publications\n"
           "(3) Check out publication\n"
           "(4) Check in publication\n\n"
           "Utility\n"
           "-------\n"
           "(9) Help\n"
           "(0) Exit\n\n";

    win_title = "Main menu";

    cmd_str = Dialogs::input(menu, win_title);
    if (cmd_str == "CANCEL") break;

    cmd_num = atoi(cmd_str.c_str());


    if (cmd_num == 1) {
      string book_title, author, copyright, isbn, temp_str, msg;
      int temp_num;
      Genre genre;
      Media media;
      Age age;

      book_title = Dialogs::input("Title?", "Input");
      if (book_title == "CANCEL") break;

      author = Dialogs::input("Author?", "Input");
      if (author == "CANCEL") break;

      copyright = Dialogs::input("Copyright date?", "Imsg = ""nput");
      if (copyright == "CANCEL") break;


      msg = "";
      for (int i = 0; i < genres.size(); ++i)
         msg += "  " + to_string(i) + ") " + genres[i] + "\n";

      temp_str = Dialogs::input(msg, "Select a Genre");
      if (temp_str == "CANCEL") break;

      temp_num = atoi(temp_str.c_str());

      genre = (Genre) temp_num;


      msg = "";
      for (int i = 0; i < medias.size(); ++i)
        msg += "  " + to_string(i) + ") " + medias[i] + "\n";

      temp_str = Dialogs::input(msg, "Select a Media");
      if (temp_str == "CANCEL") break;

      temp_num = atoi(temp_str.c_str());

      media = (Media) temp_num;


      msg = "";
      for (int i = 0; i < ages.size(); ++i)
        msg += "  " + to_string(i) + ") " + ages[i] + "\n";

      temp_str = Dialogs::input(msg, "Select a Target Age");
      if (temp_str == "CANCEL") break;

      temp_num = atoi(temp_str.c_str());

      age = (Age) temp_num;

      // cout << "ISBN? ";
      // getline(cin, isbn);

  //     try {
  //       library.add_publication(Publication(book_title, author, copyright, genre, media, age, isbn));
  //     } catch (Publication::Invalid_transaction e) {
  //       cerr << "Unable to add" << endl;
  //     }
  //
  }
  //  if (cmd_num >= 2 && cmd_num <= 4) {
  //     cout << endl;
  //     cout << "----------------------------" << endl;
  //     cout << "List of Library Publications" << endl;
  //     cout << "----------------------------" << endl;
  //     for (int i=0; i<library.number_of_publications(); ++i)
  //       cout << i << ") " << library.publication_to_string(i) << endl;
  //
  //  }
  //  if (cmd_num == 3) {
  //     int pub;
  //     string pat;
  //     string pat_phone;
  //
  //     cout << "Publication number? ";
  //     cin >> pub;
  //     cin.ignore();
  //
  //     cout << "Patron name? ";
  //     getline(cin, pat);
  //     cout << "Patron phone? ";
  //     getline(cin, pat_phone);
  //
  //     try {
  //       library.check_out(pub, pat, pat_phone);
  //     } catch (Publication::Invalid_transaction e) {
  //       cerr << "ERROR: That publication is already checked out!" << endl;
  //     }
  //
  //  }
  //  if (cmd_num == 4) {
  //     int pub;
  //     cout << "Publication number? ";
  //     cin >> pub;
  //     cin.ignore();
  //
  //     try {
  //       library.check_in(pub);
  //     } catch (Publication::Invalid_transaction e) {
  //       cerr << "ERROR: That publication is already checked in!" << endl;
  //     }
  //
  //  }
  //  if (cmd_num == 9) {
  //     cout << "Try harder." << endl;
  //
  //  }
  //  if (cmd_num == 99) {
  //    library.easter_egg();
  //  }
  //  if (cmd_num < 0 || (4 < cmd_num && cmd_num < 9) || (9 < cmd_num && cmd_num < 99) || (99 < cmd_num)) { // Invalid command
  //    cerr << "**** Invalid command - type 9 for help" << endl << endl;
  //  }
  }
  return EXIT_SUCCESS;
}
