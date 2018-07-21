#ifndef APIDEFINITION_H
#define APIDEFINITION_H

#include <QAbstractListModel>


class ApiDefinition
    : public QObject
{
    Q_OBJECT

    QString m_title;

public:
    ApiDefinition(const QString &title_);

    Q_PROPERTY(QString title MEMBER m_title CONSTANT)

    Q_INVOKABLE void exec();
};
/*
class ApiDefinitionModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ApiDefinitionRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    ApiDefinitionModel(QObject *parent = 0);

    virtual int	rowCount(const QModelIndex &parent = QModelIndex()) const;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    virtual QHash<int, QByteArray> roleNames() const;
};
*/

#endif // APIDEFINITION_H
