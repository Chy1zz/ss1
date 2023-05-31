#include "basicpoint.h"

BasicPoint::BasicPoint()
{
    shapeName = "Point";
}

BasicPoint::BasicPoint(QVector<Point> points)
{
    this->points = points;
}

double BasicPoint::getArea()
{
    return 0;
}

void BasicPoint::Build(char *buf)
{
    Point *pt = (Point*)(buf + 4);
    points.push_back(*pt);
}

QString BasicPoint::wkt() const
{
    strstream ss;
    ss << "POINT(";
    ss << points[0].x << " " << points[0].y;
    ss << ")";
    return QString::fromStdString(ss.str());
}

QString BasicPoint::constuctToFileFormat()
{
    return shapeName + " " + color + " " + "(" + QString::number(points[0].x) + " " + QString::number(points[0].y) + ")";
}

QGraphicsItemGroup *BasicPoint::toItemGroup()
{
    QGraphicsItemGroup* group = new QGraphicsItemGroup;
    Point anchorPt = {points[0].x, points[0].y};
    QGraphicsItem* item = new QGraphicsEllipseItem(anchorPt.x-1, anchorPt.y-1, 2, 2);
    QColor brushcolor;
    brushcolor.setNamedColor(color);
    ((QGraphicsEllipseItem*)item)->setBrush(brushcolor);
    group->addToGroup(item);
    group->setData(1, "Point");
    group->setData(2, color);
    return group;
}
