
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this); // обов'язкова частина

  QSqlDatabase mybd=QSqlDatabase::addDatabase("QSQLITE");
  mybd.setDatabaseName("C:/Qt/ProjectsQT/MyProjects/project29sqlite/копія.db");
  if (mybd.open())
  {
      ui->label->setText("База даних відкрита");
  }
  else
  {
      ui->label->setText("Закрита");
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    QString   query_string = "SELECT * FROM accountstotal;";
}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    auto   account = ui->lineEdit->text();
    QString   type    = ui->lineEdit_2->text();
    QString   amount  = ui->lineEdit_3->text();
    QString query_string = "insert into income(account, type, sum) values("+account+","+"'"+type+"',"+amount+");";
    //query.prepare("insert into income(account, type, sum) values(6,'інше',555);");
    //query.exec();
    if (query.exec(query_string))
    {
      ui->label->setText("Запис додано");
    }
    else
    {
      ui->label->setText("Запис не додано");
      qDebug() << query.lastError();
    }
}
