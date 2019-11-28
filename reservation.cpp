#include "reservation.h"

Reservation::Reservation()
{
id=0;
date="";
prix=0;
heure="";
conf="";
}

Reservation::Reservation(int id,QString date,float prix,QString heure,QString conf)
{
  this->id=id;
  this->date=date;
  this->prix=prix;
  this->heure=heure;
  this->conf=conf;
}
QString Reservation::get_date(){return  date;}
QString Reservation::get_heure(){return heure;}
QString Reservation::get_conf(){return  conf;}
int Reservation::get_id(){return  id;}
double Reservation::get_prix(){return  prix;}


bool Reservation::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);

QString ress= QString::number(prix);

query.prepare("INSERT INTO RESERVATION (ID_RESERVATION, DATE_RESV, PRIX, HEURE, CONFIRMATION) "
                    "VALUES (:id, :date, :prix, :heure, :conf)");
query.bindValue(":id", res);
query.bindValue(":date", date);
query.bindValue(":prix", ress);
query.bindValue(":heure", heure);
query.bindValue(":conf", conf);



return    query.exec();
}
QSqlQueryModel * Reservation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESERVATION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Conf"));


    return model;
}

bool Reservation::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from reservation where ID_RESERVATION = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Reservation::modifier(int id)
{
    QSqlQuery query;
   QString res= QString::number(id);
    QString rese=QString::number(prix);
   query.prepare("UPDATE RESERVATION SET DATE_RESV=:date2,PRIX=:prix,HEURE=:heure2,CONFIRMATION=:conf2 WHERE ID_RESERVATION=:id");
   query.bindValue(":id",res);
   query.bindValue(":date2",date);
   query.bindValue(":prix",rese);
   query.bindValue(":heure2",heure);
   query.bindValue(":conf2",conf);
   return  query.exec();
}
QSqlQueryModel * Reservation::chercheresv(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from reservation where(ID_RESERVATION LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID RESERV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE RESERV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CONFIRMATION"));
        return model;
}

void Reservation::exporterpdf(QTextBrowser *text)
{
   QString tt;
    QSqlQuery qry;
    qry.exec("select * from reservastion");
    while(qry.next())
    {
        tt="Id: "+qry.value(0).toString()+"\n"+"Date: "+qry.value(1).toString()+"\n"+"Confirmation: "+qry.value(2).toString()+"\n";

    }
    text->setText(tt);
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    text->print(&printer);
}

