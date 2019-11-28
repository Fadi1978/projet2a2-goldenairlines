#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSound>


#include <QMainWindow>
#include "reservation.h"
#include "avion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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

private:
    Ui::MainWindow *ui;
    QSound *son;


    Reservation tmpreservation;
    Avion tmpavion;

};
#endif // MAINWINDOW_H
