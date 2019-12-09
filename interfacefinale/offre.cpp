#include "offre.h"
#include <QDebug>
#include <QString>
offre::offre()
{
    id=0;
    depart="";
    destination="";
    libelle="";
    idcomp=0;
}
offre::offre(int id,QString depart,QString destination,QString libelle,int idcomp)
{
  this->id=id;
  this->depart=depart;
  this->destination=destination;
    this->libelle=libelle;
    this->idcomp=idcomp;
}
QString offre::get_depart(){return  depart;}
QString offre::get_libelle(){return  libelle;}
QString offre::get_destination(){return destination;}
int offre::get_id(){return  id;}
int offre::get_idcomp(){return  idcomp;}

bool offre::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res2= QString::number(idcomp);
query.prepare("INSERT INTO offre (ID_OFFRE, DEPART, DESTINATION,LIBELLE,ID_COMP) "
                    "VALUES (:id, :depart, :destination, :libelle, :idcomp)");
query.bindValue(":id", res);
query.bindValue(":depart", depart);
query.bindValue(":destination", destination);
query.bindValue(":libelle", libelle);
query.bindValue(":idcomp", res2);

return    query.exec();
}

QSqlQueryModel * offre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from offre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DEPART "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIBELLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCOMP"));

    return model;
}
bool offre::modifier(int id)
{
    QSqlQuery query;
   QString res= QString::number( id);
   QString res2= QString::number( idcomp);
   query.prepare("UPDATE OFFRE SET DEPART=:dep2,DESTINATION=:des2,LIBELLE=:lib2,ID_COMP=:id5 WHERE ID_OFFRE=:id2");
   query.bindValue(":id2",res);
   query.bindValue(":dep2",depart);
   query.bindValue(":des2",destination);
   query.bindValue(":lib2",libelle);
   query.bindValue(":id5",res2);
   return  query.exec();
}

bool offre::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from offre where ID_OFFRE = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * offre::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from offre where(ID_OFFRE LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DEPART"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_COMP"));
        return model;
}
