#include "triangle.h"

Triangle::Triangle()
{
    shapeName = "Triangle";
}

Triangle::Triangle(QVector<Point> points)
{
    this->points = points;
}

double Triangle::getArea()
{
    double a = distance(points[0].x, points[0].y, points[1].x, points[1].y);
    double b = distance(points[1].x, points[1].y, points[2].x, points[2].y);
    double c = distance(points[2].x, points[2].y, points[0].x, points[0].y);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p -c ));
}

QString Triangle::constuctToFileFormat()
{
    QString data = shapeName + " " + color + " (";
    for (Point point : points)
    {
        data = data + QString::number(point.x) + " " + QString::number(point.y) + ",";
    }
    data.chop(1);
    data += ")";
    return data;
}

QGraphicsItemGroup *Triangle::toItemGroup()
{
    QGraphicsItemGroup* group = new QGraphicsItemGroup;
    QGraphicsItem* item = new QGraphicsPolygonItem;
    QPolygonF polygon;
    for (Point point : points)
    {
        polygon.append(QPointF(point.x, point.y));
    }
    ((QGraphicsPolygonItem*)item)->setPolygon(polygon);
    QColor brushcolor;
    brushcolor.setNamedColor(color);
    ((QGraphicsPolygonItem*)item)->setBrush(brushcolor);
    group->addToGroup(item);
    group->setData(1, "Triangle");
    group->setData(2, color);
    return group;
}

QString Triangle::wkt() const
{
    strstream ss;
    ss << "POLYGON((";
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            ss << points[i].x << " " << points[i].y << ")";
        }
        ss << points[i].x << " " << points[i].y << ",";
    }
    return QString::fromStdString(ss.str());
}

double Triangle::distance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
