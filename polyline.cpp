#include "polyline.h"

Polyline::Polyline()
{
    shapeName = "Polyline";
}

Polyline::Polyline(QVector<Point> points)
{
    this->points = points;
}

double Polyline::getArea()
{
    return 0;
}

void Polyline::Build(char *buf)
{
    int partNum = *(int*)(buf + 36);
    pointNum = *(int*)(buf + 40);
    Point *pt = (Point*)(buf + 44 + 4 * partNum);

    for(int i = 0; i < pointNum; i++)
    {
        points.push_back(pt[i]);
    }
}

QString Polyline::wkt() const
{
    strstream ss;
    ss << "LINESTRING(";
    for (int i = 0; i < pointNum; i++)
    {
        ss << points[i].x << " " << points[i].y;
        if (i < pointNum - 1)
            ss << ",";
        else
            ss << ")";
    }
    return QString::fromStdString(ss.str());
}

QString Polyline::constuctToFileFormat()
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

QGraphicsItemGroup *Polyline::toItemGroup()
{
    QGraphicsItemGroup* group = new QGraphicsItemGroup;
    QGraphicsItem* item = new QGraphicsLineItem;
    QLineF line;
    QPointF startPt, endPt;
    for (int i = 1; i < points.length(); i++)
    {
        startPt = {points[i - 1].x, points[i - 1].y};
        endPt = {points[i].x, points[i].y};
        line = {startPt, endPt};
        QColor pencolor;
        pencolor.setNamedColor(color);
        ((QGraphicsLineItem*)item)->setPen(pencolor);
        ((QGraphicsLineItem*)item)->setLine(line);
        group->addToGroup(item);
    }
    group->setData(1, "Polyline");
    group->setData(2, color);
    return group;
}

