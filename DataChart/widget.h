#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QValueAxis>

#include <QChart>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QPieSeries>
#include <QLineSeries>
#include <QBarSeries>
#include <QBarset>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>

#include <QProgressBar>
#include <QLabel>
#include <QPushButton>


#include <QVariantAnimation>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private:
    Ui::Widget *ui;

public:
    QList<QPushButton*> list_btn;
public slots:
    void slot_btn_changed();



/*曲线图-start*/
public:
    QTimer* time_run;
    QChart* Chart_spline;
    QSplineSeries* series_spline;
    int spline_maxSize;
    void spline_init(void);
public slots:
    void slot_spline_roll(void);
/*曲线图-end*/



/*饼状图-start*/
public:
    QChart* Chart_pie;
    QPieSeries* series_pie;
    void pie_init(void);
public slots:
    void slot_pie_roll(void);
/*饼状图-end*/

/*柱状图-start*/
public:
    QStackedBarSeries * series_bar;
    QChart* Chart_bar;
    QBarSet *barH;
    QBarSet *barL;
    void bar_init(void);
public slots:
    void slot_bar_roll(void);
/*柱状图-end*/


/*进度条*start*/
public:
    QVariantAnimation* m_vAnimation;
    QList<QProgressBar*> list_progressBar;
    QList<QLabel*> list_label;
    int flag_start[4];           //进度条滑动的开始标志位
    int prograss_value[4];      //进度条的数值
    void progressbar_init(void);//进度条初始化
public slots:
    void sltAtIndexChanged(QVariant value);
    void slot_progressBar_start(void);
/*进度条-end*/


/*内容换肤*/
public:
    struct colorSkin
    {
        QColor color_1;
        QColor color_2;
        QColor color_3;
        QString progress_color1;
        QString progress_color2;
    };
    colorSkin mySkin[4];
    int curr_skin;//当前皮肤
};

#endif // WIDGET_H
