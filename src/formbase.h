//
// Created by felipe on 05/12/2021.
//

#ifndef FTK_FORMBASE_H
#define FTK_FORMBASE_H

#include "gtkmm.h"
#include "glibmm.h"
using namespace Glib;

class FormBase : public Gtk::Window {
public:
    explicit FormBase(ustring Title = "formbase", int Width = 1280, int Height = 900);
    ~FormBase() override;

protected:
    ustring Title;
    int Width;
    int Height;

 protected:
  //Sinais:
  void onClickCompress();

  //Widgets
  Gtk::Button pButtonCompress;
  Gtk::Box boxLayout;
  Gtk::TreeView tr;
  Gtk::ScrolledWindow scrollWindow;
};


#endif //FTK_FORMBASE_H
