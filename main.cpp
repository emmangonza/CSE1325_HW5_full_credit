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

      book_title = Dialogs::input("Title?");
      if (book_title == "CANCEL") break;

      author = Dialogs::input("Author?");
      if (author == "CANCEL") break;

      copyright = Dialogs::input("Copyright date?");
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


      isbn = Dialogs::input("ISBN?");
      if (isbn == "CANCEL") break;


      try {
        library.add_publication(Publication(book_title, author, copyright, genre, media, age, isbn));
      } catch (Publication::Invalid_transaction e) {
        cerr << "Unable to add" << endl;
      }

  }
   if (cmd_num == 2) {
      string msg = "";

      for (int i=0; i<library.number_of_publications(); ++i)
        msg += to_string(i) + ". " + library.publication_to_string(i) + "\n";

      Dialogs::message(msg, "List of Library Publications");

   }
   if (cmd_num == 3) {
      string pub, pat, pat_phone, msg = "";
      int pub_num;

      for (int i=0; i<library.number_of_publications(); ++i)
        msg += to_string(i) + ". " + library.publication_to_string(i) + "\n";

      pub = Dialogs::input(msg, "Publication number?");
      if (pub == "CANCEL") break;

      pub_num = atoi(pub.c_str());

      pat = Dialogs::input("Patron name?");
      if (pat == "CANCEL") break;

      pat_phone = Dialogs::input("Patron number?");
      if (pat_phone == "CANCEL") break;

      try {
        library.check_out(pub_num, pat, pat_phone);
      } catch (Publication::Invalid_transaction e) {
        cerr << "ERROR: That publication is already checked out!" << endl;
      }

   }
   if (cmd_num == 4) {
      string pub, msg = "";
      int pub_num;

      for (int i=0; i<library.number_of_publications(); ++i)
        msg += to_string(i) + ". " + library.publication_to_string(i) + "\n";

      pub = Dialogs::input(msg, "Publication number?");
      if (pub == "CANCEL") break;

      pub_num = atoi(pub.c_str());

      try {
        library.check_in(pub_num);
      } catch (Publication::Invalid_transaction e) {
        cerr << "ERROR: That publication is already checked in!" << endl;
      }

   }
   if (cmd_num == 9) {
      string msg = R"(
The LMS tracks publication assets for a library, including those who
check out and return those publications.

(1) Add publication - This allows the librarian to enter data
    associated with a new publication.
(2) List all publications - All data known about each publication
    in the library is listed.
(3) Check out publication - Enter the data for patrons who check out
    a publication, and mark that publication as checked out.
(4) Check in publication - Select a publication and mark it as checked in.
(5) Add patron - This allows the librarian to enter data associated
    with a new library patron.
(6) List patrons - All data know about each patron of the library.
(9) Help - Print this text.
(0) Exit - Exit the program. WARNING: The current version does NOT
    save any entered data. This feature will be added in the "next version".

Use the '99' command to pre-populate test data.
  )";

      Dialogs::message(msg, "Help Menu");

   }
   if (cmd_num == 99) {
     library.easter_egg();
   }
   if (cmd_num < 0 || (4 < cmd_num && cmd_num < 9) || (9 < cmd_num && cmd_num < 99) || (99 < cmd_num)) { // Invalid command
     cerr << "**** Invalid command - type 9 for help" << endl << endl;
   }
  }
  return EXIT_SUCCESS;
}
