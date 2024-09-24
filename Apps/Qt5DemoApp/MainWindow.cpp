#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ����һ����Ϊm_occWidget��OCCWidgetʵ��
    m_occWidget = new OCCWidget(this);
    // ��OCCWidget����Ϊ�����ڵ����벿��
    this->setCentralWidget(m_occWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
