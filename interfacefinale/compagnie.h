#ifndef COMPAGNIE_H
#define COMPAGNIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class compagnie
{
public:
   compagnie();
    compagnie (int,QString,QString);
    QString get_nom();
    QString get_pays();
    QSqlQueryModel * recherche(const QString &);
    int get_id();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int );
private:
    QString nom,pays;
    int id;
};

#endif // COMPAGNIE_H
