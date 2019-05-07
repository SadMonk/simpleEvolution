#include <QApplication>
#include <QtWidgets>
#include <math.h>
#include "seeker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300,-300,600,600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);


    for(int i=0; i< 10; ++i) {
        Seeker *seeker = new Seeker;
        seeker->setPos(i*10,i*10);
        scene.addItem(seeker);
    }

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    //view.setBackgroundBrush(Qt::lightGray);

    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Simple evolution"));
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000/33);

    return a.exec();
}
