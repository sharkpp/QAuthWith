#include "pagebase.h"

PageBase::PageBase(QWidget *parent)
    : QWidget(parent)
{

}

PageBase::~PageBase()
{

}

void PageBase::setAuth(Dropbox *dropbox)
{
    this->dropbox = dropbox;
}
