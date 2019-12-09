#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QPixmap>
#include<QSystemTrayIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    mSystemTrayIcon=new QSystemTrayIcon(this);
    son=new QSound("C:/Userswindows 10/DesktopPROJET 2A/musiqueqt.wav");

    ui->tabreservation->setModel(tmpreservation.afficher());
    ui->tabavion->setModel(tmpavion.afficher1());
    ui->tabtrie->setModel(tmpavion.affichertrie());
    ui->textpdf->hide();
    ui->tabcher->setModel(tmpreservation.afficher());
    ui->tabrech->setModel(tmpavion.afficher1());
    ui->tabagences->setModel(tmpagences.afficher());
    ui->tabequipements->setModel(tmpequipements.afficher1());

    QPixmap pix3("C:/Users/windows 10/Desktop/PROJET 2A/acceuil");
    QPixmap pix2("C:/Users/windows 10/Desktop/PROJET 2A/avion");
    QPixmap pix("C:/Users/windows 10/Desktop/PROJET 2A/avion");
    QPixmap pix4("C:/Users/windows 10/Desktop/PROJET 2A/avion");
    QPixmap pix5("C:/Users/windows 10/Desktop/PROJET 2A/avion");

    /*ui->imagelabel->setPixmap(pix2.scaled(200,200,Qt::KeepAspectRatio));*/
    ui->logoresv->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
    ui->acceuil->setPixmap(pix3.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->avion1->setPixmap(pix4.scaled(1500,1500,Qt::KeepAspectRatio));
    ui->arriere1->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere2->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere3->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere4->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere5->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere6->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere7->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere8->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere9->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere10->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere11->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere12->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));
    ui->arriere13->setPixmap(pix5.scaled(1200,1500,Qt::KeepAspectRatio));


    QPixmap pix6("C:/Users/windows 10/Desktop/PROJET 2A/imageoumaima1");
    ui->label_pic->setPixmap(pix6);

    QPixmap pixs("C:/Users/windows 10/Desktop/PROJET 2A/imageoumaima2");
    ui->label_pic_s->setPixmap(pixs);
    int w=ui->label_pic_s->width();
    int h=ui->label_pic_s->height();
    ui->label_pic_s->setPixmap(pixs.scaled(w,h,Qt::KeepAspectRatio));

   mSystemTrayIcon= new QSystemTrayIcon(this);
        mSystemTrayIcon ->setIcon(QIcon(":/myappico.png"));
        mSystemTrayIcon ->setVisible(true);




    ui->tabpersonnel->setModel(tmppersonnel.afficher());
   ui->tabservice->setModel(tmpservice.afficher());
       ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
        ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
        for(int i=25 ;i<60;i++)

         {

             ui->comboBox->addItem(QString::number(i)+"ans");

          }

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


