#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cgraph.h>
#include"Generategraph.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<QDebug>
#include<QString>
#include<QFile>
#include<QFileDialog>
#include<QTextCodec>
#define MaxSize 1000
int getstringarray(string getfromfile, string* tmp);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int getstringarray(string getfromfile,string *tmp) {

    istringstream str(getfromfile);
    string out;
    int i = 0;
    while (str >> out) {
        //cout << out << endl;
        tmp[i++] = out;
    }
    return i ;//返回数组内元素个数；
}
void MainWindow::on_makegragh_clicked()
{
    string str[MaxSize];//存结点的string数组
    QString structure=ui->structure->currentText();
    QString nodemode_str=ui->nodeform->currentText();
    QString linemode_str=ui->lineform->currentText();
    string text=ui->textEdit->toPlainText().toStdString();
    string outpath=ui->lead_out_path->text().toStdString();
    int nodemode=(nodemode_str=="圆图"?0:1);
    int linemdoe=(linemode_str=="无向图"?0:1);
    if(structure=="树模式"){
        int n = getstringarray(text, str);
        GenerateGraph g;//生成图
        bool flag=g.Make_Tree(str,n,nodemode,linemdoe);
        if(!flag)QMessageBox::question(this,"提示！","内容为空！",QMessageBox::Ok);
        else QMessageBox::question(this,"提示！","绘制成功！",QMessageBox::Ok);
        g.Get_Jpg(outpath);
    }
    else if(structure=="自由模式"){
        int n = getstringarray(text, str);
        GenerateGraph g;//生成图
        bool flag=g.Make_Free(str,n,nodemode,linemdoe);
        if(!flag)QMessageBox::question(this,"提示！","内容为空或奇数个数据无法配对！",QMessageBox::Ok);
        else QMessageBox::question(this,"提示！","绘制成功！",QMessageBox::Ok);
        g.Get_Jpg(outpath);
    }

}


void MainWindow::on_lead_in_clicked()
{
        QString path=QFileDialog::getOpenFileName(this,"打开文件","");
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly))
        {
             QMessageBox::question(this,"提示！","未打开文件！",QMessageBox::Ok);
             return;
        }
        ui->lead_in_path->setVisible(1);
        ui->lead_in_path->setText(path);
        QByteArray array=file.readAll();
        QString data_in=QString(array);
        ui->textEdit->setText(data_in);
        QMessageBox::question(this,"提示！","导入成功！",QMessageBox::Ok);
}



