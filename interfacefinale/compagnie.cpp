#include "compagnie.h"
#include <QDebug>
#include <QString>
compagnie::compagnie()
{
    id=0;
    nom="";
    pays="";
}
compagnie::compagnie(int id,QString nom,QString pays)
{
  this->id=id;
  this->nom=nom;
  this->pays=pays;
}
QString compagnie::get_nom(){return  nom;}
QString compagnie::get_pays(){return pays;}
int compagnie::get_id(){return  id;}

bool compagnie::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO compagnie (ID_COMP, PAYS, NOM) "
                    "VALUES (:id, :pays, :nom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":pays", pays);

return    query.exec();
}

QSqlQueryModel * compagnie::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from compagnie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
    return model;
}
bool compagnie::modifier(int id)
{
    QSqlQuery query;
   QString res= QString::number(id);
   query.prepare("UPDATE COMPAGNIE SET PAYS=:pays1,NOM=:nom1 WHERE ID_COMP=:id2");
   query.bindValue(":id2",res);
   query.bindValue(":pays1",pays);
   query.bindValue(":nom1",nom);
   return  query.exec();
}
bool compagnie::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from compagnie where ID_COMP = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * compagnie::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from compagnie where(ID_COMP LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
        return model;
}
