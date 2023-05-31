#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"

class Polyline : public Shape
{
private:
    int pointNum;

public:
    Polyline();
    Polyline(QVector<Point> points);

    // Shape interface
public:
    double getArea() override;
    void Build(char *buf) override;
    QString wkt() const override;
    QString constuctToFileFormat() override;
    QGraphicsItemGroup *toItemGroup() override;
};

#endif // POLYLINE_H
