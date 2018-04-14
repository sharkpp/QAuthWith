#include "pageremove.h"
#include "ui_pageremove.h"

PageRemove::PageRemove(QWidget *parent)
    : PageBase(parent)
    , ui(new Ui::PageRemove)
{
    ui->setupUi(this);
}

PageRemove::~PageRemove()
{
    delete ui;
}
