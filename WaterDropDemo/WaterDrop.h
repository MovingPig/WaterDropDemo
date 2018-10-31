#include <QtWidgets/QWidget>
#include <QVariantAnimation>

/**
* @author : 前行中的小猪;
* @date   : 2018年10月31日
* @version: 1.0
* @note   : Qt实现 鼠标点击 出现水滴的效果;

*@ 博客地址: https://blog.csdn.net/GoForwardToStep ;
**/

class WaterDrop : public QWidget
{
	Q_OBJECT

public:
	WaterDrop(QWidget *parent = Q_NULLPTR);
	~WaterDrop();
	
    // 设置水滴颜色;
    void setColor(QColor color);

    // 设置水滴半径;
    void setRadius(int radius);

    // 显示水滴;
    void showWaterDrop(const QPoint &point);

private:
	void paintEvent(QPaintEvent *event);

private slots :
	void onRaduisChanged(QVariant value);

private:
    // 水滴动画类;
	QVariantAnimation* m_waterDropAnimation;
    // 水滴实际半径;
    int m_waterDropRadisu;
	// 水滴变化的半径;
	int m_animationRadius;
	// 水滴的颜色;
	QColor m_waterDropColor;
};