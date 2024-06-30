#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mySkin[0] = {QColor(252,77,62),QColor(21,23,49),QColor(200,29,14),"252,77,62","21,23,49"};
    mySkin[1] = {QColor(49,177,72),QColor(26,142,199),QColor(61,222,85),"49,177,72","26,142,199"};
    mySkin[2] = {QColor(138,103,205),QColor(137,204,208),QColor(122,64,232),"138,103,205","137,204,208"};
    mySkin[3] = {QColor(252,53,152),QColor(83,207,199),QColor(200,30,114),"252,53,152","83,207,199"};
    curr_skin = 0;

    list_btn << ui->btn_1 << ui->btn_2 << ui->btn_3 << ui->btn_4;
    for(uint8_t i = 0;i < 4; i++)
    {
       list_btn[i]->setStyleSheet("background:transparent;color:rgb(255,255,255)");
       connect(list_btn[i],SIGNAL(clicked(bool)),this,SLOT(slot_btn_changed(void)));
    }
    list_btn[0]->setStyleSheet("background:transparent;color:rgb(252,77,62)");

    spline_init();      //曲线初始化
    pie_init();         //饼状图初始化
    bar_init();         //柱状图初始化
    progressbar_init(); //进度条初始化

    //定时器初始化

    time_run = new QTimer(this);
    // connect(time_run,SIGNAL(timeout()),this,SLOT(slot_spline_roll()));
    // connect(time_run,SIGNAL(timeout()),this,SLOT(slot_pie_roll()));
    // connect(time_run,SIGNAL(timeout()),this,SLOT(slot_bar_roll()));
    connect(time_run,SIGNAL(timeout()),this,SLOT(slot_progressBar_start()));
    time_run->start(500);


    slot_spline_roll();
    slot_pie_roll();
    slot_bar_roll();
}

void Widget::slot_btn_changed(void)
{
    for(uint8_t i = 0;i < 4; i++)
    {
       list_btn[i]->setStyleSheet("background:transparent;color:rgb(255,255,255)");
    }

    QPushButton* btn = qobject_cast<QPushButton*>(sender());//获取发射信号的对象
    QString BtnName= btn->objectName();//获取按钮定义的对象名称

    if(BtnName == "btn_1")
    {
        curr_skin = 0;
        ui->frame_left->setStyleSheet("background-color: rgb(21,23,49);");
        ui->frame_lefttop->setStyleSheet("background-color: rgb(252,77,32);");
        QString str = QString("background:transparent;color:rgb(252,77,32)");
        list_btn[0]->setStyleSheet(str);
    }
    else if(BtnName == "btn_2")
    {
        curr_skin = 1;
        ui->frame_left->setStyleSheet("background-color: rgb(49,177,72);");
        ui->frame_lefttop->setStyleSheet("background-color: rgb(26,142,199);");
        QString str = QString("background:transparent;color:rgb(254,208,47)");
        list_btn[1]->setStyleSheet(str);
    }
    else if(BtnName == "btn_3")
    {
        curr_skin = 2;
        ui->frame_left->setStyleSheet("background-color: rgb(138,103,205);");
        ui->frame_lefttop->setStyleSheet("background-color: rgb(137,204,208);");
        QString str = QString("background:transparent;color:rgb(254,208,47)");
        list_btn[2]->setStyleSheet(str);

    }
    else if(BtnName == "btn_4")
    {
        curr_skin = 3;
        ui->frame_left->setStyleSheet("background-color: rgb(252,53,152);");
        ui->frame_lefttop->setStyleSheet("background-color: rgb(83,207,199);");
        QString str = QString("background:transparent;color:rgb(254,208,47)");
        list_btn[3]->setStyleSheet(str);
    }

    slot_spline_roll();
    slot_pie_roll();
    slot_bar_roll();
}


Widget::~Widget()
{
    delete ui;
}
