#include "WaterDrop.h"
#include <QPainter>

// 水滴的默认半径;
#define WATER_DROP_RADIUS 15

WaterDrop::WaterDrop(QWidget *parent)
	: QWidget(parent)
	, m_waterDropAnimation(NULL)
	, m_animationRadius(0)
	, m_waterDropColor(QColor(255, 120, 0, 150))    // 默认为橘黄色;
    , m_waterDropRadisu(WATER_DROP_RADIUS)
{
	this->setFixedSize(QSize(WATER_DROP_RADIUS * 2, WATER_DROP_RADIUS * 2));
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	this->setAttribute(Qt::WA_TranslucentBackground);

	// 控件显示完关闭后自动删除;
	this->setAttribute(Qt::WA_DeleteOnClose);

	m_waterDropAnimation = new QVariantAnimation(this);
}

WaterDrop::~WaterDrop()
{
}

// 设置水滴的颜色;
void WaterDrop::setColor(QColor color)
{
	m_waterDropColor = color;
}

// 设置水滴半径;
void WaterDrop::setRadius(int radius)
{
    m_waterDropRadisu = radius;
    this->setFixedSize(QSize(m_waterDropRadisu * 2, m_waterDropRadisu * 2));
}

void WaterDrop::showWaterDrop(const QPoint &point)
{
    // 通过动画类不断进行重绘;
    m_waterDropAnimation->setStartValue(0);
    m_waterDropAnimation->setEndValue(m_waterDropRadisu);
    m_waterDropAnimation->setDuration(350);

    connect(m_waterDropAnimation, &QVariantAnimation::valueChanged, this, &WaterDrop::onRaduisChanged);
    connect(m_waterDropAnimation, &QVariantAnimation::finished, this, &WaterDrop::close);
    m_waterDropAnimation->start();

    // 这里要把鼠标点击的点转换为圆心点坐标;
    QPoint translatePoint = point - QPoint(m_waterDropRadisu, m_waterDropRadisu);
    __super::move(translatePoint);
    __super::show();
}

// 绘制鼠标的水滴点击效果;
void WaterDrop::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(m_waterDropColor));

	// 思路就是先绘制一个固定大小的圆A，然后绘制同一圆心的透明的圆B，然后通过动画类是圆B的半径从0增长到m_waterDropRadisu，以致覆盖固定的圆A;
	QPainterPath waterDropPath;
	waterDropPath.addEllipse(QPoint(m_waterDropRadisu, m_waterDropRadisu), m_waterDropRadisu, m_waterDropRadisu);
	QPainterPath hidePath;
	hidePath.addEllipse(QPoint(m_waterDropRadisu, m_waterDropRadisu), m_animationRadius, m_animationRadius);

	waterDropPath -= hidePath;
	painter.drawPath(waterDropPath);
}

void WaterDrop::onRaduisChanged(QVariant value)
{
	// 不断增加圆B的半径值,并重绘;
	m_animationRadius = value.toInt();
	update();
}