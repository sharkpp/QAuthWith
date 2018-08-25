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

    QList<QObject*> m_definitions; // definitions of methods/signals

    Dropbox* m_dropbox;

public:

    explicit AppData(QObject *parent = nullptr);

    Q_PROPERTY(QString appName   MEMBER m_appName   CONSTANT)

    Q_PROPERTY(QList<QObject*> definitions   MEMBER m_definitions   CONSTANT)

signals:

public slots:
};

#endif // APPDATA_H
