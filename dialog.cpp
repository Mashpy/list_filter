#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QDir myPath("E:/Best");
    myPath.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    myList = myPath.entryList();
    ui->listWidget->addItems(myList);
    ui->lblTotal->setText(QString("%1").arg(ui->listWidget->count()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1,Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget->clear();
    ui->listWidget->addItems(myList.filter(regExp));
    ui->lblTotal->setText(QString("%1").arg(ui->listWidget->count()));
}
