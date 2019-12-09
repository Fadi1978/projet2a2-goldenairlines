#include "client.h"
#include <QString>
Client::Client()
{
id=0;
nom="";
prenom="";
adresse="";
date_naiss="";
}
Client::Client(int id,QString nom,QString prenom,QString adresse,QString date_naiss)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->date_naiss=date_naiss;
}
QString Client::get_nom(){return nom;};
int Client::get_id(){return id;};
QString Client::get_adresse(){return adresse;};
QString Client::get_prenom(){return prenom;};
QString Client::get_date_naiss(){return date_naiss;};

bool Client::ajouter1()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client (NUM_CLIENT, NOM, PRENOM, ADRESSE, DATE_NAIS) "
                    "VALUES (:id, :nom, :prenom, :adresse, :DATE_NAISS)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":DATE_NAIS", date_naiss);

return    query.exec();
}
QSqlQueryModel * Client::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CLIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_NAISS"));
    return model;
}
QSqlQueryModel * Client::afficherorder1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client order by num_client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CLIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_NAISS"));
    return model;
}

bool Client::supprimer1(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where num_client = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Client::modifier1(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE client SET NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse,DATE_NAISS=:DATE_NAIS WHERE NUM_CLIENT=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":DATE_NAISS",date_naiss);

    return    query.exec();
}
QSqlQueryModel * Client::recherche1(const QString& id)
{

    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client WHERE (NUM_CLIENT LIKE '"+id+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CLIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISS"));
    return model;
}
QVector<double> Client:: statistique()
{
    QSqlQuery q;
    QVector<double> stat(12);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    stat[5]=0;
    stat[6]=0;
    stat[7]=0;
    stat[8]=0;
    stat[9]=0;
    stat[10]=0;
    stat[11]=0;
    q.prepare("SELECT * FROM client WHERE 1.1<=DATE_NAISS and DATE_NAISS<=1.31");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }

    q.prepare("SELECT * FROM client WHERE 1.31<DATE_NAISS and DATE_NAISS<=2.31");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }

   q.prepare("SELECT * FROM client WHERE 2.31<DATE_NAISS and DATE_NAISS<=3.31");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }

   q.prepare("SELECT * FROM client WHERE 3.31<DATE_NAISS and DATE_NAISS<=4.31");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }

    q.prepare("SELECT * FROM client WHERE 4.31<DATE_NAISS and DATE_NAISS<=5.31");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    q.prepare("SELECT * FROM client WHERE 5.31<DATE_NAISS and DATE_NAISS<=6.31");
    q.exec();
    while (q.next())
    {
        stat[5]++;
    }
    q.prepare("SELECT * FROM client WHERE 6.31<DATE_NAISS and DATE_NAISS<=7.31");
    q.exec();
    while (q.next())
    {
        stat[6]++;
    }
    q.prepare("SELECT * FROM client WHERE 7.31<DATE_NAISS and DATE_NAISS<=8.31");
    q.exec();
    while (q.next())
    {
        stat[7]++;
    }
    q.prepare("SELECT * FROM client WHERE 8.31<DATE_NAISS and DATE_NAISS<=9.31");
    q.exec();
    while (q.next())
    {
        stat[8]++;
    }
    q.prepare("SELECT * FROM client WHERE 9.31<DATE_NAISS and DATE_NAISS<=10.31");
    q.exec();
    while (q.next())
    {
        stat[9]++;
    }
    q.prepare("SELECT * FROM client WHERE 10.31<DATE_NAISS and DATE_NAISS<=11.31");
    q.exec();
    while (q.next())
    {
        stat[10]++;
    }
    q.prepare("SELECT * FROM client WHERE 11.31<DATE_NAISS and DATE_NAISS<=12.31");
    q.exec();
    while (q.next())
    {
        stat[11]++;
    }
    return stat;
}
