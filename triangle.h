#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(QVector<Point> points);


    // Shape interface
public:
    double getArea() override;
    QString constuctToFileFormat() override;
    QGraphicsItemGroup *toItemGroup() override;
    QString wkt() const override;

private:
    double distance(float x1, float y1, float x2, float y2);
};

#endif // TRIANGLE_H
