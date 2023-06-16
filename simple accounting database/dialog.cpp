#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <fstream>
#include <QInputDialog>


using namespace std;


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

string filename("d://123.dat") ;
struct patient {char name[25];char city[25]; char diagnosis[25]; int age; }
d={"","","",0};


void Dialog::on_pushButton_clicked()
{
    bool ok;
        ofstream f("D:\\patient.dat",ios::app|ios::binary);
        if (!f){ ui->textEdit->append("Файл D:\\diod.dat не вдалося відкрити для запису!"); }
        else  {

         strcpy(d.name, QString(QInputDialog::getText(this,"Введення інформації про пацієнта","Ім'я:", QLineEdit::Normal,"", &ok )).toStdString().c_str()  );
         strcpy(d.city, QString(QInputDialog::getText(this,"Введення інформації про пацієнта","Місто:", QLineEdit::Normal,"", &ok )).toStdString().c_str()  );
         strcpy(d.diagnosis, QString(QInputDialog::getText(this,"Введення інформації про пацієнта","Діагноз:", QLineEdit::Normal,"", &ok )).toStdString().c_str()  );
         d.age=QInputDialog::getInt(this,"Введення інформації про пацієнта "+QString().fromStdString(d.name), "Вік:(A)", 0, 0, 100, 1, &ok);
         f.write((char*)&d, sizeof(d));
         ui->textEdit->append(QString("Ім'я: %1, Місто=%2 , Діагноз=%3 , вік=%4 років").arg(d.name).arg(d.city).arg(d.diagnosis).arg(d.age));
         }
}


void Dialog::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    bool ok=false;
       ifstream f("D:\\patient.dat",ios::in | ios::binary);
       if (!f) {
           ui->textEdit->append("Файл D:\\patient.dat не вдалося відкрити для читання!");
       }
       else {
           f.read((char*)&d,sizeof(d));
                  while (!f.eof() ) {
                         if(strstr(d.city,ui->lineEdit->text().toStdString().c_str())==0) {
                             ui->textEdit->append(QString("Ім'я: %1, Місто=%2 , Діагноз=%3 , вік=%4 років").arg(d.name).arg(d.city).arg(d.diagnosis).arg(d.age));
                           ok=true;
                         }
                  f.read((char*)&d,sizeof(d));
                  }
                  if(!ok) ui->textEdit->append("Пацієнт з міста відміного від: "+ui->lineEdit->text()+" не знайден в базі!");
       }
}


void Dialog::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
    bool ok=false;
       ifstream f("D:\\patient.dat",ios::in | ios::binary);
       if (!f) {
           ui->textEdit->append("Файл D:\\patient.dat не вдалося відкрити для читання!");
       }
       else {
           f.read((char*)&d,sizeof(d));
                  while (!f.eof() ) {
                         if(strstr(d.diagnosis,ui->lineEdit_3->text().toStdString().c_str())!=0&&d.age>=ui->lineEdit_2->text().toInt() ) {
                             ui->textEdit->append(QString("Ім'я: %1, Місто=%2 , Діагноз=%3 , вік=%4 років").arg(d.name).arg(d.city).arg(d.diagnosis).arg(d.age));
                           ok=true;
                         }
                  f.read((char*)&d,sizeof(d));
                  }
                  if(!ok) ui->textEdit->append("Підходящого пацієнта з діагнозом: "+ui->lineEdit_3->text()+ " віком від " + ui->lineEdit_2->text() + " не знайден в базі!");
       }

}

