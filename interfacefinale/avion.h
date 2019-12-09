#ifndef AVION_H
#define AVION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Avion
{public:
    Avion();
    Avion(int,QString,long,QString);
    int get_mat();
    QString get_nom();
    long get_cap();
    QString get_dispo();

    bool ajouter();

    QSqlQueryModel * afficher1();
    QSqlQueryModel * affichertrie();

    QSqlQueryModel * chercher(const QString &);

    bool supprimer1(int);
    bool modifier(int);
private:
    QString nom,dispo;
    int mat;
    long cap;
};


#endif // AVION_H
