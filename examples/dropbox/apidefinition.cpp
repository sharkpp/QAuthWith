#include "apidefinition.h"
#include <QDebug>

ApiDefinition::ApiDefinition(const QString &title_)
    : QObject()
    , m_title(title_)
{
}

void ApiDefinition::exec()
{
    qDebug() << m_title;
}

/*
ApiDefinitionModel::ApiDefinitionModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int	ApiDefinitionModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ApiDefinitionModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case TypeRole:
        return QVariant("*type*");
    case SizeRole:
        return QVariant("*size*");
    }
}

QHash<int, QByteArray> ApiDefinitionModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}
*/
