#include "widget.h"
#include "ui_widget.h"

void Widget::progressbar_init(void)
{
    //实例化动画类
    m_vAnimation = new QVariantAnimation(this);
    if (m_vAnimation) {
        m_vAnimation->setDuration(200);
        m_vAnimation->setKeyValueAt(0, 0.0);
        //m_vAnimation->setKeyValueAt(0.5, 0.1);
        m_vAnimation->setKeyValueAt(1, 0.5);
        m_vAnimation->setLoopCount(-10);
        m_vAnimation->start();
        connect(m_vAnimation, &QVariantAnimation::valueChanged, this, &Widget::sltAtIndexChanged);
    }

    //进度条初始值
    prograss_value[0] = 0;
    prograss_value[1] = 0;
    prograss_value[2] = 0;
    prograss_value[3] = 0;


   list_progressBar << ui->progressBar_1 << ui->progressBar_2 << ui->progressBar_3 << ui->progressBar_4;
   list_label << ui->label_1 << ui->label_2 << ui->label_3 << ui->label_4;
   for(uint8_t i = 0; i < 4; i++)
   {
       list_progressBar[i]->setOrientation(Qt::Horizontal);// 水平方向
       list_progressBar[i]->setMinimum(0);// 最小值
       list_progressBar[i]->setMaximum(100);// 最大值

       list_progressBar[i]->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式
       list_progressBar[i]->setTextVisible(false);
       list_progressBar[i]->resize(400,12);
       list_progressBar[i]->setValue(prograss_value[i]);
       QString prograss_skin = QString("QProgressBar{border-radius:6px;border:none;background:rgb(%1);}"
                                       "QProgressBar::chunk{background:rgb(%2);border-radius:6px;}")
                                .arg(mySkin[curr_skin].progress_color2).arg(mySkin[curr_skin].progress_color1);

       list_progressBar[i]->setStyleSheet(prograss_skin);
   }
    ui->frame->setStyleSheet("background-color: rgb(255, 255, 255);");
}

/*进度条滑动的动画槽*/
/*根据QVariantAnimation的制定的步长，每走一步触发该槽函数，实现进度条动态滑动的效果*/
void Widget::sltAtIndexChanged(QVariant value)
{
    QString prograss_skin = QString("QProgressBar{border-radius:6px;border:none;background:rgb(%1);}"
                                    "QProgressBar::chunk{background:rgb(%2);border-radius:6px;}")
                             .arg(mySkin[curr_skin].progress_color2).arg(mySkin[curr_skin].progress_color1);


    static bool dirc[4];//进度条的方向 true为加，false为减
    for(uint8_t i = 0; i < 4;i++)
    {
        list_progressBar[i]->setStyleSheet(prograss_skin);
        if(flag_start[i] == 1)
        {
            if(dirc[i])list_progressBar[i]->setValue(prograss_value[i]++);  //向右递增
            if(!dirc[i])list_progressBar[i]->setValue(prograss_value[i]--); //向左递减
            list_label[i]->setText(QString("%1%").arg(prograss_value[i]));  //刷新数据显示
        }
    }

//    if(flag_start_1 == 1)//启动进度条1的滑动效果
//    {
//        if(dirc[0])ui->progressBar_1->setValue(prograss_value[0]++);
//        if(!dirc[0])ui->progressBar_1->setValue(prograss_value[0]--);
//        ui->label_1->setText(QString("%1%").arg(prograss_value[0]));
//    }
//    if(flag_start_2 == 1)//启动进度条2的滑动效果
//    {
//      if(dirc[1])ui->progressBar_2->setValue(prograss_value[1]++);
//      if(!dirc[1])ui->progressBar_2->setValue(prograss_value[1]--);
//      ui->label_2->setText(QString("%1%").arg(prograss_value[0]));
//    }
//    if(flag_start_3 == 1)//启动进度条3的滑动效果
//    {
//        if(dirc[2])ui->progressBar_3->setValue(prograss_value[2]++);
//        if(!dirc[2])ui->progressBar_3->setValue(prograss_value[2]--);
//        ui->label_3->setText(QString("%1%").arg(prograss_value[0]));
//    }
//    if(flag_start_4 == 1)//启动进度条4的滑动效果
//    {
//        if(dirc[3])ui->progressBar_4->setValue(prograss_value[3]++);
//        if(!dirc[3])ui->progressBar_4->setValue(prograss_value[3]--);
//        ui->label_4->setText(QString("%1%").arg(prograss_value[0]));
//    }

    /*进度条的滑动方向改变*/
    for(uint8_t i = 0;i < 4;i++)
    {
        if(prograss_value[i] > 100)
        {
            dirc[i] = !dirc[i];
        }else if(prograss_value[i] < 0)
        {
            dirc[i] = !dirc[i];
        }
    }
}

/*启动进度条滑动的顺序*/
void Widget::slot_progressBar_start(void)
{
    static int i = 0;
    i++;
    if(i == 1)flag_start[0] = 1;//启动第一条进度条滑动
    else if(i == 2)flag_start[1] = 1;//启动第二条进度条滑动
    else if(i == 3)flag_start[2] = 1;//启动第三条进度条滑动
    else if(i == 4)flag_start[3] = 1;//启动第四条进度条滑动
}




