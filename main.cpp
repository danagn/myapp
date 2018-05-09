#include "mainwindow.h"
#include "scenemodifier.h"

#include <QApplication>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>
#include <Qt3DExtras/QOrbitCameraController>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   MainWindow w;
//    w.show();
//ADDED TO GITHUB
   //ADDED TO GITHUB
   //ADDED TO GITHUB



    Qt3DExtras::Qt3DWindow *view= new Qt3DExtras::Qt3DWindow();
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    w.modifier = new scenemodifier(rootEntity);

    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 320.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camera);

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    w.modifier->LoadSTL();

    view->setRootEntity(rootEntity);

    view->show();

    return a.exec();
}
