#include "seeker.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <qmath.h>

Seeker::Seeker()
{

    // for now, initialize in the middle of the screen with no velocity or acceleration
    position = QVector2D(0,0);
    velocity = QVector2D(0,0);
    acceleration = QVector2D(QPointF(
                                 (-50 + QRandomGenerator::global()->bounded(100.0)) / 100.0,
                                 (-50 + QRandomGenerator::global()->bounded(100)) / 100.0)
                             );
}

// pretty simple paint... just paint a round dot.
void Seeker::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(-3,-3,6,6);
}

void Seeker::advance(int step)
{
    // if step == 0 this is pretty much a "beforeMove" callback while step == 1 is "move"
    if(!step) {
        return;
    }

    velocity += acceleration;
    position += velocity;

    // set position relative to global coords
    setPos(position.toPointF());
}

QRectF Seeker::boundingRect() const
{
    return QRectF(-4, -4, 8, 8);
}

QPainterPath Seeker::shape() const
{
    QPainterPath path;
    path.addRect(-3,-3,6,6);
    return path;
}
