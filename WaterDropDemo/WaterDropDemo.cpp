#include "WaterDropDemo.h"
#include "WaterDrop.h"
#include <QMouseEvent>

WaterDropDemo::WaterDropDemo(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(QSize(500, 500));
}

void WaterDropDemo::mousePressEvent(QMouseEvent *event)
{
    // 在鼠标点击出显示水滴效果;
    WaterDrop* waterDrop = new WaterDrop();
    waterDrop->setRadius(20);
    waterDrop->showWaterDrop(this->mapToGlobal(event->pos()));
}