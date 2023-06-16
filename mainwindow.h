#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
     void paintEvent(QPaintEvent *event);
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_action_triggered();

    void on_action_QT_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
