#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QComboBox>
#include <cmath>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
//бібліотеки


//задання початкового інтерфейсу, конструктор форми
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //запуск додатку, стандартні опції прямий дріт
    ui->label->setText(QString("l="));
    ui->label_2->setText(QString("d="));
    ui->textEdit->setText(QString("l-довжина дрота,см\nd-діаметр,см"));
    ui->checkBox->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();

    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();


}
//деконструктор стандартної форми
MainWindow::~MainWindow()
{
    delete ui;
}

//вивід першої картинки на екран
void MainWindow::paintEvent(QPaintEvent *event)
{    QPainter painter(this);
     QImage img1(":/new/prefix1/1.png");
     painter.drawImage(160,10,img1);
}

bool chk;int CmbId=0,ChkId=0;

void MainWindow::on_comboBox_currentIndexChanged(int ComboID)
//у цьому блоці буде зміна інтерфейсу під потреби користовуча по "флажкам" bool chk int cmbBox chkBox , після зміни об'єкту розрахунку
{
   //задамо піксельні карти для зміни зоображень

     QImage img1(":/new/prefix1/1.png");
     QImage img2(":/new/prefix2/2.png");
     QImage img3(":/new/prefix3/3.png");
     QImage img4(":/new/prefix4/4.png");
     QPixmap pix1 = QPixmap::fromImage(img1);
     QPixmap pix2 = QPixmap::fromImage(img2);
     QPixmap pix3 = QPixmap::fromImage(img3);
     QPixmap pix4 = QPixmap::fromImage(img4);
     ui->label_6->setPixmap(pix1);

    CmbId=ComboID;

    switch ( CmbId){
    case 0:///дріт
        //зміни в інтерфейсі приклад

        ui->label_6->setPixmap(pix1);//установка зоображенння

        ui->label->show(); //видимі label , lineEdit
        ui->label_2->show();
        ui->lineEdit->show();
        ui->lineEdit_2->show();

        ui->label->setText(QString("l="));//задання тексту label
        ui->label_2->setText(QString("d="));
        ui->textEdit->setText(QString("l-довжина дрота,см\nd-діаметр,см"));

        ui->checkBox->hide();  //не видимі label , lineEdit, chkbox
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();

        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();


        break;
    case 1:///виток

        ui->label_6->setPixmap(pix2);


        ui->label->show();
        ui->label_2->show();
        ui->lineEdit->show();
        ui->lineEdit_2->show();

        ui->label->setText(QString("D="));
        ui->label_2->setText(QString("d="));
        ui->textEdit->setText(QString("D-діаметр витка,мм\nd-діаметр дрота,см"));

        ui->checkBox->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();

        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();


        break;
    case 2:

        ui->label_6->setPixmap(pix3);


        if(ChkId==0){///індуктивність одношарової


            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();

            ui->label->setText(QString("D="));
            ui->label_2->setText(QString("l="));
            ui->label_3->setText(QString("n="));
            ui->textEdit->setText(QString("D-діаметр котушки,см\nl-довжина намотки котушки,см\nn-кількість витків"));

            ui->checkBox->show();

            ui->label_4->hide();
            ui->label_5->hide();

            ui->lineEdit_4->hide();
            ui->lineEdit_5->hide();

        }
        else {///виткі одношарової

            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();

            ui->label->setText(QString("D="));
            ui->label_2->setText(QString("l="));
            ui->label_3->setText(QString("L="));
            ui->textEdit->setText(QString("D-діаметр котушки,см\nl-довжина обмотки котушки,мм\nL-індуктивність,мкГн"));

            ui->checkBox->show();

            ui->label_4->hide();
            ui->label_5->hide();

            ui->lineEdit_4->hide();
            ui->lineEdit_5->hide();

        }

        break;
    case 3:

        ui->label_6->setPixmap(pix4);

        if(ChkId==0){///індуктивність на кільці
              ui->checkBox->show();
              ui->label->show();
              ui->label_2->show();
              ui->label_3->show();
              ui->label_4->show();
              ui->label_5->show();
              ui->lineEdit->show();
              ui->lineEdit_2->show();
              ui->lineEdit_3->show();
              ui->lineEdit_4->show();
              ui->lineEdit_5->show();


            ui->label->setText(QString("m="));
            ui->label_2->setText(QString("n="));
            ui->label_3->setText(QString("D="));
            ui->label_4->setText(QString("d="));
            ui->label_5->setText(QString("h="));
            ui->textEdit->setText(QString("m-магнітна проникність\nn-кількість витків\nD-звонішній діаметр,м\nd-внутрішній діаметр,м\nh-вистота,м"));

        }
        else {///виткі на кільці
            ui->checkBox->show();
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->label_4->show();
            ui->label_5->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();
            ui->lineEdit_4->show();
            ui->lineEdit_5->show();

            ui->label->setText(QString("m="));
            ui->label_2->setText(QString("L="));
            ui->label_3->setText(QString("D="));
            ui->label_4->setText(QString("d="));
            ui->label_5->setText(QString("h="));
            ui->textEdit->setText(QString("m-магнітна проникність\nL-індуктивність котушкі,Гн\nD-звонішній діаметр,м\nd-внутрішній діаметр,м\nh-вистота,м"));


        }
        break;
    }
}


