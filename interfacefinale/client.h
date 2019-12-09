#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_date_naiss();
    bool ajouter1();
    QSqlQueryModel * afficher1();
    QSqlQueryModel * afficherorder1();
    QSqlQueryModel * recherche1(const QString&);
    bool supprimer1(int);



    bool modifier1(int);
    QVector<double> statistique();
private:
    QString nom,prenom,adresse,date_naiss;
    int id;
};
#endif // CLIENT_H
