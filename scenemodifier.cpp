#include "scenemodifier.h"

#include <QUrl>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QMesh>

scenemodifier::scenemodifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity)
{

}

scenemodifier::~scenemodifier()
{
}
void scenemodifier::LoadSTL()
{
    QUrl data = QUrl::fromLocalFile("C:/Users/Dimitrios/MyQtapps/STLloader/block1.stl");
    Qt3DRender::QMesh *partMesh = new Qt3DRender::QMesh;
    partMesh->setSource(data);

    Qt3DCore::QTransform *partTransform = new Qt3DCore::QTransform();

    Qt3DExtras::QPhongMaterial *partMaterial = new Qt3DExtras::QPhongMaterial();
    partMaterial->setDiffuse(QColor(0, 200, 255));

    //part (STL model)
    m_partEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_partEntity->addComponent(partMesh);
    m_partEntity->addComponent(partMaterial);
    m_partEntity->addComponent(partTransform);
}
