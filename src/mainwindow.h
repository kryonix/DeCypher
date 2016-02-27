#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QLineEdit>
#include <QTimer>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_plainTextEdit_textChanged();

    void tTimer();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QLineEdit*> key;
    QVector<QLabel*> percent;
    void translate();
    QTimer timer;
};

#endif // MAINWINDOW_H
