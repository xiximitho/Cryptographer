//
// Created by felipe on 05/12/2021.
//

#include "FormBase.h"
#include <utility>
#include <iostream>
#include <gtkmm/button.h>
#include "cryptopp/gzip.h"
#include "cryptopp/files.h"


FormBase::~FormBase() = default;

FormBase::FormBase(ustring Title, int Width, int Height) {
    this->Title = std::move(Title);
    this->Width = Width;
    this->Height = Height;


  //auto pmap = Gtk::make_managed<Gtk::Image>("dota2.svg");
  auto label = Gtk::make_managed<Gtk::Label>("Comprimir utilizando Gzip");
  label->set_expand(true);

  //Box para colocar a label + botao ou Imagem:
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  //hbox->append(*pmap);
  hbox->append(*label);

  //Colocar o box no botao
  pButtonCompress.set_child(*hbox);

  set_title(this->Title);
  set_default_size(this->Width, this->Height);

  pButtonCompress.signal_clicked().connect( sigc::mem_fun(*this,
                                                   &FormBase::onClickCompress) );

  pButtonCompress.set_margin(10);
  set_child(pButtonCompress);
}

void FormBase::onClickCompress(){
  //Teste para criar um arquivo comprimido Gzip
  ustring filename("test.txt.gz");
  ustring data = "abcdefghijklmnopqrstuvwxyz";

  CryptoPP::Gzip zipper(new CryptoPP::FileSink(filename.c_str(), true));
  zipper.Put(reinterpret_cast<const CryptoPP::byte *>((std::byte *) data.data ()), data.size());
  zipper.MessageEnd();
}