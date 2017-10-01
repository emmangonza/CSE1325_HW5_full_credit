#include "dialogs.h"

void Dialogs::message(string msg, string title) {
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
  dialog->set_secondary_text(msg, true);
  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending()) Gtk::Main::iteration();

  delete dialog;
}