void MainWindow::on_pushButton_clicked()
{//блок рохрахунків при події натискання кнопки


    double L,l,n,D,d,m,m0,h;
    switch (CmbId){
    case 0:///дріт
        l=ui->lineEdit->text().toDouble();
        d=ui->lineEdit_2->text().toDouble();
        L=0.00508*l*(log10(2*l/d)-0.75);
        if(L<=0){
             ui->textEdit->append(QString("Помилка! спробуйте інші праметри"));

        }
        else
        ui->textEdit->append(QString("Індуктивність дрота L=%1 нГн.").arg(L));
        break;
    case 1:///виток
         D=ui->lineEdit->text().toDouble();
         d=ui->lineEdit_2->text().toDouble();
         L=2*D*(log(D/d)-1.75);
         if(L<=0){
              ui->textEdit->append(QString("Помилка! спробуйте інші праметри"));
         }
         else
         ui->textEdit->append(QString("Індуктивність дрота L=%1 мкГн.").arg(L));
        break;
    case 2:
        if(ChkId==0){///індуктивність одношарової
            D=ui->lineEdit->text().toDouble();
            l=ui->lineEdit_2->text().toDouble();
            n=ui->lineEdit_3->text().toDouble();
            L=(D*D*n*n)/(45*D+100*l);
            if(L<=0){
                 ui->textEdit->append(QString("Помилка! спробуйте інші праметри"));
            }
            else
            ui->textEdit->append(QString("Індуктивність котушки L=%1 мкГн.").arg(L));

        }
        else {///виткі одношарової
            D=ui->lineEdit->text().toDouble();
            l=ui->lineEdit_2->text().toDouble();
            L=ui->lineEdit_3->text().toDouble();
            n=sqrt(5*L*(9*D+20*l))/D;
            d=l/n;
            if(n<=0&&d<=0){
                 ui->textEdit->append(QString("Помилка! спробуйте інші праметри"));
            }
            else
            ui->textEdit->append(QString("Кількість витків котушки n=%1, при діаметрі d=%2,мм").arg(n).arg(d));

        }

        break;
    case 3:
        if(ChkId==0){///індуктивність на кільці
            m=ui->lineEdit->text().toDouble();
            n=ui->lineEdit_2->text().toDouble();
            D=ui->lineEdit_3->text().toDouble();
            d=ui->lineEdit_4->text().toDouble();
            h=ui->lineEdit_5->text().toDouble();
            m0=1,256637*pow(10,(-6));
            L = m * m0 * pow(n,2) * (h*(D - d)/2) / (M_PI*(D + d)/2);
            if(L<=0){
                 ui->textEdit->append(QString("Помилка! спробуйте інші праметри"));
            }
            else
            ui->textEdit->append(QString("Індуктивність котушки L=%1 мкГн.").arg(L));

        }
        else {///виткі на кільці
            m=ui->lineEdit->text().toDouble();
            L=ui->lineEdit_2->text().toDouble();
            D=ui->lineEdit_3->text().toDouble();
            d=ui->lineEdit_4->text().toDouble();
            h=ui->lineEdit_5->text().toDouble();
            m0=1,256637*pow(10,(-6));
            n=sqrt(L/m*m0*((h*(D-d)/2)/(M_PI*(D-d)/2)));
            if(n<=0){
                 ui->textEdit->append(QString("Помилка! спробуйте інші праметри"));
            }
            else
            ui->textEdit->append(QString("Кількість витків котушки n=%1 мкГн.").arg(n));
        }
        break;
    }
}


