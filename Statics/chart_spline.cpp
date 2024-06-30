#include "widget.h"
#include "ui_widget.h"
void Widget::spline_init()
{

    spline_maxSize = 20;//设置曲线的X坐标的个数
    series_spline = new QSplineSeries();                         // 创建一个样条曲线对象
    series_spline->setPen(QPen(mySkin[curr_skin].color_1,4));
    Chart_spline = ui->graphicsView_spline->chart();             // 获取一个chart用于管理不同类型的series和其他图表相关对象
    Chart_spline->setAnimationOptions(QChart::SeriesAnimations);
    Chart_spline->setAnimationDuration(500);
    Chart_spline->legend()->hide();                              // 隐藏图例
    Chart_spline->addSeries(series_spline);                      // 添加创建好的曲线图对象
    QFont font_spline("Microsoft YaHei",18);
    Chart_spline->setTitleFont(font_spline);
    Chart_spline->setTitle("专注时段");                     // 设置标题
    Chart_spline->createDefaultAxes();                           // 基于已添加到图表中的series为图表创建轴。以前添加到图表中的任何轴都将被删除。
    Chart_spline->axes(Qt::Horizontal).first()->setRange(0, 190);// 设置Y轴的范围
    Chart_spline->axes(Qt::Vertical).first()->setRange(0, 20);   // 设置Y轴的范围

    //批量添加数据
    QList<QPointF> points;
    for(int i = 0; i < spline_maxSize; i++)
    {
        points.append(QPointF(i*10, rand() %15));
    }
    series_spline->replace(points);

    ui->graphicsView_spline->setRenderHint(QPainter::Antialiasing);  // 设置抗锯齿

}

/*刷新数据*/
void Widget::slot_spline_roll()
{
    qDebug() << curr_skin;
    series_spline->setPen(QPen(mySkin[curr_skin].color_1,4));
    for(int i = 0; i < spline_maxSize; i++)
    {
        series_spline->replace(i*10,series_spline->at(i).y(),i*10, 3+rand() %15);
    }
}
