#ifndef SEEKER_H
#define SEEKER_H

#include <QGraphicsItem>
#include <QVector2D>

class Seeker : public QGraphicsItem
{
public:
    Seeker();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    QVector2D position;
    QVector2D velocity;
    QVector2D acceleration;
};

#endif // SEEKER_H
