#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Dropbox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void setupUi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dropbox *dropbox;
};

#endif // MAINWINDOW_H
