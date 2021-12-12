//
// Created by felipe on 11/12/2021.
//

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_
#include "gtkmm.h"
#include "sigc++/sigc++.h"
#include "listmodel.h"
class MainWindow : public Gtk::Window{
 public:
  MainWindow();
  ~MainWindow() override;

 protected:
  //Signals
  void on_click_m_Button_Quit();

  void set_layout();
  void set_slots();

  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  ListModelColumns m_Columns;

  Gtk::Box m_ButtonBox;
  Gtk::Button m_Button_Quit;

  void add_item(unsigned int id, const Glib::ustring& name, double value, int percent);

  //template para adicionar qualquer tipo para a treeview
  template <typename Type> inline
  void add_column(const Glib::ustring& title, const Gtk::TreeModelColumn<Type>& m_column);

  template <typename Type> inline
  void add_column_w_mask(const Glib::ustring& title, const Gtk::TreeModelColumn<Type>& m_column, const Glib::ustring& mask);

  //utilizar para adicionar na model
  Gtk::TreeRow m_Row;
};

#endif //_MAINWINDOW_H_
