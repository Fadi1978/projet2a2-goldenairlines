#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "QFileDialog"
#include "QTextBrowser"
#include "QPrinter"
#include <QSqlQueryModel>

class Reservation
{public:
    Reservation();
    Reservation(int,QString,float,QString,QString,int);
    QString get_date();
    double get_prix();
    QString get_heure();
    QString get_conf();
    int get_id();
    int get_idavion();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * chercheresv(const QString &);
    void exporterpdf(QTextBrowser *text);

private:
    QString date,heure,conf;
    int id,idavion;
    double prix;
};

#endif // RESERVATION_H
