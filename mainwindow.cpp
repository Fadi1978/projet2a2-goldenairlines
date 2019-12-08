#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    son=new QSound("C:/Userswindows 10/DesktopPROJET 2A/musiqueqt.wav");

    ui->tabreservation->setModel(tmpreservation.afficher());
    ui->tabavion->setModel(tmpavion.afficher1());
    ui->tabtrie->setModel(tmpavion.affichertrie());
    ui->textpdf->hide();
    ui->tabcher->setModel(tmpreservation.afficher());
    ui->tabrech->setModel(tmpavion.afficher1());


    QPixmap pix3("C:/Users/windows 10/Desktop/PROJET 2A/acceuil");
    QPixmap pix2("C:/Users/windows 10/Desktop/PROJET 2A/avion");
    QPixmap pix("C:/Users/windows 10/Desktop/PROJET 2A/reservation");
    QPixmap pix4("C:/Users/windows 10/Desktop/PROJET 2A/avion1");
    QPixmap pix5("C:/Users/windows 10/Desktop/PROJET 2A/arriere3");

    ui->imagelabel->setPixmap(pix2.scaled(200,200,Qt::KeepAspectRatio));
    ui->logoresv->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
    ui->acceuil->setPixmap(pix3.scaled(900,900,Qt::KeepAspectRatio));
    ui->avion1->setPixmap(pix4.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere1->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere2->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere3->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere4->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere5->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere6->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));
    ui->arriere7->setPixmap(pix5.scaled(900,900,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked()
{
    int id = ui->id->text().toInt();
    QString date= ui->date->text();
   float prix = ui->prix->text().toFloat();
    QString heure= ui->heure->text();

    int idavion = ui->idavion->text().toInt();


    QString conf= ui->conf->text();

  Reservation r(id,date,prix,heure,conf,idavion);
  bool test=r.ajouter();
  if(test)
{ui->tabreservation->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un reservation"),
                  QObject::tr("RESERVATION  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Ajouter un Reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_supprimer_clicked()
{
    int id = ui->idsupp->text().toInt();

    bool test=tmpreservation.supprimer(id);
    if(test)
    {ui->tabreservation->setModel(tmpreservation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Reservation"),
                    QObject::tr("RESERVATION supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->id2->text().toInt();
       QString date= ui->date2->text();
       int prix=ui->prix2->text().toInt();
       QString heure= ui->heure2->text();

       QString conf= ui->conf->text();
       int idavion = ui->idavion2->text().toInt();

       Reservation r1(id,date,prix,heure,conf,idavion);
     bool test=r1.modifier(id);
     if(test)
   {ui->tabreservation->setModel(tmpreservation.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("modifier une reservation"),
                     QObject::tr("modifier ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier une reservatiion"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

/* ************************************************************************************ */
void MainWindow::on_ajouteravion_clicked()
{
    int mat = ui->mat->text().toInt();
    QString nom= ui->nom->text();
   double cap = ui->cap->text().toDouble();


  Avion a(mat,nom,cap);
  bool test=a.ajouter();
  if(test)
{ui->tabavion->setModel(tmpavion.afficher1());//refresh
      ui->tabtrie->setModel(tmpavion.affichertrie());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un avion"),
                  QObject::tr("AVION  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Ajouter un avion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifieravion_clicked()
{

    int mat = ui->mat2->text().toInt();
       QString nom= ui->nom2->text();
       double cap=ui->cap2->text().toDouble();


       Avion a1(mat,nom,cap);
     bool test=a1.modifier(mat);
     if(test)
   {ui->tabavion->setModel(tmpavion.afficher1());//refresh
         ui->tabtrie->setModel(tmpavion.affichertrie());//refresh
   QMessageBox::information(nullptr, QObject::tr("modifier une avion"),
                     QObject::tr("modifier ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier une avion"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimeravion_clicked()
{

    int mat = ui->matsupp->text().toInt();

    bool test=tmpavion.supprimer1(mat);
    if(test)
    {ui->tabavion->setModel(tmpavion.afficher1());//refresh
        ui->tabtrie->setModel(tmpavion.affichertrie());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un avion"),
                    QObject::tr("Avion supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un avion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_2_clicked()
{
    son->play();
}

void MainWindow::on_chercher_clicked()
{QString str=ui->mat2_2->text();
    ui->tabrech->setModel(tmpavion.chercher(str));


}

void MainWindow::on_chercher_2_clicked()
{
    QString str=ui->idcher->text();
        ui->tabcher->setModel(tmpreservation.chercheresv(str));
}

void MainWindow::on_exporter_clicked()
{
    tmpreservation.exporterpdf(ui->textpdf);

}
