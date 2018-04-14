#ifndef PAGEUPLOAD_H
#define PAGEUPLOAD_H

#include "PageBase.h"

namespace Ui {
class PageUpload;
}

class PageUpload
    : public PageBase
{
public:
    explicit PageUpload(QWidget *parent = 0);
    ~PageUpload();

private:
    Ui::PageUpload *ui;
};

#endif // PAGEUPLOAD_H
