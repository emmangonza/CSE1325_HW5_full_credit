#include <iostream>
#include <vector>
#include <string>
#include "library.h"
#include "publication.h"
using namespace std;

void show_menu();
void list_publications(Library lib);
void execute_cmd(int cmd, Library lib, Publication pub;

void show_menu() {
  cout << "\n===============================\n";
  cout << "C1325 Library Management System\n";
  cout << "===============================\n";
  cout << "\nPublications\n------------\n";
  cout << "(1) Add publication\n(2) List all publications\n";
  cout << "(3) Check out publication\n(4) Check in publication\n";
  cout << "\nUtility\n-------\n";
  cout << "(9) Help\n(0) Exit\n";
}

void list_publications(Library lib) {
  for(int i = 0; i < lib.number_of_publications(); ++i) {
    cout << lib.publication_to_string(i);
    cout << "\n\n";
  }
}

void execute_cmd(int cmd, Library lib, Publication pub) {
  int index;
  if(cmd == 1) lib.add_publication(pub);
  if(cmd == 2) list_publications(lib);
  if(cmd == 3) {
    string name, number
    cout << "\nEnter the patron name: ";
    getline(cin, name);
    cout << "\nEnter the patron phone number ";
    getline(cin, number);
    cout << "\nWhich publication?(Enter a number) ";
    cin >> index;

    lib.check_out(index, name, number);
  }
  if(cmd == 4) {
    cout << "\nWhich publication?(Enter a number) ";
    cin >> index;

    lib.check_in(index);
  }
  if(cmd == 9) {
    cout << "To perform any of the these actions, simply press the corresponding\n";
    cout << "number on your keyboard.\n\n"
    cout << "1. If you wish to add a publication, be prepared to enter the\n";
    cout << "following: title, author, copyright, genre, media, age, and isbn\n\n";
    cout << "2. Listing the publications will print all of the publications that\n";
    cout << "have added.\n\n";
    cout << "3. Checking a publication out will require the patrons name and\n";
    cout << "phone number. When chosing a publication to check out or in, the first\n";
    cout << "publication corresponds to the number 0 and the list goes down\n";
    cout << "chronologically.\n\n"
    cout << "4. Pressing 0 will exit the program.\n\n"
  }
}

int main() {
  int command;
  Library main_lib;
  Publication default_pub();

  show_menu();

  while(true) {
    cout << "Enter your command: ";
    cin >> command;

    if(command == 0) return 0;

    exectue_cmd(command, lib, default_pub);
  }

}
