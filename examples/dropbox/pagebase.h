#ifndef PAGEBASE_H
#define PAGEBASE_H

#include <QWidget>

class Dropbox;

class PageBase
    : public QWidget
{
    Q_OBJECT

public:
    explicit PageBase(QWidget *parent = nullptr);
    ~PageBase();

    virtual void setAuth(Dropbox *dropbox);

protected:

signals:

public slots:

protected:
    Dropbox *dropbox;
};

#endif // PAGEBASE_H
