#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSound>


#include <QMainWindow>
#include "reservation.h"
#include "avion.h"
#include "carte.h"
#include "client.h"
#include "agences.h"
#include "equipement.h"
#include "personnel.h"
#include "service.h"
#include "compagnie.h"
#include "offre.h"

#include <QSystemTrayIcon>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QSystemTrayIcon;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();


    void on_ajouteravion_clicked();

    void on_modifieravion_clicked();

    void on_supprimeravion_clicked();

    void on_pushButton_2_clicked();

    void on_chercher_clicked();

    void on_chercher_2_clicked();

    void on_exporter_clicked();

    void on_ajoutercarte_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_carte_clicked();

    void on_rechercher_carte_clicked();

    void on_ajouter_client_clicked();

    void on_supprimer_client_clicked();


    void on_modifier_client_clicked();

    void on_chercher_client_2_clicked();

    void on_ajouter_agence_clicked();

    void on_supprimer_agence_clicked();

    void on_modifier_agence_clicked();

    void on_rechercher_agence_clicked();

    void on_ajouter_equip_clicked();

    void on_modifier_equip_clicked();

    void on_supprimer_equip_clicked();

    void on_chercher_equip_clicked();

    void on_ajouter_personnel_clicked();

    void on_rechercher_personnel_clicked();

    void on_supprimer_personnel_clicked();

    void on_modifier_persoonel_clicked();

    void on_verifier_personnel_clicked();

    void on_actionQuitter_triggered();

    void on_actionAbout_Qt_triggered();

    void on_ajouter_service_clicked();

    void on_rechercher_service_clicked();

    void on_supprimer_service_clicked();

    void on_pb_modifier_s_clicked();

    void on_pb_verifier_s_clicked();

    void on_ajouter_compagnie_clicked();

    void on_modifier_compagnie_clicked();

    void on_supprimer_compagnie_clicked();

    void on_chercher_compagnie_clicked();

    void on_ajouter_offre_clicked();

    void on_modifier_offre_clicked();

    void on_supprimer_offre_clicked();

    void on_chercher_offre_clicked();

private:
    Ui::MainWindow *ui;
    QSound *son;
    QSystemTrayIcon *mSystemTrayIcon;


    Reservation tmpreservation;
    Avion tmpavion;
    Carte tmpcarte;
    Client tmpclient;
    Agences tmpagences;
    Equipements tmpequipements;
    Personnel tmppersonnel;
    service tmpservice;
    compagnie tmpcompagnie;
    compagnie tmpcomp;
    offre tmpoffre;


};
#endif // MAINWINDOW_H
