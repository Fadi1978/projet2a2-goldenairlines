#include "avion.h"

Avion::Avion()
{
mat=0;
nom="";
cap=0;
}

Avion::Avion(int mat,QString nom, long cap,QString dispo)
{   this->mat=mat;
    this->nom=nom;
    this->cap=cap;
    this->dispo=dispo;

}
int Avion::get_mat(){return  mat;}
QString Avion::get_nom(){return nom;}
long Avion::get_cap(){return  cap;}
QString Avion::get_dispo(){return dispo;}


bool Avion::ajouter()
{
QSqlQuery query;
QString res= QString::number(mat);
QString ress= QString::number(cap);


query.prepare("INSERT INTO AVION (MATRICULE,NOM_AVION,CAPACITE,DISPO) "
                    "VALUES (:mat, :nom, :cap, :dispo )");
query.bindValue(":mat", res);
query.bindValue(":nom", nom);
query.bindValue(":cap", ress);
query.bindValue(":dispo", dispo);



return    query.exec();
}

QSqlQueryModel * Avion::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from avion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cap"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dispo"));



    return model;
}

bool Avion::supprimer1(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from avion where MATRICULE = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Avion::modifier(int mat)
{
    QSqlQuery query1;
    QSqlQuery query2;
    QSqlQuery query3;

   QString res= QString::number(mat);
   QString ress= QString::number(cap);
   if(nom!=""&&cap==0)
   {
      query1.prepare("UPDATE AVION SET NOM_AVION=:nom  WHERE MATRICULE=:mat");
      query1.bindValue(":mat",res);
      query1.bindValue(":nom",nom);
      query1.bindValue(":cap",ress);

      return  query1.exec();

   }
    if(cap!=0&&nom=="")
   {
      query2.prepare("UPDATE AVION SET CAPACITE=:cap  WHERE MATRICULE=:mat");
      query2.bindValue(":mat",res);
      query2.bindValue(":nom",nom);
      query2.bindValue(":cap",ress);
      return  query2.exec();

    }

 if((nom!="") && (cap!=0))
{
   query3.prepare("UPDATE AVION SET NOM_AVION=:nom,CAPACITE=:cap  WHERE MATRICULE=:mat");
   query3.bindValue(":mat",res);
   query3.bindValue(":nom",nom);
   query3.bindValue(":cap",ress);
   return  query3.exec();


}

}
QSqlQueryModel * Avion::affichertrie()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from avion ORDER BY CAPACITE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cap"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dispo"));



    return model;
}

QSqlQueryModel * Avion::chercher(const QString &mat)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from avion where(MATRICULE LIKE '"+mat+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM AVION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DISPO"));

        return model;
}
