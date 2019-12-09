#include "carte.h"

Carte::Carte()
{
id_carte=0;
libelle="";
points=0;
}
Carte::Carte(int id_carte,QString libelle,int points,int id_client)
{
    this->id_carte=id_carte;
    this->id_client=id_client;
    this->points=points;
    this->libelle=libelle;
}
QString Carte::get_type(){return libelle;};
int Carte::get_id_carte(){return id_carte;};
int Carte::get_points(){return points;};

bool Carte::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_carte);
query.prepare("INSERT INTO carte (ID_CARTE, libelle, POINTS,ID_CLIENT) "
                    "VALUES (:id_carte, :libelle, :points, :id_client)");
query.bindValue(":id_carte", res);
query.bindValue(":libelle", libelle);
query.bindValue(":points", points);
query.bindValue(":id_client",id_client);
return    query.exec();
}
QSqlQueryModel * Carte::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CARTE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}
QSqlQueryModel * Carte::afficherorder()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte order by id_carte");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CARTE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTS"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}
bool Carte::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE carte SET libelle=:libelle,POINTS=:points WHERE ID_CARTE=:id_carte");
    query.bindValue(":id",res);
    query.bindValue(":libelle",libelle);
    query.bindValue(":points",points);


    return    query.exec();
}


bool Carte::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte where ID_CARTE = :id_carte ");
query.bindValue(":id_carte", res);
return    query.exec();
}
QSqlQueryModel * Carte::recherche(const QString& id_carte)
{

    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte WHERE (ID_CARTE LIKE '"+id_carte+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CARTE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));

return model;
}

