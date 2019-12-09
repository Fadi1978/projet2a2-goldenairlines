#include "agences.h"

Agences::Agences()
{
    id=0;
    Localisation="";
    nbr_employees=0;
    ref_eq =0;
}


Agences::Agences(int id,QString localisation,int nbr_employees,int ref_eq)
{
  this->id=id;
  this->Localisation=localisation;
  this->nbr_employees=nbr_employees;
    this->ref_eq=ref_eq;
}
int Agences::get_id(){return  id;}
QString Agences::get_Localisation(){return  Localisation;}
int Agences::get_nbr_employees(){return nbr_employees;}
int Agences::get_ref_eq(){return ref_eq;}

bool Agences::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(nbr_employees);
QString res2=QString::number(ref_eq);
query.prepare("INSERT INTO AGENCE (ID_AGENCE1, LOCALISATION, NBR_EMPLOYEES,ID_EQUIP) "
                    "VALUES (:id_agence1, :localisation, :nbr_employees,:ID_Equip)");
query.bindValue(":id_agence1", res);
query.bindValue(":localisation",Localisation);
query.bindValue(":nbr_employees", res1);
query.bindValue(":ID_Equip",res2);

return    query.exec();
}


QSqlQueryModel * Agences::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from agence");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AGENCE1"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCALISATION "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_EMPLOYEES"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_Equip"));
    return model;
}

bool Agences::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from agence where ID_AGENCE1 = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Agences ::modifier(int id,int nbr_employees )
{
    QSqlQuery query;
    QString res= QString::number(id);
   QString res1= QString::number(nbr_employees);

       query.prepare("UPDATE agence SET NBR_EMPLOYEES = :nbr_employees WHERE ID_AGENCE1 = :id_agence1");
       query.bindValue(":id_agence1", res);
       query.bindValue(":nbr_employees", res1);
       return query.exec();
   }

bool Agences::chercheragences(int id )
 {
    Agences a ;
   QSqlQuery q;
   QString res= QString::number(id);
    q.prepare("SELECT * from agence where ID_AGENCE1=:id");
    q.bindValue(":id",id);


return q.exec();
 }


QSqlQueryModel * Agences::afficherRecherche(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);

model->setQuery("SELECT * from agence where ID_AGENCE1 like '%"+res+"%'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AGENCE1"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOCALISATION "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_EMPLOYEES"));
    return model;
}


