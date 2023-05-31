#ifndef BASICPOINT_H
#define BASICPOINT_H
#include "shape.h"

class BasicPoint : public Shape
{
public:
    BasicPoint();
    BasicPoint(QVector<Point> points);
    // Shape interface
public:
    double getArea() override;
    void Build(char *buf) override;
    QString wkt() const override;
    QString constuctToFileFormat() override;
    QGraphicsItemGroup *toItemGroup() override;
};

#endif // BASICPOINT_H
