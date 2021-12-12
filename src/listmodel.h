//
// Created by felipe on 11/12/2021.
//
//Classe que implementa as colunas de um treemodel

#ifndef _LISTMODEL_H_
#define _LISTMODEL_H_
#include "gtkmm.h"

class ListModelColumns : public Gtk::TreeModel::ColumnRecord{
   public:

    ListModelColumns();
    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<double> m_col_value;
    Gtk::TreeModelColumn<int> m_col_percentage;
};

#endif //_LISTMODEL_H_
