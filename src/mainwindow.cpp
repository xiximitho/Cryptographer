//
// Created by felipe on 11/12/2021.
//

#include "mainwindow.h"

MainWindow::~MainWindow ()
= default;

MainWindow::MainWindow ()
    : m_VBox(Gtk::Orientation::VERTICAL)
{
  set_layout();
  set_slots();

  add_column("Id", m_Columns.m_col_id);
  add_column("Nome", m_Columns.m_col_name);

  add_column_w_mask ("Formatado", m_Columns.m_col_value,"%010f");

  add_item (0,"teste", 231.52, 2);

}
void MainWindow::set_layout ()
{
  set_title("Gtk::TreeView (ListStore) example");
  set_default_size(400, 200);

  m_VBox.set_margin(5);
  set_child(m_VBox);

  //Adiciona a treeview dentro do scroll
  m_ScrolledWindow.set_child(m_TreeView);

  //Mostra scrollbar somente quando é necessario
  m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_ScrolledWindow.set_expand();

  m_VBox.append(m_ScrolledWindow);

  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  m_ButtonBox.append(m_Button_Quit);
  m_ButtonBox.set_margin(5);
  m_Button_Quit.set_hexpand(true);
  m_Button_Quit.set_halign(Gtk::Align::END);

}

void MainWindow::set_slots ()
{
  m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,&MainWindow::on_click_m_Button_Quit));
}

void MainWindow::on_click_m_Button_Quit ()
{
  this->hide();
}

void MainWindow::add_item (unsigned int id, const Glib::ustring& name, double value, int percent)
{
  m_Row = *(m_refTreeModel->append());
  m_Row[m_Columns.m_col_id] = id;
  m_Row[m_Columns.m_col_name] = name;
  m_Row[m_Columns.m_col_value] = value;
  m_Row[m_Columns.m_col_percentage] = percent;
}

template<typename Type>
void MainWindow::add_column (const Glib::ustring &title, const Gtk::TreeModelColumn<Type> &m_column)
{
  m_TreeView.append_column (title, m_column);
}
template<typename Type>
void MainWindow::add_column_w_mask (const Glib::ustring &title, const Gtk::TreeModelColumn<Type> &m_column, const Glib::ustring &mask)
{
  m_TreeView.append_column_numeric (title, m_column, mask);
}