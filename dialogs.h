#ifndef __DIALOGS_H
#define __DIALOGS_H

#include <iostream>
#include <gtkmm.h>

using namespace std;

class Dialogs {
  public:
    static void message(string msg, string title);
};
#endif
