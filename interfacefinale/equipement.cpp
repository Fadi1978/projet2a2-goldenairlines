#include "equipement.h"

Equipements::Equipements()
{ ref_eq = 0 ;
    type_eq="" ;
    prix =0 ;


}
Equipements::Equipements(int ref_eq,QString type_eq,int prix)
{
  this->ref_eq=ref_eq;
  this->type_eq=type_eq;
  this->prix=prix;
}
int Equipements::get_Ref_eq(){return ref_eq;}
QString Equipements::get_type_eq(){return  type_eq;}
int Equipements::get_prix(){return prix;}


bool Equipements::ajouter1()
{
QSqlQuery query;
QString res= QString::number(ref_eq);
QString res1= QString::number(prix);
query.prepare("INSERT INTO EQUIPMENT (REF_EQUIP, TYPE_EQUIPE, PRIX) "
                    "VALUES (:ref_eq, :type_eq, :prix)");
query.bindValue(":ref_eq", res);
query.bindValue(":type_eq",type_eq);
query.bindValue(":prix", res1);

return    query.exec();
}


QSqlQueryModel * Equipements::afficher1()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_EQ"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_EQUIPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

bool Equipements::supprimer1(int ref_equipp)
{
QSqlQuery query;
QString res2= QString::number(ref_equipp);
query.prepare("Delete from EQUIPMENT where REF_EQUIP = :ref_equipp ");
query.bindValue(":ref_equipp", res2);
return    query.exec();
}


bool Equipements::chercherEqui(int id )
 {
    Equipements a ;
   QSqlQuery q;
   QString res= QString::number(id);
    q.prepare("SELECT * from EQUIPMENT where REF_EQUIP=:id");
    q.bindValue(":id",id);


return q.exec();
 }

QSqlQueryModel * Equipements::afficherRecherche(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);

model->setQuery("SELECT * from EQUIPMENT where REF_EQUIP like '%"+res+"%'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_EQUIP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_EQUIPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}
