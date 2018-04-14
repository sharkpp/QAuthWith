#include "pageauth.h"
#include "ui_pageauth.h"
#include "dropbox.h"

PageAuth::PageAuth(QWidget *parent)
    : PageBase(parent)
    , ui(new Ui::PageAuth)
{
    ui->setupUi(this);
}

PageAuth::~PageAuth()
{
    delete ui;
}

void PageAuth::setAuth(Dropbox *dropbox)
{
    PageBase::setAuth(dropbox);

    connect(dropbox, &Dropbox::authenticated, this, [&]() {
        ui->signal_authenticated->setCheckState(Qt::Checked);
        ui->userToken->setText(dropbox->token());
    });
}

void PageAuth::on_executeReqest_clicked()
{
    ui->signal_authenticated->setCheckState(Qt::Unchecked);
    ui->userToken->setText("");

    dropbox->setAppKeyAndSecret(
        ui->appKey->text(),
        ui->appSecret->text()
    );
}
