//
// Created by felipe on 11/12/2021.
//

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_
#include "gtkmm.h"
#include "sigc++/sigc++.h"
#include "listmodel.h"
#include <utility>
#include <iostream>
#include "cryptopp/gzip.h"
#include "cryptopp/files.h"
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <iostream>
#include <openssl/aes.h>

using aes_key_t = std::array<CryptoPP::byte, CryptoPP::AES::DEFAULT_KEYLENGTH>;
using aes_iv_t = std::array<CryptoPP::byte, CryptoPP::AES::BLOCKSIZE>;

class MainWindow : public Gtk::Window{
 public:
  MainWindow();
  ~MainWindow() override;

 protected:
  //Signals
  void on_click_m_Button_Quit();
  void on_click_m_Button_Add();
  void on_click_m_Button_Compress();
  //Signal de resposta do dialog
  void on_file_dialog_response(int response_id, Gtk::FileChooserDialog *dialog);

  void set_layout();
  void set_slots();

  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  ListModelColumns m_Columns;

  Gtk::Box m_ButtonBox;
  Gtk::Button m_Button_Quit;
  Gtk::Button m_Button_Add;
  Gtk::Button m_Button_Compress;

  void add_item(unsigned int id, const Glib::ustring& name, double value, int percent);
  void add_file_list(std::string& filename);
  //template para adicionar qualquer tipo para a treeview
  template <typename Type> inline
  void add_column(const Glib::ustring& title, const Gtk::TreeModelColumn<Type>& m_column);

  template <typename Type> inline
  void add_column_w_mask(const Glib::ustring& title, const Gtk::TreeModelColumn<Type>& m_column, const Glib::ustring& mask);

  short file_count = 0;
  static void search_and_replace (std::basic_string<char> value, const std::string &search, const std::string &replace);

  static void encrypt (const std::array<CryptoPP::byte, 16> &key, const std::array<CryptoPP::byte, 16> &iv, const Glib::ustring &filename_in, const Glib::ustring &filename_out);
  static void decrypt (const std::array<CryptoPP::byte, 16> &key, const std::array<CryptoPP::byte, 16> &iv, const Glib::ustring &filename_in, const Glib::ustring &filename_out);
};

#endif //_MAINWINDOW_H_
