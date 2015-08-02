#ifndef JUCI_WINDOW_H_
#define JUCI_WINDOW_H_

#include "gtkmm.h"
#include "directories.h"
#include "entrybox.h"
#include "notebook.h"
#include "menu.h"

class Window : public Gtk::Window {
public:
  Window();
  Notebook notebook;
  Directories directories;
protected:
  bool on_key_press_event(GdkEventKey *event);
  bool on_delete_event (GdkEventAny *event);
private:
  Gtk::Box box;
  Gtk::VPaned vpaned;
  Gtk::Paned directory_and_notebook_panes;
  Gtk::VBox notebook_vbox;
  Gtk::VBox terminal_vbox;
  Gtk::HBox status_hbox;
  EntryBox entry_box;
  std::mutex running;
  Menu menu;

  void create_menu();
  void hide();
  void new_file_entry();
  void open_folder_dialog();
  void open_file_dialog();
  void save_file_dialog();
  
  void search_and_replace_entry();
  void goto_line_entry();
  void rename_token_entry();
  std::string last_search;
  std::string last_replace;
  bool case_sensitive_search=true;
  bool regex_search=false;
  bool search_entry_shown=false;

};

#endif  // JUCI_WINDOW_H
