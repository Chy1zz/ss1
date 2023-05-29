#ifndef SHAPE_H
#define SHAPE_H
#include <QVector>
#include <QStringList>
#include <QtMath>
#include <string>
#include <strstream>
#include <iomanip>
#include <QGraphicsItem>
#include <QPainter>
using namespace std;

typedef QString Color;

/*
 *外包矩形类，表示一个图形的最小外包矩形
 */
struct BBox
{
    double Xmin;
    double Ymin;
    double Xmax;
    double Ymax;
};

struct Point
{
    double x;
    double y;
};

class Shape
{
protected:
    QVector<Point> points;//几何图形的所有点
    Color color;//颜色
    QString shapeName;//几何图形的名称
    int tableIndex;//在数据库中的索引

public:
    Shape();
    void setShape(QVector<Point> points);
    QVector<Point> getShape();
    void setColor(Color color);
    void addPoint(Point point);
    int getTableIndex() const;
    void setTableIndex(int value);

public:
    //主要接口
    virtual QString constuctToFileFormat() = 0; //将图形转为我们定义的格式
    virtual double getArea() = 0;
    virtual QGraphicsItemGroup *toItemGroup() = 0;
    virtual void Build(char *buf) { buf = NULL;}
    virtual QString wkt() const;
};

#endif // SHAPE_H
