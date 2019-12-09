#include "service.h"
#include <QDebug>
service::service()
{
    id_service=0;
    nom="";

}
service::service(int id_service,QString nom)
{
  this->id_service=id_service;
  this->nom=nom;

}
QString service::get_nom(){return  nom;}

int service::get_id_service(){return  id_service;}

bool service::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_service);
query.prepare("INSERT INTO SERVICE (ID_SERVICE, NOM) "
                    "VALUES (:id_service, :nom)");
query.bindValue(":id_service", res);
query.bindValue(":nom", nom);


return    query.exec();
}

QSqlQueryModel * service::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from service ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SERVICE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    return model;
}

QSqlQueryModel *service::afficher_service_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from service ORDER BY ID_SERVICE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_service"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));

    return model;
}

bool service::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from service where ID_SERVICE = :id_service ");
query.bindValue(":id_service", res);
return    query.exec();
}

bool service::modifier(int id_service)
{
    QSqlQuery query1;
   QString res= QString::number(id_service);



   query1.prepare("UPDATE SERVICE SET NOM=:nom WHERE ID_SERVICE=:id_service");
   query1.bindValue(":id_service",res);
   query1.bindValue(":nom",nom);

   return  query1.exec();

 }

service service::verifier(int id_service)

{

service *p= new service();

      QSqlQuery q;

      q.prepare("SELECT * FROM SERVICE WHERE id_service=?");

      q.addBindValue(id_service);

      q.exec();

      if(q.next())

      {

      int id_service = q.value(0).toInt();



      QString nom    = q.value(1).toString();



  p= new service(id_service,nom);

  return *p;

      }

  return *p;


 }

QSqlQueryModel * service::recherche(const QString &id_service)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from service where(ID_SERVICE LIKE '"+id_service+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SERVICE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        return model;
}

