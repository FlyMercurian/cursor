#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , timerCount(0)
{
    ui->setupUi(this);
    
    initui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initui()
{
    // 连接按钮点击信号到槽函数
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    
    // 连接定时器超时信号到槽函数
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    
    // 设置定时器间隔为1秒
    timer->setInterval(1000);
}

void MainWindow::onButtonClicked()
{
    if (timer->isActive()) {
        // 如果定时器正在运行，停止它
        timer->stop();
        ui->pushButton->setText("开始计时");
        ui->lineEdit->setText("计时已停止");
    } else {
        // 如果定时器没有运行，启动它
        timerCount = 0;
        timer->start();
        ui->pushButton->setText("停止计时");
        ui->lineEdit->setText("计时中 0");
    }
}

void MainWindow::onTimerTimeout()
{
    timerCount++;
    QString timerText = QString("计时中 %1").arg(timerCount);
    ui->lineEdit->setText(timerText);
}
