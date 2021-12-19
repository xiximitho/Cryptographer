//
// Created by felipe on 11/12/2021.
//
#include "mainwindow.h"

MainWindow::~MainWindow ()
= default;

ListModelColumns::ListModelColumns ()
{
  add(m_col_id);
  add(m_col_name);
  add(m_col_value);
  add(m_col_percentage);
}

MainWindow::MainWindow ()
    : m_VBox(Gtk::Orientation::VERTICAL)
{
  set_layout();
  set_slots();

  add_column("Id", m_columns.m_col_id);
  add_column("Arquivo", m_columns.m_col_name);

  add_column_w_mask ("Formatado", m_columns.m_col_value,"%010f");

  //insere a barra de progresso para o campo percent
  auto cell = Gtk::make_managed<Gtk::CellRendererProgress>();
  int cols_count = m_treeView.append_column("Restante", *cell);
  auto pColumn = m_treeView.get_column(cols_count - 1);
  if(pColumn)
    {
      pColumn->add_attribute(cell->property_value(), m_columns.m_col_percentage);
    }

}
void MainWindow::set_layout ()
{
  set_title("Cryptographer");
  set_default_size(1280, 720);

  m_VBox.set_margin(5);
  set_child(m_VBox);

  //Adiciona a treeview dentro do scroll
  m_scrolledWindow.set_child(m_treeView);

  //Mostra scrollbar somente quando é necessario
  m_scrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_scrolledWindow.set_expand();

  m_VBox.append(m_scrolledWindow);

  m_refTreeModel = Gtk::ListStore::create(m_columns);

  m_treeView.set_model(m_refTreeModel);


  m_button_Add.set_label ("Adicionar");
  m_button_Compress.set_label ("Criptografar");
  m_button_Decompress.set_label ("Descriptografar");
  m_button_Quit.set_label ("Fechar");
  m_buttonBox.set_spacing (33);
  m_buttonBox.append (m_entry_Chave);
  m_buttonBox.append (m_button_Add);
  m_buttonBox.append (m_button_Compress);
  m_buttonBox.append (m_button_Decompress);
  m_buttonBox.append(m_button_Quit);
  m_buttonBox.set_margin(5);
  m_button_Quit.set_hexpand(true);

  m_button_Quit.set_halign(Gtk::Align::END);
  m_button_Compress.set_halign (Gtk::Align::END);
  m_button_Add.set_halign (Gtk::Align::END);

  m_VBox.append (m_buttonBox);
}

void MainWindow::set_slots ()
{
  m_button_Quit.signal_clicked().connect( sigc::mem_fun(*this,&MainWindow::on_click_m_Button_Quit));
  m_button_Add.signal_clicked().connect (sigc::mem_fun (*this, &MainWindow::on_click_m_Button_Add));
  m_button_Compress.signal_clicked().connect (sigc::mem_fun (*this, &MainWindow::on_click_m_Button_Compress));
}

void MainWindow::add_item (unsigned int id, const Glib::ustring& name, double value, int percent)
{
  Gtk::TreeRow m_Row;
  m_Row = *(m_refTreeModel->append());
  m_Row[m_columns.m_col_id] = id;
  m_Row[m_columns.m_col_name] = name;
  m_Row[m_columns.m_col_value] = value;
  m_Row[m_columns.m_col_percentage] = percent;

}

template<typename Type>
void MainWindow::add_column (const Glib::ustring &title, const Gtk::TreeModelColumn<Type> &m_column)
{
  m_treeView.append_column (title, m_column);
}
template<typename Type>
void MainWindow::add_column_w_mask (const Glib::ustring &title, const Gtk::TreeModelColumn<Type> &m_column, const Glib::ustring &mask)
{
  m_treeView.append_column_numeric (title, m_column, mask);
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
  //para cada filho(item)
  for(auto row : m_refTreeModel->children()){
    std::cout << "id: " << row[m_columns.m_col_id] << "\n";

      std::cout <<  CryptoPP::AES::BLOCKSIZE << std::endl;

      Glib::ustring i = "Idt@102#";

      std::array<unsigned char, 16> b_key = {'#','!','@','b','a','b','a','b','a','b','a','b','a','b','a','b'};

      std::array<unsigned char, 16> b_iv = {'0','x'};

      std::cout << "\n CHAVE: ";
      for (auto ai:b_key)
        {
          std::cout << ai;
        }

      std::cout << "\n \n";
      //encrypt(b_key, b_iv, row[m_Columns.m_col_name], row[m_Columns.m_col_name]+"-cif");

      decrypt (b_key, b_iv, row[m_columns.m_col_name], row[m_columns.m_col_name]+".out");
  }

  std::cout << "Finalizado";
}
void MainWindow::add_file_list (std::string &filename)
{
  file_count++;
  //somente caso nao for windows irá introduzir um backslash e espaço (definidos por sistemas baseados em unix)
#ifndef __WIN32
  search_and_replace (filename, std::string(" "), std::string("\\ "));
#endif
  add_item (file_count,filename, 0.00, 0);
}

void MainWindow::search_and_replace(std::basic_string<char> str, std::string const& search, std::string const& replace)
{
  std::string::size_type next;

  for(next = str.find(search);next != std::string::npos;next = str.find(search,next))
    {
      str.replace(next,search.length(),replace);
      next += replace.length();
    }
}

void MainWindow::encrypt(const aes_key_t &key, const aes_iv_t &iv,const Glib::ustring &filename_in, const Glib::ustring &filename_out)
{
  CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption cipher{};
  cipher.SetKeyWithIV(key.data(), key.size(), iv.data());

  std::ifstream in{filename_in, std::ios::binary};
  std::ofstream out{filename_out, std::ios::binary};

  CryptoPP::FileSource{in, /*bombeia todos=*/true,new CryptoPP::StreamTransformationFilter{cipher, new CryptoPP::FileSink{out}}};
}

void MainWindow::decrypt(const aes_key_t &key, const aes_iv_t &iv, const Glib::ustring &filename_in, const Glib::ustring &filename_out)
{
  CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption cipher{};
  cipher.SetKeyWithIV(key.data(), key.size(), iv.data());

  std::ifstream in{filename_in, std::ios::binary};
  std::ofstream out{filename_out, std::ios::binary};

  CryptoPP::FileSource{in, /*bombeia todos=*/true,new CryptoPP::StreamTransformationFilter{cipher, new CryptoPP::FileSink{out}}};
}
