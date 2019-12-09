#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Personnel
{
public:
    Personnel();
    Personnel(int,QString,QString,QString,int);
        QString get_nom();
        QString get_prenom();
        QString get_age();
        int get_id();
        int get_id_service();


        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel *afficher_personnel_trier();
     QSqlQueryModel * recherche(const QString &id);
            bool supprimer(int);
            bool modifier(int );
            Personnel verifier(int );

private:
    QString nom,prenom,age;
    int id,id_service;
};

#endif // PERSONNEL_H
