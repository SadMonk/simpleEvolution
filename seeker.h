#ifndef SEEKER_H
#define SEEKER_H

#include <QGraphicsItem>

class Seeker : public QGraphicsItem
{
public:
    Seeker();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    int x;
    int y;
    int accX;
    int accY;
};

#endif // SEEKER_H
