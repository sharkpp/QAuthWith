#include "appdata.h"
#include "apidefinition.h"

AppData::AppData(QObject *parent)
    : QObject(parent)
{
    apiDefinitionLModel.append(new ApiDefinition("てすとてすと"));
    apiDefinitionLModel.append(new ApiDefinition("ほげほげ"));
}

QList<QObject*> AppData::getApiMethods()
{
    return apiDefinitionLModel;
}






















