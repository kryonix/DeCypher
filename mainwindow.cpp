#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QtAlgorithms>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Totally awesome DeCypher Tool");

    key.push_back(ui->lineEdit);
    key.push_back(ui->lineEdit_2);
    key.push_back(ui->lineEdit_3);
    key.push_back(ui->lineEdit_4);
    key.push_back(ui->lineEdit_5);
    key.push_back(ui->lineEdit_6);
    key.push_back(ui->lineEdit_7);
    key.push_back(ui->lineEdit_8);
    key.push_back(ui->lineEdit_9);
    key.push_back(ui->lineEdit_10);
    key.push_back(ui->lineEdit_11);
    key.push_back(ui->lineEdit_12);
    key.push_back(ui->lineEdit_13);
    key.push_back(ui->lineEdit_14);
    key.push_back(ui->lineEdit_15);
    key.push_back(ui->lineEdit_16);
    key.push_back(ui->lineEdit_17);
    key.push_back(ui->lineEdit_18);
    key.push_back(ui->lineEdit_19);
    key.push_back(ui->lineEdit_20);
    key.push_back(ui->lineEdit_21);
    key.push_back(ui->lineEdit_22);
    key.push_back(ui->lineEdit_23);
    key.push_back(ui->lineEdit_24);
    key.push_back(ui->lineEdit_25);
    key.push_back(ui->lineEdit_26);

    percent.push_back(ui->p_1);
    percent.push_back(ui->p_2);
    percent.push_back(ui->p_3);
    percent.push_back(ui->p_4);
    percent.push_back(ui->p_5);
    percent.push_back(ui->p_6);
    percent.push_back(ui->p_7);
    percent.push_back(ui->p_8);
    percent.push_back(ui->p_9);
    percent.push_back(ui->p_10);
    percent.push_back(ui->p_11);
    percent.push_back(ui->p_12);
    percent.push_back(ui->p_13);
    percent.push_back(ui->p_14);
    percent.push_back(ui->p_15);
    percent.push_back(ui->p_16);
    percent.push_back(ui->p_17);
    percent.push_back(ui->p_18);
    percent.push_back(ui->p_19);
    percent.push_back(ui->p_20);
    percent.push_back(ui->p_21);
    percent.push_back(ui->p_22);
    percent.push_back(ui->p_23);
    percent.push_back(ui->p_24);
    percent.push_back(ui->p_25);
    percent.push_back(ui->p_26);

    timer.setInterval(500);
//    connect(this, SLOT(tTimer()), &timer, SIGNAL(timeout()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(tTimer()));

    timer.start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plainTextEdit_textChanged()
{
    QString strCipher = ui->plainTextEdit->toPlainText();

    int a[26];
    int sum = 0;
    for(int i = 0; i < percent.size(); i++)
    {
        char rep = 'A'+i;
        a[i] = 0;

        for(int j = 0; j < strCipher.length(); j++)
        {
            if(strCipher.at(j) == rep)
            {
                ++a[i];
            }
        }
        sum += a[i];
    }

    for(int i = 0; i < 26; i++)
    {
        percent.at(i)->setText(QString("%1\n%2").arg(a[i]).arg((100*a[i]/(double)sum), 0, 'f', 1));
    }
}

void MainWindow::tTimer()
{
    translate();

    for(int i = 0; i < key.size(); i++)
    {
        QString t = key.at(i)->text();
        if(t.length() == 0) continue;
        bool lower = false;
        for(int j = 'a'; j <= 'z'; j++)
        {
            if(t.at(0) == (char)j)
            {
                lower = true;
                break;
            }
        }

        if(lower)
        {
            key.at(i)->setStyleSheet("QLineEdit {background-color: red;}");
        }
        else
        {
            key.at(i)->setStyleSheet("QLineEdit {background-color: white;}");
        }
    }
}

void MainWindow::translate()
{
    QString strCipher = ui->plainTextEdit->toPlainText();

    for(int i = 0; i < key.size(); i++)
    {
        char rep = 'A'+i;

        strCipher.replace(QString(rep),key.at(i)->text());
    }

    ui->plainTextEdit_2->setPlainText(strCipher);
}

void MainWindow::on_pushButton_clicked()
{
    double per[] = {6.5, 1.9, 2.9,
                    4.9, 17.5, 1.7,
                    3.0, 4.5, 7.7,
                    0.3, 1.3, 3.5,
                    2.5, 9.8, 2.7,
                    0.9, 0.03, 7.2,
                    7.1, 6.1, 4.3,
                    0.8, 1.7, 0.03,
                    0.03, 1.1};

    QString strCipher = ui->plainTextEdit->toPlainText();

    int a[26];
    int sum = 0;
    for(int i = 0; i < percent.size(); i++)
    {
        char rep = 'A'+i;
        a[i] = 0;

        for(int j = 0; j < strCipher.length(); j++)
        {
            if(strCipher.at(j) == rep)
            {
                ++a[i];
            }
        }
        sum += a[i];
    }

    QVector<int> ch;
    int reih[] = {4, 13, 8, 17, 18, 0, 19, 3, 7};

    for(int i = 0; i < 26; i++) ch.push_back(i);

    for(int i = 0; i < 9; i++)
    {
        int pos = reih[i];//i;//ch.at(i);
        double pi = 100*a[pos]/(double)sum;
        int best = 0;
        double val = std::abs(per[ch.at(0)]-pi);

        for(int j = 1; j < ch.size(); j++)
        {
            if(std::abs(per[ch.at(j)]-pi) < val)
            {
                best = j;
                val = std::abs(per[ch.at(j)]-pi);
            }
        }

        key.at(pos)->setText(QString((char)ch.at(best)+'a'));
        ch.remove(best);
    }
}
