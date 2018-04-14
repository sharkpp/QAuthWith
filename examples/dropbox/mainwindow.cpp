#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dropbox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dropbox(new Dropbox())
{
    ui->setupUi(this);
    setupUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUi()
{
    ui->methodList->addItem(tr("authorization"));
    ui->methodList->addItem(tr("upload"));
    ui->methodList->addItem(tr("download"));
    ui->methodList->addItem(tr("remove"));

    connect(ui->methodList, &QListWidget::currentItemChanged, [&](QListWidgetItem *current, QListWidgetItem * /*previous*/) {
        ui->methodProperty->setCurrentIndex(ui->methodList->row(current));
    });

    ui->methodList->setCurrentRow(0);

    for (int i = 0; i < ui->methodProperty->count(); ++i) {
        PageBase *base = qobject_cast<PageBase*>(ui->methodProperty->widget(i));
        base->setAuth(dropbox);
    }
}

void MainWindow::on_pushButton_clicked()
{

}
