#include "pagedownload.h"
#include "ui_pagedownload.h"

PageDownload::PageDownload(QWidget *parent)
    : PageBase(parent)
    , ui(new Ui::PageDownload)
{
    ui->setupUi(this);
}

PageDownload::~PageDownload()
{
    delete ui;
}
