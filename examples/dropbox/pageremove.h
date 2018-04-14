#ifndef PAGEREMOVE_H
#define PAGEREMOVE_H

#include "PageBase.h"

namespace Ui {
class PageRemove;
}

class PageRemove
    : public PageBase
{
public:
    explicit PageRemove(QWidget *parent = 0);
    ~PageRemove();

private:
    Ui::PageRemove *ui;
};

#endif // PAGEREMOVE_H
