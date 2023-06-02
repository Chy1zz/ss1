#include "polygon.h"

Polygon::Polygon()
{
    shapeName = "Polygon";
}

Polygon::Polygon(QVector<Point> points)
{
    this->points = points;
}

double Polygon::getArea()
{
    double s = points[0].y * (points[points.length()-1].x - points[1].x);
    for(int i = 1; i < points.length(); ++i)
        s += points[i].y * (points[i-1].x - points[(i + 1) % points.length()].x);
    return fabs(s/2.0);
}

void Polygon::Build(char *buf)
{
    partNum = *(int*)(buf + 36);
    int numPoints = *(int*)(buf + 40);
    parts = (int*)(buf + 44);
    Point *pt = (Point*)(buf + 44 + 4 * partNum);

    for(int i = 0; i < numPoints; i++)
    {
        points.push_back(pt[i]);
    }
}

QString Polygon::wkt() const
{
    strstream ss;
    ss << setiosflags(ios_base::fixed);
    ss << "POLYGON(";
    int pointIndex = 0;
    for (int i = 0; i < partNum; i++)
    {
        ss << "(";
        for (int j = 0; j < parts[i]; j++)
        {
            ss << setprecision(10) << points[pointIndex].x << " " <<setprecision(10) << points[pointIndex].y;
            if (j < parts[i] - 1)
                ss << ",";
            else
                ss << ")";
        }
        if (i < partNum - 1)
            ss << ",";
        else
            ss << ")";
    }
    return QString::fromStdString(ss.str());
}

QString Polygon::constuctToFileFormat()
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

QGraphicsItemGroup *Polygon::toItemGroup()
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
    group->setData(1, "Polygon");
    group->setData(2, color);
    return group;
}