void MainWindow::on_checkBox_stateChanged(int CheckID){
   //зміна інтерфейсу при натисканні галочки

    ChkId=CheckID;

    QMessageBox msgBox;
    if ( ChkId==0){ ///дріт
        if(CmbId==2){///індуктивність одношарової
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();

            ui->label->setText(QString("D="));
            ui->label_2->setText(QString("l="));
            ui->label_3->setText(QString("n="));
            ui->textEdit->setText(QString("D-діаметр котушки,см\nl-довжина намотки котушки,см\nn-кількість витків"));

            ui->checkBox->show();

            ui->label_4->hide();
            ui->label_5->hide();

            ui->lineEdit_4->hide();
            ui->lineEdit_5->hide();

        }
        else if (CmbId==3) {///індуктивність на кільці
            ui->checkBox->show();
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->label_4->show();
            ui->label_5->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();
            ui->lineEdit_4->show();
            ui->lineEdit_5->show();


          ui->label->setText(QString("m="));
          ui->label_2->setText(QString("n="));
          ui->label_3->setText(QString("D="));
          ui->label_4->setText(QString("d="));
          ui->label_5->setText(QString("h="));
          ui->textEdit->setText(QString("m-магнітна проникність\nn-кількість витків\nD-звонішній діаметр,м\nd-внутрішній діаметр,м\nh-вистота,м"));


        }
    }



    else if(ChkId==2){

        if(CmbId==2){///виткі одношарової
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();

            ui->label->setText(QString("D="));
            ui->label_2->setText(QString("l="));
            ui->label_3->setText(QString("L="));
            ui->textEdit->setText(QString("D-діаметр котушки,см\nl-довжина обмотки котушки,мм\nL-індуктивність,мкГн"));

            ui->checkBox->show();

            ui->label_4->hide();
            ui->label_5->hide();

            ui->lineEdit_4->hide();
            ui->lineEdit_5->hide();

        }
         else if (CmbId==3) {///виткі на кільці
            ui->checkBox->show();
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->label_4->show();
            ui->label_5->show();
            ui->lineEdit->show();
            ui->lineEdit_2->show();
            ui->lineEdit_3->show();
            ui->lineEdit_4->show();
            ui->lineEdit_5->show();

            ui->label->setText(QString("m="));
            ui->label_2->setText(QString("L="));
            ui->label_3->setText(QString("D="));
            ui->label_4->setText(QString("d="));
            ui->label_5->setText(QString("h="));
            ui->textEdit->setText(QString("m-магнітна проникність\nL-індуктивність котушкі,Гн\nD-звонішній діаметр,м\nd-внутрішній діаметр,м\nh-вистота,м"));
        }
    }
}
void MainWindow::on_action_triggered()//меню про автора
{
    QMessageBox msgBox;
    msgBox.setText("Автор програми");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText("Штура Андрій, у рамках виконанння курсової роботи з дицсипліни: Програмування та алгоритмічні мови Чернігів 2022");
    msgBox.exec();
}
void MainWindow::on_action_QT_triggered()//меню про Qt
{
    QMessageBox msgBox;
    msgBox.setText("About QT");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText("Qt is a cross-platform application development framework for desktop, embedded and mobile. Supported Platforms include Linux, OS X, Windows, VxWorks, QNX, Android, iOS, BlackBerry, Sailfish OS and others. Qt is not a programming language on its own. It is a framework written in C++. A preprocessor, the MOC (Meta-Object Compiler), is used to extend the C++ language with features like signals and slots. Before the compilation step, the MOC parses the source files written in Qt-extended C++ and generates standard compliant C++ sources from them. Thus the framework itself and applications/libraries using it can be compiled by any standard compliant C++ compiler like Clang, GCC, ICC, MinGW and MSVC.");
    msgBox.exec();

}
void MainWindow::on_action_2_triggered()//меню переходів до розрахунків
{
    //дріт

    ui->comboBox->setCurrentIndex(0);


}
void MainWindow::on_action_3_triggered()
{
    ui->comboBox->setCurrentIndex(1);

}
void MainWindow::on_action_4_triggered()
{
    ui->comboBox->setCurrentIndex(2);
    ui->checkBox->QAbstractButton::setChecked(false);

}
void MainWindow::on_action_5_triggered()
{
    ui->comboBox->setCurrentIndex(2);
    ui->checkBox->QAbstractButton::setChecked(true);

}
void MainWindow::on_action_6_triggered()
{
    ui->comboBox->setCurrentIndex(3);
    ui->checkBox->QAbstractButton::setChecked(false);

}
void MainWindow::on_action_7_triggered()
{
    ui->comboBox->setCurrentIndex(3);
    ui->checkBox->QAbstractButton::setChecked(true);
}
void MainWindow::on_action_8_triggered()//допомга по програмі
{
    QMessageBox msgBox;
    msgBox.setText("Допомога");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText(QString("Для користування програмою виберіть опцію розрахунку через меню, або скористувавшись користувацьким інтерфеском вибрати пункт, потім з клавіатуру ввести відповідні значення, та натуснути кнопку 'розрахунок' "));
    msgBox.exec();
}
void MainWindow::on_action_9_triggered()//допомога : виведення формул
{
    QMessageBox msgBox;
    msgBox.setText("Формули");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText(QString("Всі формули будуть виведені у тектове віконце"));
    msgBox.exec();

   ui->textEdit->setText(QString("Розрахунок індукції дроту: L=0.00508*l*(log10(2*l/d)-0.75)\n "));
   ui->textEdit->append(QString("Розрахунок індукції одного витку: L=2*D*(log(D/d)-1.75 \n "));
   ui->textEdit->append(QString("Розрахунок індукції одношарової котушки: L=(D*D*n*n)/(45*D+100*l) \n "));
   ui->textEdit->append(QString("Розрахунок витків одношарової котушки:\n n=кв.корінь з(5*L*(9*D+20*l))/D діаметр: d=l/n \n "));
   ui->textEdit->append(QString("Розрахунок індукції одношарової котушки:\n L = m * m0 * n^2 * (h*(D - d)/2) / (Пі*(D + d)/2)\n "));
   ui->textEdit->append(QString("Розрахунок витків одношарової котушки:\n n=кв.корінь з(L/m*m0*((h*(D-d)/2)/(Пі*(D-d)/2)))\n "));
   ui->textEdit->append(QString("Позначення: log10-десятковий логарифвм, log-натуральний логарифм\n, m0-константа  m0=1,256637*10^-6;"));
}
void MainWindow::on_action_10_triggered()//допомога : гарячі клавіши
{
    QMessageBox msgBox;
    msgBox.setText("Гарячі клавіши");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText(QString("Всі гарячі клавіши будуть виведені у тектове віконце"));
    msgBox.exec();

   ui->textEdit->setText(QString("Розрахунок індукції дроту: Alt+1 \n "));
   ui->textEdit->append(QString("Розрахунок індукції одного витку: Alt+2 \n "));
   ui->textEdit->append(QString("Розрахунок індукції одношарової котушки: Alt+3 \n "));
   ui->textEdit->append(QString("Розрахунок витків одношарової котушки: Alt+4\n "));
   ui->textEdit->append(QString("Розрахунок індукції одношарової котушки: Alt+5\n  "));
   ui->textEdit->append(QString("Розрахунок витків одношарової котушки: Alt+6\n  "));
}

