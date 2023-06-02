#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"

class Polygon : public Shape
{
private:
    int* parts;
    int partNum;

public:
    Polygon();
    Polygon(QVector<Point> points);

    // Shape interface
public:
    double getArea() override;
    void Build(char *buf) override;
    QString wkt() const override;
    QString constuctToFileFormat() override;
    QGraphicsItemGroup *toItemGroup() override;
};

#endif // POLYGON_H