void MainWindow::on_ajouteravion_clicked()
{
    int mat = ui->mat->text().toInt();
    QString nom= ui->nom->text();
   double cap = ui->cap->text().toDouble();
   QString dispo= ui->dispo->text();


  Avion a(mat,nom,cap,dispo);
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

       QString dispo= ui->dispo->text();

       Avion a1(mat,nom,cap,dispo);
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
/* ********************************************************* */

void MainWindow::on_ajoutercarte_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString type= ui->lineEdit_2->text();
    int points= ui->lineEdit_3->text().toInt();
    int id_client= ui->lineEdit_20->text().toInt();
  Carte e(id,type,points,id_client);
  bool test=e.ajouter();
  if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_supp->text().toInt();
    bool test=tmpcarte.supprimer(id);
    if(test)
    {ui->tabcarte->setModel(tmpcarte.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("carte supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_carte_clicked()
{
    int id = ui->lineEdit_15->text().toInt();
    QString type= ui->lineEdit_16->text();
    int points= ui->lineEdit_17->text().toInt();
    int id_client= ui->lineEdit_14->text().toInt();
   Carte x(id,type,points,id_client);
  bool test=x.modifier(id);
  if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
 ui->tabcartetri->setModel(tmpcarte.afficherorder());
QMessageBox::information(nullptr, QObject::tr("Modifier carte"),
                  QObject::tr("Carte modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_rechercher_carte_clicked()
{
    QString id = ui->lineEdit_18->text();


        ui->tabcarterecherche ->setModel(tmpcarte.recherche(id));
}

/* ********************************************************************************   */

void MainWindow::on_ajouter_client_clicked()
{
    int id = ui->lineEdit_4->text().toInt();
    QString nom= ui->lineEdit_5->text();
    QString prenom= ui->lineEdit_6->text();
    QString adresse= ui->lineEdit_7->text();
    QString date_naiss= ui->lineEdit_8->text();
    Client a(id,nom,prenom,adresse,date_naiss);
    bool test=a.ajouter1();
    if(test)
  {
  ui->tabclient->setModel(tmpclient.afficher1());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
  QObject::tr("Client ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client "),
                    QObject::tr("Erreur else !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_client_clicked()
{

    int id = ui->lineEdit_9->text().toInt();
    bool test=tmpclient.supprimer1(id);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher1());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_modifier_client_clicked()
{
    int id = ui->lineEdit_10->text().toInt();
    QString nom= ui->lineEdit_11->text();
    QString prenom= ui->lineEdit_12->text();
    QString adresse=ui->lineEdit_13->text();
    QString date_naiss=ui->lineEdit_14->text();
   Client x(id,nom,prenom,adresse,date_naiss);
  bool test=x.modifier1(id);
  if(test)
{ui->tabclient->setModel(tmpclient.afficher1());//refresh
 ui->tabclient2->setModel(tmpclient.afficherorder1());
QMessageBox::information(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Client modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_chercher_client_2_clicked()
{
    QString id = ui->lineEdit_18->text();


        ui->tabcarterecherche ->setModel(tmpcarte.recherche(id));

}

/* ********************************************************************************   */

void MainWindow::on_ajouter_agence_clicked()
{

    int id = ui->lineEdit_8->text().toInt();
    QString Localisation= ui->lineEdit_9->text();
    int nbr_employees= ui->lineEdit_10->text().toInt();
    int ref_eq= ui->lineEdit_7->text().toInt();

  Agences a(id,Localisation,nbr_employees,ref_eq);
  bool test=a.ajouter();
  if(test)
{ui->tabagences->setModel(tmpagences.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une agence"),
                  QObject::tr("Agence ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

else
  QMessageBox::critical(nullptr, QObject::tr("Ajouter une agence"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_supprimer_agence_clicked()
{
    int id = ui->lineEdit_11->text().toInt();
    bool test=tmpagences.supprimer(id);
    if(test)
    {ui->tabagences->setModel(tmpagences.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Agence"),
                    QObject::tr("Agence supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Agence"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_agence_clicked()
{
    int id = ui->lineEdit_13->text().toInt();
    int nbr_employees = ui->lineEdit_15->text().toInt();
    int ref_eq= ui->lineEdit_7->text().toInt();

    QString localisation;
    Agences a(id, localisation, nbr_employees,ref_eq);
    bool test = a.modifier(id ,nbr_employees );
    if(test){
        ui->tabagences->setModel(tmpagences.afficher());
}
}

void MainWindow::on_rechercher_agence_clicked()
{

    int id = ui->lineEdit_12->text().toInt();
     Agences a;
     bool test =a.chercheragences(id);
     if(test)
   {ui->tableView_2->setModel(a.afficherRecherche(id));//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une agence"),
                     QObject::tr("Agence ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }

 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter une agence"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_ajouter_equip_clicked()
{
    int ref_eq = ui->lineEdit_32->text().toInt();
    QString type_eq= ui->lineEdit_31->text();
    int prix= ui->lineEdit_33->text().toInt();
  Equipements e(ref_eq,type_eq,prix);
  bool test2=e.ajouter1();
  if(test2)
{ui->tabequipements->setModel(tmpequipements.afficher1());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement."),
                  QObject::tr("Agence ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

else
  QMessageBox::critical(nullptr, QObject::tr("Ajouter une agence"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_equip_clicked()
{

}

void MainWindow::on_supprimer_equip_clicked()
{

    int ref_eq = ui->lineEdit_35->text().toInt();
    bool test1=tmpequipements.supprimer1(ref_eq);
    if(test1)
    {ui->tabequipements->setModel(tmpequipements.afficher1());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un équipement."),
                    QObject::tr("Equipement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un équipement."),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_chercher_equip_clicked()
{

    int id = ui->lineEdit_36->text().toInt();
     Equipements a;
     bool test =a.chercherEqui(id);
     if(test)
   {ui->tableView->setModel(a.afficherRecherche(id));//refresh
   QMessageBox::information(nullptr, QObject::tr("chercher equipment"),
                     QObject::tr("equipment trouvée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }

 else
     QMessageBox::critical(nullptr, QObject::tr("cherccher equipment"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

/* ********************************************************************************   */


void MainWindow::on_ajouter_personnel_clicked()
{   mSystemTrayIcon->showMessage(tr("Ajouter un personnel!"),
                                 tr("personnel ajouté.\n"));
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString  age= ui->comboBox->currentText();
    int id_service = ui->lineEdit_id_service->text().toInt();

  Personnel p(id,nom,prenom,age,id_service);
  bool test=p.ajouter();
  if(test)
{
      ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
         ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
  else

            QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_rechercher_personnel_clicked()
{
    mSystemTrayIcon->showMessage(tr("rechercher un service!"),
                                     tr("service recherché.\n"));
    QString str=ui->lineEdit_id_4->text();
    ui->tableView->setModel(tmppersonnel.recherche(str));
}

void MainWindow::on_supprimer_personnel_clicked()
{
    mSystemTrayIcon->showMessage(tr("supprimer un personnel!"),
                                   tr("personnel supprimé .\n"));
   int id = ui->tmppersonnel->text().toInt();
   bool test=tmppersonnel.supprimer(id);
   if(test)
   {
       ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
      ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
       QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                   QObject::tr("Personnel supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_modifier_persoonel_clicked()
{
    mSystemTrayIcon->showMessage(tr("modifier un personnel!"),
                                  tr("personnel modifié.\n"));
        int id = ui->lineEdit_idm->text().toInt();
        QString nom= ui->lineEdit_nomm->text();
        QString prenom= ui->lineEdit_premomm->text();
         QString age= ui->lineEdit_agem->text();
         int id_service = ui->lineEdit_3->text().toInt();

       Personnel p(id,nom,prenom,age,id_service);
      bool test=p.modifier(id);
      if(test)
    {ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
       ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
    QMessageBox::information(nullptr, QObject::tr("Modifier un personnel"),
                      QObject::tr("Personnel modifier.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier personnel"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_verifier_personnel_clicked()
{
    mSystemTrayIcon->showMessage(tr("Verifier un personnel!"),
                                          tr("personnel verifié.\n"));
    int id = ui->lineEdit_7->text().toInt();

       Personnel test= tmppersonnel.verifier(id);

       if (test.get_id()==id)

      {

           QMessageBox::information(nullptr, QObject::tr("Rechercher un Personnel"),

                           QObject::tr("Personnel trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);

            }

       else


       {

           QMessageBox::critical(nullptr, QObject::tr("Error !"),

           QObject::tr("Echech de l'Opération !.\n"

                        "Click Cancel to exit."), QMessageBox::Cancel);

       }

}

void MainWindow::on_actionQuitter_triggered()
{
     close();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::information(nullptr, QObject::tr("info !"),

    QObject::tr("information qt !.\n"

                 "Click Cancel to exit."), QMessageBox::Cancel);
}


/* ********************************************************************************   */


void MainWindow::on_ajouter_service_clicked()
{
    mSystemTrayIcon->showMessage(tr("Ajouter un service!"),
                                     tr("service ajouté.\n"));
        int id_service = ui->lineEdit_ids->text().toInt();
        QString nom= ui->lineEdit_noms->text();

      service p(id_service,nom);
      bool test=p.ajouter();
      if(test)
    {
          ui->tabservice->setModel(tmpservice.afficher());//refresh
             ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un service"),
                      QObject::tr("service ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un service"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_rechercher_service_clicked()
{
    QString str=ui->lineEdit_2->text();
    ui->tableView_3->setModel(tmpservice.recherche(str));
}

void MainWindow::on_supprimer_service_clicked()
{
    mSystemTrayIcon->showMessage(tr("Supprimer un service!"),
                                  tr("service supprimé.\n"));
   int id = ui->lineEdit_40->text().toInt();
   bool test=tmpservice.supprimer(id);
   if(test)
   {
       ui->tabservice->setModel(tmpservice.afficher());//refresh
          ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
       QMessageBox::information(nullptr, QObject::tr("Supprimer un service"),
                   QObject::tr("service supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un service"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_modifier_s_clicked()
{
    mSystemTrayIcon->showMessage(tr("modifier un service!"),
                                   tr("service modifié.\n"));


        int id_service = ui->lineEdit_id_servicem->text().toInt();
        QString nom= ui->lineEdit_nomm_3->text();


       service s(id_service,nom);
      bool test=s.modifier(id_service);
      if(test)
    {ui->tabservice->setModel(tmpservice.afficher());//refresh
       ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
    QMessageBox::information(nullptr, QObject::tr("Modifier un service"),
                      QObject::tr("service modifier.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier service"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_verifier_s_clicked()
{
    mSystemTrayIcon->showMessage(tr("verifier un service!"),
                                  tr("service vérifié.\n"));

       int id_service= ui->lineEdit->text().toInt();

          service test= tmpservice.verifier(id_service);

          if (test.get_id_service()==id_service)

                {

              QMessageBox::information(nullptr, QObject::tr("Rechercher un service"),

                              QObject::tr("service trouvé.\n"

                                          "Click Cancel to exit."),
   QMessageBox::Cancel);

                }

          else


          {

              QMessageBox::critical(nullptr, QObject::tr("Error !"),

              QObject::tr("Echech de l'Opération !.\n"

                           "Click Cancel to exit."), QMessageBox::Cancel);

          }

}
/* ********************************************************************************   */

void MainWindow::on_ajouter_compagnie_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString pays= ui->lineEdit_pays->text();
  compagnie  e(id,nom,pays);
  bool test=e.ajouter();
  if(test)
{ui->tabcompagnie->setModel(tmpcompagnie.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une comagnie"),
                  QObject::tr("compagnie ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("compagnie non ajouté"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_compagnie_clicked()
{
    int id = ui->id2->text().toInt();
        QString pays1= ui->pays1->text();
        QString nom1= ui->nom1->text();
        compagnie c1(id,pays1,nom1);
      bool test=c1.modifier(id);
      if(test)
    {ui->tabcompagnie->setModel(tmpcompagnie.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("modifier un compagnie"),
                      QObject::tr("modifier effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier un compagnie"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_compagnie_clicked()
{

    int id = ui->lineEdit_id_5->text().toInt();
    bool test=tmpcompagnie.supprimer(id);
    if(test)
    {ui->tabcompagnie->setModel(tmpcompagnie.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une compagnie"),
                    QObject::tr(" compagnie supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une compagnie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_chercher_compagnie_clicked()
{ QString str=ui->lineEdit_rechercher->text();
    ui->tabrechercher->setModel(tmpcomp.recherche(str));

}

void MainWindow::on_ajouter_offre_clicked()
{
    int id = ui->id_2->text().toInt();
    QString depart= ui->depart->text();
    QString destination= ui->destination->text();
    QString libelle= ui->libelle->text();
    int idcomp = ui->idc->text().toInt();

  offre  o(id,depart,destination,libelle,idcomp);
  bool test=o.ajouter();
  if(test)
{ui->taboffre->setModel(tmpoffre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une offre"),
                  QObject::tr("offre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une offre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_offre_clicked()
{
    int id = ui->id2->text().toInt();
        QString depart1= ui->dep2->text();
        QString destination1= ui->des2->text();
         QString libelle1= ui->lib2->text();
         int idcomp = ui->id2->text().toInt();

        offre o1(id,depart1,destination1,libelle1,idcomp);
      bool test=o1.modifier(id);
      if(test)
    {ui->taboffre->setModel(tmpoffre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("modifier une offre"),
                      QObject::tr("modifier effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier une offre"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_offre_clicked()
{
    int id = ui->id3->text().toInt();
    bool test=tmpoffre.supprimer(id);
    if(test)
    {ui->taboffre->setModel(tmpoffre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une offre"),
                    QObject::tr("offre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une offre "),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_chercher_offre_clicked()
{
    QString str=ui->lineEdit_rechercher_2->text();
    ui->taboffre_2->setModel(tmpoffre.recherche(str));
}
