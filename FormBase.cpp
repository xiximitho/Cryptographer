//
// Created by felipe on 05/12/2021.
//

#include "FormBase.h"
#include <utility>

FormBase::~FormBase() = default;

FormBase::FormBase(ustring Title, int Width, int Height) {
    this->Title = std::move(Title);
    this->Width = Width;
    this->Height = Height;


    set_title(this->Title);
    set_default_size(this->Width, this->Height);
}

