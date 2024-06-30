#include "widget.h"
#include "ui_widget.h"

void Widget::pie_init(void)
{
    series_pie = new QPieSeries();
    series_pie->setHoleSize(0.35);//设置中心圆大小
    //设置每个饼块的大小
    series_pie->append("Color1",4.2);
    series_pie->append("Color2",56.4);
    series_pie->append("Color3",23.8);

    //添加颜色
    series_pie->slices().at(0)->setColor(mySkin[curr_skin].color_1);
    series_pie->slices().at(1)->setColor(mySkin[curr_skin].color_2);
    series_pie->slices().at(2)->setColor(mySkin[curr_skin].color_3);


    Chart_pie = new QChart();
    //chart开始动画模式
    Chart_pie->setAnimationOptions(QChart::SeriesAnimations);
    Chart_pie->setAnimationDuration(500);

    Chart_pie->addSeries(series_pie);
    Chart_pie->legend()->setAlignment(Qt::AlignBottom);
    Chart_pie->legend()->setFont(QFont("Arial",7));
    QFont font_spline("Microsoft YaHei",18);
    Chart_pie->setTitleFont(font_spline);
    Chart_pie->setTitle("时间分配比例");           // 设置标题

    ui->graphicsView_pie->setRenderHint(QPainter::Antialiasing);// 设置抗锯齿
    ui->graphicsView_pie->setChart(Chart_pie);
}


//刷新数据
void Widget::slot_pie_roll(void)
{

    int data1 = rand()%30;
    int data2 = rand()%30;
    int data3 = rand()%40;

    series_pie->clear();
    series_pie->setHoleSize(0.35);
    //重新添加数据
    series_pie->append(QString("Color1"),data1);
    series_pie->append(QString("Color2"),data2);
    series_pie->append(QString("Color3"),data3);

    //设置颜色
    series_pie->slices().at(0)->setColor(mySkin[curr_skin].color_1);
    series_pie->slices().at(1)->setColor(mySkin[curr_skin].color_2);
    series_pie->slices().at(2)->setColor(mySkin[curr_skin].color_3);
}
