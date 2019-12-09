#ifndef EQUIPEMETS_H
#define EQUIPEMETS_H
#include<qstring.h>
#include<qsqlquery.h>
#include<qsqlquerymodel.h>

class Equipements
{public:
    Equipements();
   Equipements(int,QString,int);
   int get_Ref_eq();
    QString get_type_eq();
    int get_prix();

    bool ajouter1();
    QSqlQueryModel * afficher1();
    bool supprimer1(int);
    bool chercherEqui(int);
   QSqlQueryModel * afficherRecherche(int id);
private:
    QString type_eq;
    int ref_eq,prix;
};

#endif // EQUIPEMETS_H
