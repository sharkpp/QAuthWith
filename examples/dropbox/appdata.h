#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QList>

class Dropbox;

class AppData
    : public QObject
{
    Q_OBJECT

    QString m_appName;

    QList<QObject*> methodList;

    Dropbox* m_dropbox;

public:

    explicit AppData(QObject *parent = nullptr);

    Q_PROPERTY(QString appName   MEMBER m_appName   CONSTANT)

    Q_INVOKABLE QList<QObject*> getMethods();

signals:

public slots:
};

#endif // APPDATA_H
