#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QPixmap>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");

    if(!pokemondb.open())
        ui->label->setText("fail to open");
    else
       ui->label->setText("connected");

     ;
    QSqlQuery getAllTrainers("SELECT Trainer.t_name FROM Trainer WHERE t_id < 580 ");
     while(getAllTrainers.next()){

        ui->comboBox->addItem(getAllTrainers.value(0).toString());
    }

     QSqlQuery getAllTeams("SELECT Trainer.t_id FROM Trainer where t_id >= 600");
     while(getAllTeams.next()){

         ui->teamsDrop->addItem(getAllTeams.value(0).toString());
     }

    battlewindow = new BattleWindow(this);
    vp = new ViewPokemonWindow(this);
    ui->pushButton_3->hide();

}

int trainerIdgotten = 0;
int teamIdgotten = 0;

MainWindow::~MainWindow()
{
    delete ui;
    delete c;
    delete battlewindow;
    delete vp;
}


void MainWindow::on_createTeamButton_clicked()
{


    QSqlQuery query("SELECT * FROM TrainerPokemon");
    int pname = query.record().indexOf("p_id");
    int p_trainerID = query.record().indexOf("p_trainerID");

    while (query.next())
    {
        QString n = query.value(pname).toString();
        QString pid = query.value(p_trainerID).toString();
       // qDebug() << n << pid;

    }
    c = new createteam(this);
    c->show();
    this->hide();

}

int getTrainerIdFromName(QString name){

    int i = 0;
    QSqlQuery getId;
    getId.prepare("SELECT Trainer.t_id FROM Trainer WHERE Trainer.t_name = (:name) ");
    getId.bindValue(":name", name);
    if(getId.exec()){
        while(getId.next()){

            i = stoi((getId.value(0).toString()).toStdString());
        }
    }

    return i;
}


void MainWindow::on_battleWindowButton_clicked()
{

   qDebug() << "zzzzzzzz;zzzzzzzzz;df" << trainerIdgotten;
    battlewindow->loadTeam2again();
    battlewindow->setTrainerSelected(trainerIdgotten);
    battlewindow->setTeamSelected(teamIdgotten);

    battlewindow->show();
    battlewindow->showFullScreen();
    this->hide();
}


void MainWindow::on_pushButton_clicked()
{

    vp->setTrainerId(teamIdgotten);
    vp->load();
    vp->loadTypes();
    vp->show();

    this->hide();
    //this->hide();

}


void MainWindow::on_pushButton_3_clicked()
{
    //ui->widget_3->startit();
    //ui->widget_2->stopit();
}


void MainWindow::on_comboBox_activated(int index)
{
    qDebug() << "Skdlfhsl;kdfhlska;df" << ui->comboBox->currentText() << getTrainerIdFromName(ui->comboBox->currentText());
    trainerIdgotten =  getTrainerIdFromName(ui->comboBox->currentText());
    battlewindow->setTrainerSelected(trainerIdgotten);

}


void MainWindow::on_teamsDrop_activated(int index)
{
    qDebug() << "Skdlfhsl;kdfhlska;df" << ui->teamsDrop->currentText() << (ui->teamsDrop->currentText());
    teamIdgotten =  stoi((ui->teamsDrop->currentText()).toStdString());
    battlewindow->setTeamSelected(teamIdgotten);
}

