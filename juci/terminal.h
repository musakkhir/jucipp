#ifndef JUCI_TERMINAL_H_
#define JUCI_TERMINAL_H_

#include <mutex>
#include "gtkmm.h"

namespace Terminal {

  class View {
  public:
    View();   
    Gtk::HBox& view() {return view_;}
    Gtk::TextView& textview() {return textview_;}
  private:
    Gtk::HBox view_;
    Gtk::TextView textview_;
    Gtk::ScrolledWindow scrolledwindow_;
  };  // class view
  
  class Controller {  
  public:
    Controller();
    Gtk::HBox& view() {return view_.view();}
    Gtk::TextView& Terminal(){return view_.textview();}
    void SetFolderCommand(std::string path);
    void CompileAndRun(std::string project_name);
  private:
    void ExecuteCommand(std::string command);
    bool OnButtonRealeaseEvent(GdkEventKey* key);
    bool ExistInConsole(std::string string);
    bool FindExecutable(std::string executable);
    void PrintMessage(std::string message);
    Terminal::View view_;
    std::string folder_command_;
    std::mutex running;
    const std::string cmake_sucsess = "Build files have been written to:";
    const std::string make_built = "Built target";
    const std::string make_executable = "Linking CXX executable";
  };  // class controller
}  // namespace Terminal

#endif  // JUCI_TERMINAL_H_