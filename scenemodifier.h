#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H

#include <QtCore/QObject>
#include <QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

class scenemodifier : public QObject
{
    Q_OBJECT
public:
    explicit scenemodifier(Qt3DCore::QEntity *rootEntity);
    ~scenemodifier();


signals:

public slots:
    void LoadSTL();

private:
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_partEntity;
};

#endif // SCENEMODIFIER_H
