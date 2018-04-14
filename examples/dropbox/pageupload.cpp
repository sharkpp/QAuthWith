#include "pageupload.h"
#include "ui_pageupload.h"

PageUpload::PageUpload(QWidget *parent)
    : PageBase(parent)
    , ui(new Ui::PageUpload)
{
    ui->setupUi(this);
}

PageUpload::~PageUpload()
{
    delete ui;
}
