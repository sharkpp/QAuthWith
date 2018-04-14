#ifndef PAGEDOWNLOAD_H
#define PAGEDOWNLOAD_H

#include "PageBase.h"

namespace Ui {
class PageDownload;
}

class PageDownload
    : public PageBase
{
public:
    explicit PageDownload(QWidget *parent = 0);
    ~PageDownload();

private:
    Ui::PageDownload *ui;
};

#endif // PAGEDOWNLOAD_H
