#include "shape.h"

int Shape::getTableIndex() const
{
    return tableIndex;
}

void Shape::setTableIndex(int value)
{
    tableIndex = value;
}

Shape::Shape()
{
    color = "#000000";
}

void Shape::setShape(QVector<Point> points)
{
    this->points = points;

}

QVector<Point> Shape::getShape()
{
    return points;
}

void Shape::setColor(Color color)
{
    this->color = color;
}

void Shape::addPoint(Point point)
{
    points.push_back(point);
}

QString Shape::wkt() const
{
    return "";
}

