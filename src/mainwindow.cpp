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
  add_column("Arquivo", m_Columns.m_col_name);

  add_column_w_mask ("Formatado", m_Columns.m_col_value,"%010f");

  //insere a barra de progresso para o campo percent
  auto cell = Gtk::make_managed<Gtk::CellRendererProgress>();
  int cols_count = m_TreeView.append_column("Restante", *cell);
  auto pColumn = m_TreeView.get_column(cols_count - 1);
  if(pColumn)
    {
      pColumn->add_attribute(cell->property_value(), m_Columns.m_col_percentage);
    }

}
void MainWindow::set_layout ()
{
  set_title("Cryptographer");
  set_default_size(1280, 720);

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


  m_Button_Add.set_label ("Adicionar");
  m_Button_Compress.set_label ("Comprimir");
  m_Button_Quit.set_label ("Fechar");
  m_ButtonBox.set_spacing (33);
  m_ButtonBox.append (m_Button_Add);
  m_ButtonBox.append (m_Button_Compress);
  m_ButtonBox.append(m_Button_Quit);
  m_ButtonBox.set_margin(5);
  m_Button_Quit.set_hexpand(true);

  m_Button_Quit.set_halign(Gtk::Align::END);
  m_Button_Compress.set_halign (Gtk::Align::END);
  m_Button_Add.set_halign (Gtk::Align::END);

  m_VBox.append (m_ButtonBox);

}

void MainWindow::set_slots ()
{
  m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,&MainWindow::on_click_m_Button_Quit));
  m_Button_Add.signal_clicked().connect (sigc::mem_fun (*this, &MainWindow::on_click_m_Button_Add));
  m_Button_Compress.signal_clicked().connect (sigc::mem_fun (*this, &MainWindow::on_click_m_Button_Compress));
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
void MainWindow::on_click_m_Button_Add ()
{
  auto dialog = new Gtk::FileChooserDialog("Selecione um arquivo",
                                           Gtk::FileChooser::Action::OPEN);
  dialog->set_transient_for(*this);
  dialog->set_modal(true);
  dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_file_dialog_response), dialog));

  //Adicionar botoes
  dialog->add_button("_Abrir", Gtk::ResponseType::OK);
  dialog->add_button("_Cancelar", Gtk::ResponseType::CANCEL);

  //Adiciona os filtros de arquivos
  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name(" All ");
  filter_any->add_pattern("*");
  dialog->add_filter(filter_any);

  //Mostra o dialogo e aguarda a response
  dialog->show();
}

void MainWindow::on_click_m_Button_Quit ()
{
  this->hide();
}
void MainWindow::on_file_dialog_response (int response_id, Gtk::FileChooserDialog *dialog)
{
  switch (response_id)
    {
      case Gtk::ResponseType::OK:
        {
          std::cout << "Clicou em Abrir." << std::endl;

          //retorna uma std:string
          auto filename = dialog->get_file()->get_path();
          std::cout << "Arquivo Selecionado: " <<  filename << std::endl;
          add_file_list(filename);
          break;
        }
      case Gtk::ResponseType::CANCEL:
        {
          std::cout << "Clicou em cancelar." << std::endl;
          break;
        }
      default:
        {
          std::cout << "Outro Botao." << std::endl;
          break;
        }
    }
  delete dialog;
}
void MainWindow::on_click_m_Button_Compress ()
{

}
void MainWindow::add_file_list (std::string &filename)
{
  file_count++;

  add_item (file_count,filename, 0.00, 0);
}
