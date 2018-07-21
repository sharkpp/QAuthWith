#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QList>

class AppData
    : public QObject
{
    Q_OBJECT

    QList<QObject*> methodList;

public:

    explicit AppData(QObject *parent = nullptr);

    Q_INVOKABLE QList<QObject*> getMethods();

signals:

public slots:
};

#endif // APPDATA_H
