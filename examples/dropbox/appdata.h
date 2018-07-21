#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QList>

class ApiDefinitionModel;

class AppData
    : public QObject
{
    Q_OBJECT

    QList<QObject*> apiDefinitionLModel;

public:

    explicit AppData(QObject *parent = nullptr);

    Q_INVOKABLE QList<QObject*> getApiMethods();

signals:

public slots:
};

#endif // APPDATA_H
