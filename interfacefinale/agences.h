#ifndef AGENCES_H
#define AGENCES_H
#include<qstring.h>
#include<qsqlquery.h>
#include<qsqlquerymodel.h>

class Agences
{public:
    Agences();
   Agences(int,QString,int,int);
   int get_id();
    QString get_Localisation();
    int get_nbr_employees();
    int get_ref_eq();
    void setLocalisation(QString A){Localisation=A;}
    void setid(int A){id=A;}
    void setnbr_employees(int A){nbr_employees=A;}

    void deleteProduits(QString ID);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int id,int nbr_employees);
    bool chercheragences(int id);
   QSqlQueryModel * afficherRecherche(int id);
private:
    QString Localisation;
    int id,nbr_employees,ref_eq;
};

#endif // AGENCES_H

