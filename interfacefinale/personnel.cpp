#include "personnel.h"
#include <QDebug>
Personnel::Personnel()
{
    id=0;
    nom="";
    prenom="";
    age="";
    id_service=0;

}
Personnel::Personnel(int id,QString nom,QString prenom,QString age,int id_service)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
    this->id_service=id_service;

}
QString Personnel::get_nom(){return  nom;}
QString Personnel::get_prenom(){return prenom;}
int Personnel::get_id(){return  id;}
QString Personnel::get_age(){return  age;}
int Personnel::get_id_service(){return  id_service;}

bool Personnel::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO PERSONNEL (ID, NOM, PRENOM,AGE,ID_SERVICE) "
                    "VALUES (:id, :nom, :prenom,:age,:id_service)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age",age);
query.bindValue(":id_service", id_service);

return    query.exec();
}

QSqlQueryModel * Personnel::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personnel ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant service"));
    return model;
}

QSqlQueryModel *Personnel::afficher_personnel_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from personnel ORDER BY AGE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_service"));
    return model;
}

bool Personnel::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from personnel where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Personnel::modifier(int id)
{
    QSqlQuery query1;
     QSqlQuery query2;
      QSqlQuery query3;



   QString res= QString::number(id);




    if(nom!="" && prenom=="")
    {
   query1.prepare("UPDATE PERSONNEL SET NOM=:nom WHERE ID=:id");
   query1.bindValue(":id",res);
   query1.bindValue(":nom",nom);
   query1.bindValue(":prenom",prenom);
   query1.bindValue(":id_service", id_service);

   return  query1.exec();
    }

    if(nom=="" && prenom!=""  )
    {
   query2.prepare("UPDATE PERSONNEL SET PRENOM=:prenom WHERE ID=:id");
   query2.bindValue(":id",res);
   query2.bindValue(":nom",nom);
   query2.bindValue(":prenom",prenom);
   query2.bindValue(":id_service", id_service);



   return  query2.exec();
    }




    if(nom!="" && prenom!="" )
    {
   query3.prepare("UPDATE PERSONNEL SET NOM=:nom,PRENOM=:prenom WHERE ID=:id");
   query3.bindValue(":id",res);
   query3.bindValue(":nom",nom);
   query3.bindValue(":prenom",prenom);
   query3.bindValue(":id_service", id_service);



   return  query3.exec();
    }











}

Personnel Personnel::verifier(int id)

{

Personnel *p= new Personnel();

      QSqlQuery q;

      q.prepare("SELECT * FROM PERSONNEL WHERE id=?");

      q.addBindValue(id);

      q.exec();

      if(q.next())

      {

      int id = q.value(0).toInt();



      QString nom    = q.value(1).toString();

      QString prenom = q.value(2).toString();
      QString age = q.value(3).toString();
      int id_service = q.value(4).toInt();







  p= new Personnel(id,nom,prenom,age,id_service);

  return *p;

      }

  return *p;


 }


QSqlQueryModel * Personnel::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from personnel where(ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SERVICE"));
        return model;

}

