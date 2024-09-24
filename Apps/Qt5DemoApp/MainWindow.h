#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "OCCWidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    OCCWidget* m_occWidget = nullptr;
};

#endif // MAINWINDOW_H
