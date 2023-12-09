#include "createteam.h"
#include "pokemon.h"
#include "pokemonscreen.h"
#include "mainwindow.h"
#include "ui_createteam.h"

createteam::createteam(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createteam)
{
    ui->setupUi(this);

    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");
    if(pokemondb.open())
        qDebug() << "Open";
    else
        qDebug() << "Closed";

    p1 = new PokemonScreen(this);

}



int hit = 0;
void createteam::on_pushButton_clicked()
{
    hit++;
    ui->label1->setText(QString::number(hit));
}

void createteam::on_back_clicked()
{
    MainWindow *mainwindow = new MainWindow();
    this->hide();
    mainwindow->show();

}
createteam::~createteam()
{
    delete p1;

    delete ui;

}


void createteam::on_pokemon1_clicked()
{

    QSqlQuery query("SELECT * FROM Pokemon");//this is the main query to find all the pokemon and to check if you entered a valid pokemon

    QSqlQuery queryforitems("SELECT i_name FROM Item");//this is the query to find all item names
    int itemNameID = queryforitems.record().indexOf("i_name");
    while (queryforitems.next())// loops through all the elements in the query
    {
        QString itemName = queryforitems.value(itemNameID).toString();
        p1->addItemOption(itemName);

    }

    QSqlQuery queryforid("SELECT * FROM Pokemon");//this is for moves, but will also get all the names of the pokemon in teh database
    int pid = queryforid.record().indexOf("p_id");
    int dummyname = queryforid.record().indexOf("p_name");//this will get all the names of the pokemon in the database


    int pname = query.record().indexOf("p_name");
    int pattack = query.record().indexOf("p_Attack");
    int php = query.record().indexOf("p_HP");
    int pdefense = query.record().indexOf("p_Defense");
    int pspattack = query.record().indexOf("p_SpecialAttack");
    int pspdefense = query.record().indexOf("p_SpecialDefense");
    int ptype1 = query.record().indexOf("p_type1");
    int ptype2 = query.record().indexOf("p_type2");
    int sped = query.record().indexOf("p_Speed");


    QString name = ui->lineEdit->text();//this gets the name you entered as your pokemon

    QString idOfPokemonQ = "";//
    while (queryforid.next())// loops through all the elements in the query
    {
        QString dumyname = queryforid.value(dummyname).toString();
        if(dumyname == name){//checks if the name you entered is a valid name
            idOfPokemonQ = queryforid.value(pid).toString();// if so it puts the id of the pokemon as  Qstring
            p1->setPokemonID(idOfPokemonQ);
            break;
        }
    }

    std::string convertstupidfuckingshit = idOfPokemonQ.toStdString();//Conversion stuff
    int idOfPokemon = stoi(convertstupidfuckingshit);//This is the Id of the pokemon you selected

    QSqlQuery togetmoves;
    togetmoves.prepare("SELECT Moves.m_name FROM Moves INNER JOIN MoveTable ON Moves.m_id = MoveTable.mt_moveID INNER JOIN Pokemon ON MoveTable.mt_pokemonID = Pokemon.p_id WHERE p_id = (:idOfPokemon) ");
    togetmoves.bindValue(":idOfPokemon", idOfPokemon);// this has been set so the moves your pokemon has will be saved
    if (togetmoves.exec())
    {
        while (togetmoves.next())
        {
            p1->addSinguarMoveAsOption(togetmoves.value(0).toString());
        }
    }




    while (query.next())
    {
        QString n = query.value(pname).toString();
        QString att = query.value(pattack).toString();
        QString hp = query.value(php).toString();
        QString def = query.value(pdefense).toString();
        QString spatt = query.value(pspattack).toString();
        QString spdef = query.value(pspdefense).toString();
        QString type1 = query.value(ptype1).toString();
         QString type2 = query.value(ptype2).toString();
         QString speed = query.value(sped).toString();
         qDebug() << def;
        if(name == n){
            p1->show();
            p1->setPokemon(name);
            p1->setPokemonAtt(att);
            p1->setPokemonDef(def);
            p1->setPokemonHp(hp);
            p1->setPokemonSpAtt(spatt);
            p1->setPokemonSpDef(spdef);
            p1->setType1(type1);
            p1->setType2(type2);
            p1->setSpeed(speed);
            qDebug() << att << def;
            this->hide();

            //p1->setPokemon(name);
            //this->hide();
            break;
        }

    }

}

