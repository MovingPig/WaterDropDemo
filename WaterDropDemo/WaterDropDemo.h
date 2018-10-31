#pragma once

#include <QtWidgets/QWidget>

class WaterDropDemo : public QWidget
{
    Q_OBJECT

public:
    WaterDropDemo(QWidget *parent = Q_NULLPTR);

private:
    void mousePressEvent(QMouseEvent *event);

};
