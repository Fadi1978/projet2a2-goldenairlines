#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class offre
{
public:
  offre();
  offre(int,QString,QString,QString,int);
    QString get_depart();
    QString get_destination();
     QString get_libelle();
    int get_id();
    int get_idcomp();
    bool ajouter();
    QSqlQueryModel * recherche(const QString &);
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
private:
    QString depart,destination,libelle;
    int id,idcomp;
};

#endif // OFFRE_H
