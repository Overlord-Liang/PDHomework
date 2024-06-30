#include "widget.h"
#include "ui_widget.h"

void Widget::bar_init()
{
    barH = new QBarSet("High");         //设置上方数据
    barH->setColor(mySkin[curr_skin].color_1);   //设置颜色
    barL = new QBarSet("Low");          //设置下方数据
    barL->setColor(mySkin[curr_skin].color_2);  //设置颜色
    *barL << -22 << -10 << -9.3 << -17.0 << -15.6 << -8.0
      << -6.0 << -11.8 << -9.7 << -12.8 << -23.0 << -28.0;
    *barH << 11.9 << 12.8 << 18.5 << 26.5 << 32.0 << 34.8
       << 38.2 << 34.8 << 29.8 << 20.4 << 15.1 << 11.8;

     series_bar = new QStackedBarSeries(this);
     //添加数据
     series_bar->append(barL);
     series_bar->append(barH);

     Chart_bar = new QChart();
     Chart_bar->addSeries(series_bar);
     QFont font_spline("Microsoft YaHei",18);
     Chart_bar->setTitleFont(font_spline);
     Chart_bar->setTitle("专注时长");                         // 设置标题
     Chart_bar->setAnimationOptions(QChart::SeriesAnimations);  //开启动画效果
     Chart_bar->setAnimationDuration(1000);

     //设置X轴
     QBarCategoryAxis *axisX = new QBarCategoryAxis();
     QStringList strlist = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
     axisX->append(strlist);
     Chart_bar->addAxis(axisX,Qt::AlignBottom); //设置X坐标位置
     //设置Y轴
     QValueAxis *axisY = new QValueAxis();
     axisY->setRange(-30,40);

     Chart_bar->addAxis(axisY,Qt::AlignLeft);   //设置Y坐标位置
     series_bar->attachAxis(axisX);
     series_bar->attachAxis(axisY);

     ui->graphicsView_bar->setRenderHint(QPainter::Antialiasing);// 设置抗锯齿
     ui->graphicsView_bar->setChart(Chart_bar);
}

/*更新数据*/
void Widget::slot_bar_roll(void)
{
    barH->setColor(mySkin[curr_skin].color_1);   //设置颜色
    barL->setColor(mySkin[curr_skin].color_2);  //设置颜色

    for(int i  = 0;i < 12; i++)
    {
        barH->replace(i,rand()%40);
        barL->replace(i,-rand()%30);
    }
}


