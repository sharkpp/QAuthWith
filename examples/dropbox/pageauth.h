#ifndef PAGEAUTH_H
#define PAGEAUTH_H

#include "PageBase.h"

namespace Ui {
class PageAuth;
}

class PageAuth
    : public PageBase
{
public:
    explicit PageAuth(QWidget *parent = 0);
    ~PageAuth();

    virtual void setAuth(Dropbox *dropbox);

private slots:
    void on_executeReqest_clicked();

private:
    Ui::PageAuth *ui;
};

#endif // PAGEAUTH_H
