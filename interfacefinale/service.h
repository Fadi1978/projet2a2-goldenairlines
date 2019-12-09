#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class service
{
public:
    service();
    service(int,QString);
        QString get_nom();

        int get_id_service();
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel *afficher_service_trier();
     QSqlQueryModel * recherche(const QString &id_service);
            bool supprimer(int);
            bool modifier(int );
            service verifier(int );
private:
    QString nom;
    int id_service;
};

#endif // SERVICE_H
