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
    explicit FormBase(ustring Title = "FormBase", int Width = 1280, int Height = 900);
    ~FormBase() override;

protected:
    ustring Title;
    int Width;
    int Height;

};


#endif //FTK_FORMBASE_H
