#include "viewpokemonwindow.h"
#include "ui_viewpokemonwindow.h"
#include "mainwindow.h"
#include <vector>
#include <QVBoxLayout>
#include <QGridLayout>
#include <iostream>
#include <fstream>
#include <QPixmap>
#include <QStackedLayout>
ViewPokemonWindow::ViewPokemonWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewPokemonWindow)
{
    ui->setupUi(this);

    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");
    if(pokemondb.open())
        qDebug() << "Open";
    else
        qDebug() << "Closed";

    //load();
    //loadTypes();
    ui->hide1->setVisible(false);
    ui->hide2->setVisible(false);
    ui->hide3->setVisible(false);
    ui->hide4->setVisible(false);
    ui->hide5->setVisible(false);
    ui->hide6->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void ViewPokemonWindow::setTrainerId(int i){
    trainerId = i;
}

int ViewPokemonWindow::getTrainerId(){
    return trainerId;
}


QString ViewPokemonWindow::returnMoveName(int moveid){
    QSqlQuery moveIDs;
    moveIDs.prepare("SELECT * FROM Moves WHERE m_id = (:moveid)");
    moveIDs.bindValue(":moveid", moveid);
    QString name;
    if (moveIDs.exec())
    {
        while (moveIDs.next())
        {
            name = moveIDs.value(1).toString();
        }
    }
    return name;

}
QString ViewPokemonWindow::returnPokeName(int pid){
    QSqlQuery moveIDs;
    moveIDs.prepare("SELECT p_name FROM Pokemon WHERE p_id = (:pid)");
    moveIDs.bindValue(":pid", pid);
    QString name;
    if (moveIDs.exec())
    {
        while (moveIDs.next())
        {
            name = moveIDs.value(0).toString();
        }
    }
    return name;

}

int ViewPokemonWindow::returnPokeID(QString pname){
    QSqlQuery moveIDs;
    moveIDs.prepare("SELECT p_id FROM Pokemon WHERE p_name = (:pname)");
    moveIDs.bindValue(":pname", pname);
    QString id;
    if (moveIDs.exec())
    {
        while (moveIDs.next())
        {
            id = moveIDs.value(0).toString();
        }
    }

    return stoi(id.toStdString());

}

void ViewPokemonWindow::loadTypes(){
    std::vector<QString> types;

  //  QSqlQuery query("SELECT p_type1 FROM Pokemon INNER JOIN TrainerPokemon ON Pokemon.p_id = TrainerPokemon.p_id WHERE TrainerPokemon.p_trainerID = 1002");
    QSqlQuery query;
  query.prepare("SELECT p_type1 FROM Pokemon INNER JOIN TrainerPokemon ON Pokemon.p_id = TrainerPokemon.p_id WHERE TrainerPokemon.p_trainerID = (:tid)");
    query.bindValue(":tid",getTrainerId());
  query.exec();
    while(query.next()){
        types.push_back(query.value(0).toString());
        //ids.push_back(query.value(1).toString());
    }


    if(types.size() > 0)
        ui->pktype1->setType(types[0]);
    if(types.size() > 1)
        ui->pktype2->setType(types[1]);
    if(types.size() > 2)
        ui->pktype3->setType(types[2]);
    if(types.size() > 3)
        ui->pktype4->setType(types[3]);
    if(types.size() > 4)
        ui->pktype5->setType(types[4]);
    if(types.size() > 5)
        ui->pktype6->setType(types[5]);


    QSqlQuery query2;
    query2.prepare("SELECT * FROM TrainerPokemon WHERE TrainerPokemon.p_trainerID = (:tid)");
    query2.bindValue(":tid",getTrainerId());
    query2.exec();
    std::vector<QString> ids;
    while(query2.next()){
        ids.push_back(query2.value(0).toString());
        //ids.push_back(query.value(1).toString());
        qDebug() << "IDS TO SEND" << query2.value(0).toString();
    }

    loadingImage(ids);
}

void ViewPokemonWindow::loadingImage(std::vector<QString> ids){

    std::string myText = "L";

    std::ifstream MyReadFile("C:/Users/nishb/OneDrive/Desktop/Battle/frontsprites.txt");
    // Use a while loop together with the getline() function to read the file line by line
    std::vector<QString> imageNames;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        imageNames.push_back(QString::fromStdString(myText));
    }

    QString defaultpath = "C:/Users/nishb/OneDrive/Desktop/Battle/front_sprites/";

    int numberofcurrentids = ids.size();
    int count = 0;
    for(QString e: ids){
        count++;
        QString pathpt2 = imageNames[stoi(e.toStdString()) - 1] + ".png";
        QString path = defaultpath+pathpt2;
        qDebug() << defaultpath+pathpt2;
        QPixmap pkman(path);

        if(count == 1){
            ui->pImage1->setPixmap(pkman);
            ui->pImage1->setScaledContents(true);
        }
        if(count == 2){
            ui->pImage2->setPixmap(pkman);
            ui->pImage2->setScaledContents(true);
        }
        if(count == 3){
            ui->pImage3->setPixmap(pkman);
            ui->pImage3->setScaledContents(true);
        }
        if(count == 4){
            ui->pImage4->setPixmap(pkman);
            ui->pImage4->setScaledContents(true);
        }
        if(count == 5){
            ui->pImage5->setPixmap(pkman);
            ui->pImage5->setScaledContents(true);
        }
        if(count == 6){
            ui->pImage6->setPixmap(pkman);
            ui->pImage6->setScaledContents(true);
        }

    }
}

void ViewPokemonWindow::load(){



    QSqlQuery query;
    query.prepare("SELECT * FROM TrainerPokemon WHERE TrainerPokemon.p_trainerID = (:tid)");
    query.bindValue(":tid",getTrainerId());
    query.exec();

    int pname = query.record().indexOf("p_id");
    int plevel = query.record().indexOf("tp_level");
    int pmove1 = query.record().indexOf("p_move1ID");
    int pmove2 = query.record().indexOf("p_move2ID");
    int pmove3 = query.record().indexOf("p_move3ID");
    int pmove4 = query.record().indexOf("p_move4ID");
    int item = query.record().indexOf("tp_itemName");
    int pability = query.record().indexOf("p_ability");
    int count = 0;
     qDebug() << "FUCKING WORK" << query.value(2).toString();
    std::vector<QString> stats;
    while(query.next()){
        stats.clear();
        count++;

        QString n = query.value(pname).toString();
        stats.push_back(n);
        QString pm1 = query.value(pmove1).toString();
        stats.push_back(pm1);
        QString pm2 = query.value(pmove2).toString();
        stats.push_back(pm2);
        QString pm3 = query.value(pmove3).toString();
        stats.push_back(pm3);
        QString pm4 = query.value(pmove4).toString();
        stats.push_back(pm4);
        QString ite = query.value(item).toString();
        stats.push_back(ite);
        QString lev = query.value(plevel).toString();
        stats.push_back(lev);
        QString ab = query.value(pability).toString();
        stats.push_back(ab);
        loadInPokemon(count, stats);
        /*ui->lineEdit->setText(returnPokeName(stoi(n.toStdString())));
        ui->lineEdit_2->setText(returnMoveName(stoi(pm1.toStdString())));
        ui->lineEdit_3->setText(returnMoveName(stoi(pm2.toStdString())));
        ui->lineEdit_4->setText(returnMoveName(stoi(pm3.toStdString())));
        ui->lineEdit_5->setText(returnMoveName(stoi(pm4.toStdString())));
        ui->lineEdit_6->setText(ite);
        ui->lineEdit_7->setText(lev);
        ui->lineEdit_8->setText(ab);*/


    }

}

void ViewPokemonWindow::loadInPokemon(int position, std::vector<QString> &stats){

    switch(position){
        case 1:
            ui->lineEdit->setText(returnPokeName(stoi(stats[0].toStdString())));
            ui->lineEdit_2->setText(returnMoveName(stoi(stats[1].toStdString())));
            ui->lineEdit_3->setText(returnMoveName(stoi(stats[2].toStdString())));
            ui->lineEdit_4->setText(returnMoveName(stoi(stats[3].toStdString())));
            ui->lineEdit_5->setText(returnMoveName(stoi(stats[4].toStdString())));
            ui->lineEdit_6->setText(stats[5]);
            ui->lineEdit_7->setText(stats[6]);
            ui->lineEdit_8->setText(stats[7]);
            break;
        case 2:
            ui->lineEdit_9->setText(returnPokeName(stoi(stats[0].toStdString())));
            ui->lineEdit_10->setText(returnMoveName(stoi(stats[1].toStdString())));
            ui->lineEdit_14->setText(returnMoveName(stoi(stats[2].toStdString())));
            ui->lineEdit_15->setText(returnMoveName(stoi(stats[3].toStdString())));
            ui->lineEdit_16->setText(returnMoveName(stoi(stats[4].toStdString())));
            ui->lineEdit_17->setText(stats[5]);
            ui->lineEdit_18->setText(stats[6]);
            ui->lineEdit_189->setText(stats[7]);
            break;
        case 3:
            ui->lineEdit_22->setText(returnPokeName(stoi(stats[0].toStdString())));
            ui->lineEdit_20->setText(returnMoveName(stoi(stats[1].toStdString())));
            ui->lineEdit_23->setText(returnMoveName(stoi(stats[2].toStdString())));
            ui->lineEdit_25->setText(returnMoveName(stoi(stats[3].toStdString())));
            ui->lineEdit_19->setText(returnMoveName(stoi(stats[4].toStdString())));
            ui->lineEdit_24->setText(stats[5]);
            ui->lineEdit_21->setText(stats[6]);
            ui->lineEdit_26->setText(stats[7]);
            break;
        case 4:
            ui->lineEdit_30->setText(returnPokeName(stoi(stats[0].toStdString())));
            ui->lineEdit_28->setText(returnMoveName(stoi(stats[1].toStdString())));
            ui->lineEdit_31->setText(returnMoveName(stoi(stats[2].toStdString())));
            ui->lineEdit_33->setText(returnMoveName(stoi(stats[3].toStdString())));
            ui->lineEdit_27->setText(returnMoveName(stoi(stats[4].toStdString())));
            ui->lineEdit_32->setText(stats[5]);
            ui->lineEdit_29->setText(stats[6]);
            ui->lineEdit_34->setText(stats[7]);
            break;
        case 5:
            ui->lineEdit_38->setText(returnPokeName(stoi(stats[0].toStdString())));
            ui->lineEdit_36->setText(returnMoveName(stoi(stats[1].toStdString())));
            ui->lineEdit_39->setText(returnMoveName(stoi(stats[2].toStdString())));
            ui->lineEdit_41->setText(returnMoveName(stoi(stats[3].toStdString())));
            ui->lineEdit_35->setText(returnMoveName(stoi(stats[4].toStdString())));
            ui->lineEdit_40->setText(stats[5]);
            ui->lineEdit_37->setText(stats[6]);
            ui->lineEdit_42->setText(stats[7]);
            break;
        case 6:
            ui->lineEdit_46->setText(returnPokeName(stoi(stats[0].toStdString())));
            ui->lineEdit_44->setText(returnMoveName(stoi(stats[1].toStdString())));
            ui->lineEdit_47->setText(returnMoveName(stoi(stats[2].toStdString())));
            ui->lineEdit_49->setText(returnMoveName(stoi(stats[3].toStdString())));
            ui->lineEdit_43->setText(returnMoveName(stoi(stats[4].toStdString())));
            ui->lineEdit_48->setText(stats[5]);
            ui->lineEdit_45->setText(stats[6]);
            ui->lineEdit_50->setText(stats[7]);
            break;
    }

}

ViewPokemonWindow::~ViewPokemonWindow()
{
    delete ui;
    //delete mainwindow;
}

void ViewPokemonWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    addButton();
}

void ViewPokemonWindow::addButton(){
    const QSize BUTTON_SIZE = QSize(60, 60);

    std::string myText = "L";
    std::ifstream MyReadFile("C:/Users/nishb/OneDrive/Desktop/Battle/frontsprites.txt");
    std::vector<QString> imageNames;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        imageNames.push_back(QString::fromStdString(myText));
    }
    QString defaultpath = "C:/Users/nishb/OneDrive/Desktop/Battle/front_sprites/";





    QSqlQuery query("SELECT * FROM TrainerPokemon WHERE TrainerPokemon.p_trainerID = -100");
    int pname = query.record().indexOf("p_id");
    int count = 0;
    int countfory = 1;
    int listedCount = 0;
    while(query.next()){
        listedCount++;
        if(count > 5){
            count = 0;
            countfory++;
        }
        for(int y = countfory; y < countfory+ 1; y++){
            QBrush tb(Qt::transparent);
            QPushButton* button = new QPushButton(returnPokeName(stoi((query.value(pname).toString()).toStdString())) + QString::number(listedCount));
            button->setFixedSize(BUTTON_SIZE);
            button->setPalette(QPalette(tb,tb,tb,tb,tb,tb,tb,tb,tb));
            button->setFlat(true);
            QLabel* label = new QLabel("hello");
            label->setFixedSize(QSize(60, 60));

            QString pathpt2 = imageNames[stoi((query.value(pname).toString()).toStdString()) - 1] + ".png";
            QString path = defaultpath + pathpt2;
            QPixmap pkman(path);

            label->setPixmap(pkman);
            label->setScaledContents(true);
            ui->gridLayout->addWidget(label,count,y);
            ui->gridLayout->addWidget(button,count,y);

            QObject::connect(
                button, &QPushButton::clicked,this,&ViewPokemonWindow::removeButton
                );
        }
        count++;
    }

}

std::vector<QString> ViewPokemonWindow::returnStats(int pid){
    std::vector<QString> stats;
    QSqlQuery moveIDs;
    moveIDs.prepare("SELECT * FROM Pokemon WHERE p_id = (:pid)");
    moveIDs.bindValue(":pid", pid);
    QString attack;
    QString hp;
    QString spattack;
    QString defense;
    QString spdefense;
    QString speed;
    QString type1;
    QString type2;
    if (moveIDs.exec())
    {
        while (moveIDs.next())
        {
            hp = moveIDs.value(14).toString();
            attack = moveIDs.value(15).toString();
            type1 = moveIDs.value(5).toString();
            type2 = moveIDs.value(6).toString();
            defense = moveIDs.value(16).toString();
            spattack = moveIDs.value(17).toString();
            spdefense = moveIDs.value(16).toString();
            speed = moveIDs.value(19).toString();
            stats.push_back(attack);
            stats.push_back(defense);
            stats.push_back(spattack);
            stats.push_back(spdefense);
            stats.push_back(speed);
            stats.push_back(hp);
            stats.push_back(type1);
            stats.push_back(type2);

        }
    }
    return stats;

}

int realID = 0;
void ViewPokemonWindow::removeLabel(){


}
void ViewPokemonWindow::removeButton(){

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonTxt = button->text();
    std::string btxt = buttonTxt.toStdString();
    int indexNumber = btxt[btxt.length() -1 ] - '0';

    QSqlQuery query("SELECT * FROM TrainerPokemon WHERE TrainerPokemon.p_trainerID = -100");
    int pname = query.record().indexOf("p_id");
    int plevel = query.record().indexOf("tp_level");
    int pmove1 = query.record().indexOf("p_move1ID");
    int pmove2 = query.record().indexOf("p_move2ID");
    int pmove3 = query.record().indexOf("p_move3ID");
    int pmove4 = query.record().indexOf("p_move4ID");
    int item = query.record().indexOf("tp_itemName");
    int pability = query.record().indexOf("p_ability");

    int count = 0;
    QSqlQuery query2("SELECT * FROM TrainerPokemon WHERE TrainerPokemon.p_trainerID = -100");
    int q2name = query2.record().indexOf("p_id");
    int indexofpokemon = 0;
    while(query2.next()){

        count++;
        QString n = query2.value(q2name).toString();
        if(count == indexNumber){
            indexofpokemon = stoi(n.toStdString());
        }
    }
    count = 0;

    std::vector<QString> stats = returnStats(indexofpokemon);

    std::string myText = "L";
    std::ifstream MyReadFile("C:/Users/nishb/OneDrive/Desktop/Battle/frontsprites.txt");
    std::vector<QString> imageNames;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        imageNames.push_back(QString::fromStdString(myText));
    }
    QString defaultpath = "C:/Users/nishb/OneDrive/Desktop/Battle/front_sprites/";
    //qDebug() << "and" << indexofpokemon;
    while(query.next()){
        count++;
        QString n = query.value(pname).toString();
        QString pm1 = query.value(pmove1).toString();
        QString pm2 = query.value(pmove2).toString();
        QString pm3 = query.value(pmove3).toString();
        QString pm4 = query.value(pmove4).toString();
        QString ite = query.value(item).toString();
        QString lev = query.value(plevel).toString();
        QString ab = query.value(pability).toString();



        if(count == indexNumber){

            QString pt2ofpath = n +".png";
            QPixmap pixmap(defaultpath + pt2ofpath);
            ui->pokemonPic->setPixmap(pixmap);
            ui->pokemonPic->setScaledContents(true);
            ui->label_65->setText(returnPokeName(stoi(n.toStdString())));;
           // qDebug() <<  returnPokeName(indexofpokemon);
            ui->lineEdit_52->setText(returnMoveName(stoi(pm1.toStdString())));
            ui->lineEdit_51->setText(ab);
            ui->lineEdit_56->setText(ite);
            ui->lineEdit_59->setText(lev);
            ui->lineEdit_53->setText(returnMoveName(stoi(pm2.toStdString())));;
            ui->lineEdit_54->setText(returnMoveName(stoi(pm3.toStdString())));;
            ui->lineEdit_55->setText(returnMoveName(stoi(pm4.toStdString())));;
            ui->lineEdit_60->setText( stats[0]);
            ui->lineEdit_62->setText( stats[1]);
            ui->lineEdit_61->setText( stats[2]);
            ui->lineEdit_57->setText( stats[3]);
            ui->lineEdit_58->setText( stats[4]);
            ui->lineEdit_63->setText( stats[5]);
            ui->lineEdit_12->setText( stats[6]);
            ui->lineEdit_13->setText( stats[7]);

            break;
        }
    }

   // button->setFlat(false);
    //button->setEnabled(false);
    realID = (indexNumber - 2) + indexNumber;


}

void ViewPokemonWindow::on_pushButton_2_clicked()
{
    MainWindow *mainwindow = new MainWindow();
    this->hide();
    mainwindow->show();
}
int ViewPokemonWindow::returnMoveIDD(QString movename){
    QSqlQuery moveIDs;
    moveIDs.prepare("SELECT * FROM Moves WHERE m_name = (:movename)");
    moveIDs.bindValue(":movename", movename);
    //int moveid = moveIDs.record().indexOf("m_id");
    //qDebug() << (moveid) << movename;
    QString id;
    if (moveIDs.exec())
    {
        while (moveIDs.next())
        {
            id = moveIDs.value(0).toString();
           // qDebug() << (id);
        }

    }
    std::string s = id.toStdString();

    return stoi(s);

}

void ViewPokemonWindow::on_send1_clicked()
{

    QString name =  ui->lineEdit->text();
    int move1 =  returnMoveIDD(ui->lineEdit_2->text());
    int move2 =  returnMoveIDD(ui->lineEdit_3->text());
    int move3 =  returnMoveIDD(ui->lineEdit_4->text());
    int move4 =  returnMoveIDD(ui->lineEdit_5->text());
    QString item =  ui->lineEdit_6->text();
    int level =  stoi((ui->lineEdit_7->text()).toStdString());
    QString ability =  ui->lineEdit_8->text();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->pktype1->setType("none");

    //qDebug() << returnPokeID(name);
    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = (:tid)");
    deletequery.bindValue(":id", returnPokeID(name));
    deletequery.bindValue(":tid",getTrainerId());
    /*deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.bindValue(":move3", move3);
    deletequery.bindValue(":move4", move4);
    deletequery.bindValue(":item", item);
    deletequery.bindValue(":level", level);*/
    deletequery.exec();


    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                  "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", returnPokeID(name));
        addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", -100);
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();

    QSqlQuery e("SELECT p_id FROM TrainerPokemon");
    while(e.next()){
       // qDebug() << e.value(0).toString();
    }
    //load();

    ui->hide1->setVisible(true);
        ui->hide1->setEnabled(false);
}


void ViewPokemonWindow::on_send2_clicked()
{

    QString name =  ui->lineEdit_9->text();
    int move1 =  returnMoveIDD(ui->lineEdit_10->text());
    int move2 =  returnMoveIDD(ui->lineEdit_14->text());
    int move3 =  returnMoveIDD(ui->lineEdit_15->text());
    int move4 =  returnMoveIDD(ui->lineEdit_16->text());
    QString item =  ui->lineEdit_17->text();
    int level =  stoi((ui->lineEdit_18->text()).toStdString());
    QString ability =  ui->lineEdit_189->text();

    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_189->clear();
    ui->pktype2->setType("none");


    //qDebug() << returnPokeID(name);
    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = (:tid)");
    deletequery.bindValue(":id", returnPokeID(name));
    deletequery.bindValue(":tid", getTrainerId());
    /*deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.bindValue(":move3", move3);
    deletequery.bindValue(":move4", move4);
    deletequery.bindValue(":item", item);
    deletequery.bindValue(":level", level);*/
    deletequery.exec();


    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                     "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", returnPokeID(name));
    addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", -100);
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();

    QSqlQuery e("SELECT p_id FROM TrainerPokemon");
    while(e.next()){
        //qDebug() << e.value(0).toString();
    }
     //load();
    ui->hide2->setVisible(true);
    ui->hide2->setEnabled(false);
}


void ViewPokemonWindow::on_send3_clicked()
{

    QString name =  ui->lineEdit_22->text();
    int move1 =  returnMoveIDD(ui->lineEdit_20->text());
    int move2 =  returnMoveIDD(ui->lineEdit_23->text());
    int move3 =  returnMoveIDD(ui->lineEdit_25->text());
    int move4 =  returnMoveIDD(ui->lineEdit_19->text());
    QString item =  ui->lineEdit_24->text();
    int level =  stoi((ui->lineEdit_21->text()).toStdString());
    QString ability =  ui->lineEdit_26->text();

    ui->lineEdit_22->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_23->clear();
    ui->lineEdit_25->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();
    ui->lineEdit_24->clear();
    ui->lineEdit_21->clear();
    ui->pktype3->setType("none");


    //qDebug() << returnPokeID(name);
    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = (:tid)");
    deletequery.bindValue(":id", returnPokeID(name));
    deletequery.bindValue(":tid", getTrainerId());

    /*deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.bindValue(":move3", move3);
    deletequery.bindValue(":move4", move4);
    deletequery.bindValue(":item", item);
    deletequery.bindValue(":level", level);*/
    deletequery.exec();


    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                     "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", returnPokeID(name));
    addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", -100);
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();

    QSqlQuery e("SELECT p_id FROM TrainerPokemon");
    while(e.next()){
       // qDebug() << e.value(0).toString();
    }
     //load();
    ui->hide3->setVisible(true);
    ui->hide3->setEnabled(false);
}


void ViewPokemonWindow::on_send4_clicked()
{

    QString name =  ui->lineEdit_30->text();
    int move1 =  returnMoveIDD(ui->lineEdit_28->text());
    int move2 =  returnMoveIDD(ui->lineEdit_31->text());
    int move3 =  returnMoveIDD(ui->lineEdit_33->text());
    int move4 =  returnMoveIDD(ui->lineEdit_27->text());
    QString item =  ui->lineEdit_32->text();
    int level =  stoi((ui->lineEdit_29->text()).toStdString());
    QString ability =  ui->lineEdit_34->text();

    ui->lineEdit_30->clear();
    ui->lineEdit_28->clear();
    ui->lineEdit_31->clear();
    ui->lineEdit_33->clear();
    ui->lineEdit_34->clear();
    ui->lineEdit_27->clear();
    ui->lineEdit_32->clear();
    ui->lineEdit_29->clear();
    ui->pktype4->setType("none");

    //qDebug() << returnPokeID(name);
    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = (:tid)");
    deletequery.bindValue(":id", returnPokeID(name));
    deletequery.bindValue(":tid", getTrainerId());

    /*deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.bindValue(":move3", move3);
    deletequery.bindValue(":move4", move4);
    deletequery.bindValue(":item", item);
    deletequery.bindValue(":level", level);*/
    deletequery.exec();


    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                     "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", returnPokeID(name));
    addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", -100);
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();

    QSqlQuery e("SELECT p_id FROM TrainerPokemon");
    while(e.next()){
       // qDebug() << e.value(0).toString();
    }
    // load();
    ui->hide4->setVisible(true);
    ui->hide4->setEnabled(false);

}


void ViewPokemonWindow::on_send5_clicked()
{

    QString name =  ui->lineEdit_38->text();
    int move1 =  returnMoveIDD(ui->lineEdit_36->text());
    int move2 =  returnMoveIDD(ui->lineEdit_39->text());
    int move3 =  returnMoveIDD(ui->lineEdit_41->text());
    int move4 =  returnMoveIDD(ui->lineEdit_35->text());
    QString item =  ui->lineEdit_40->text();
    int level =  stoi((ui->lineEdit_37->text()).toStdString());
    QString ability =  ui->lineEdit_42->text();
    ui->lineEdit_38->clear();
    ui->lineEdit_36->clear();
    ui->lineEdit_39->clear();
    ui->lineEdit_41->clear();
    ui->lineEdit_35->clear();
    ui->lineEdit_40->clear();
    ui->lineEdit_37->clear();
    ui->lineEdit_42->clear();
    ui->pktype5->setType("none");


    //qDebug() << returnPokeID(name);
    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = (:tid)");
    deletequery.bindValue(":id", returnPokeID(name));
    deletequery.bindValue(":tid", getTrainerId());

    /*deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.bindValue(":move3", move3);
    deletequery.bindValue(":move4", move4);
    deletequery.bindValue(":item", item);
    deletequery.bindValue(":level", level);*/
    deletequery.exec();


    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                     "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", returnPokeID(name));
    addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", -100);
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();

    QSqlQuery e("SELECT p_id FROM TrainerPokemon");
    while(e.next()){
        //qDebug() << e.value(0).toString();
    }
    // load();
    ui->hide5->setVisible(true);
    ui->hide5->setEnabled(false);


}


void ViewPokemonWindow::on_send6_clicked()
{

    QString name =  ui->lineEdit_46->text();
    int move1 =  returnMoveIDD(ui->lineEdit_44->text());
    int move2 =  returnMoveIDD(ui->lineEdit_47->text());
    int move3 =  returnMoveIDD(ui->lineEdit_49->text());
    int move4 =  returnMoveIDD(ui->lineEdit_43->text());
    QString item =  ui->lineEdit_48->text();
    int level =  stoi((ui->lineEdit_45->text()).toStdString());
    QString ability =  ui->lineEdit_50->text();
    ui->lineEdit_46->clear();
    ui->lineEdit_44->clear();
    ui->lineEdit_47->clear();
    ui->lineEdit_49->clear();
    ui->lineEdit_43->clear();
    ui->lineEdit_48->clear();
    ui->lineEdit_45->clear();
    ui->lineEdit_50->clear();
    ui->pktype6->setType("none");


   // qDebug() << returnPokeID(name);
    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = (:tid) AND p_move1ID = (:move1) AND p_move2ID = (:move2)");
    deletequery.bindValue(":id", returnPokeID(name));
    deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.bindValue(":tid", getTrainerId());
    /*deletequery.bindValue(":move3", move3);
    deletequery.bindValue(":move4", move4);
    deletequery.bindValue(":item", item);
    deletequery.bindValue(":level", level);*/
    deletequery.exec();


    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                     "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", returnPokeID(name));
    addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", -100);
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();

    QSqlQuery e("SELECT p_id FROM TrainerPokemon");
    while(e.next()){
       // qDebug() << e.value(0).toString();
    }

   // load();
    ui->hide6->setVisible(true);
    ui->hide6->setEnabled(false);

}


void ViewPokemonWindow::on_pushButton_3_clicked()
{

   /* const QSize BUTTON_SIZE = QSize(800, 500);
    QPushButton* button = new QPushButton();
    button->setFixedSize(BUTTON_SIZE);
    button->setVisible(true);
    QStackedLayout *stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(button);
    ui->page_4->setLayout(stackedLayout);*/

    QSqlQuery partynumber;
   partynumber.prepare("SELECT COUNT(*) FROM TrainePokemon WHERE p_trainerID = (:tid)");
   partynumber.bindValue(":tid", getTrainerId());
   partynumber.exec();
    while(partynumber.next()){
       // qDebug() << "number in party: " <<partynumber.value(0).toString();
    }


    for (int i=0; i < ui->gridLayout->count(); ++i) {
        QLayoutItem *item = ui->gridLayout->itemAt(i);
        if (!item || !item->widget())
            continue;
        QLabel *lab = qobject_cast<QLabel*>(item->widget());
        if(lab){
            QString path = "C:/Users/nishb/OneDrive/Desktop/Battle/back_sprite/0.png";
            QPixmap blank(path);
             lab->setPixmap(blank);
        }

    }


    int id = (returnPokeID(ui->label_65->text()));
    int move1 = returnMoveIDD(ui->lineEdit_52->text());
    QString ability = ui->lineEdit_51->text();
    QString item =ui->lineEdit_56->text();
    QString level =ui->lineEdit_59->text();
    int move2 = returnMoveIDD(ui->lineEdit_53->text());
    int move3 = returnMoveIDD(ui->lineEdit_54->text());
    int move4 = returnMoveIDD(ui->lineEdit_55->text());


    QSqlQuery deletequery;
    deletequery.prepare("DELETE FROM TrainerPokemon WHERE p_id = (:id) AND p_trainerID = -100 AND p_move1ID = (:move1) AND p_move2ID = (:move2)");
    deletequery.bindValue(":id", id);
    deletequery.bindValue(":move1", move1);
    deletequery.bindValue(":move2", move2);
    deletequery.exec();

    ui->label_65->clear();
    ui->lineEdit_52->clear();
    ui->lineEdit_51->clear();
    ui->lineEdit_56->clear();
    ui->lineEdit_59->clear();
    ui->lineEdit_53->clear();
    ui->lineEdit_54->clear();
    ui->lineEdit_55->clear();
    QPixmap pixmap("C:/Users/nishb/OneDrive/Desktop/Battle/back_sprite/0.png");
    ui->pokemonPic->setPixmap(pixmap);

    for (int i=0; i < ui->gridLayout->count(); ++i) {
        QLayoutItem *item = ui->gridLayout->itemAt(i);
        ui->gridLayout->removeItem(item);
        qDebug()<<ui->gridLayout->count();

    }

    QSqlQuery addquery;
    addquery.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                     "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    addquery.bindValue(":p_id", id);
    addquery.bindValue(":p_ability", ability);
    addquery.bindValue(":p_trainerID", getTrainerId());
    addquery.bindValue(":p_move1ID", move1);
    addquery.bindValue(":p_move2ID", move2);
    addquery.bindValue(":p_move3ID", move3);
    addquery.bindValue(":p_move4ID", move4);
    addquery.bindValue(":tp_itemName", item);
    addquery.bindValue(":tp_level", level);
    addquery.exec();
    addButton();
    load();
    loadTypes();
    //loadingImage();
    ui->stackedWidget->setCurrentIndex(0);

    ui->stackedWidget->setCurrentIndex(1);
    //ui->gridLayout->itemAt(realID);


}


void ViewPokemonWindow::on_pushButton_4_clicked()
{
    //this->hide();
   // MainWindow *mainwindow = new MainWindow();
   // mainwindow->on_pushButton_clicked();
    ui->lineEdit_46->clear();
    ui->lineEdit_44->clear();
    ui->lineEdit_47->clear();
    ui->lineEdit_49->clear();
    ui->lineEdit_43->clear();
    ui->lineEdit_48->clear();
    ui->lineEdit_45->clear();
    ui->lineEdit_50->clear();
    ui->lineEdit_38->clear();
    ui->lineEdit_36->clear();
    ui->lineEdit_39->clear();
    ui->lineEdit_41->clear();
    ui->lineEdit_35->clear();
    ui->lineEdit_40->clear();
    ui->lineEdit_37->clear();
    ui->lineEdit_42->clear();
    ui->lineEdit_30->clear();
    ui->lineEdit_28->clear();
    ui->lineEdit_31->clear();
    ui->lineEdit_33->clear();
    ui->lineEdit_34->clear();
    ui->lineEdit_27->clear();
    ui->lineEdit_32->clear();
    ui->lineEdit_29->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_23->clear();
    ui->lineEdit_25->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();
    ui->lineEdit_24->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_189->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->pktype1->setType("none");
    ui->pktype2->setType("none");
    ui->pktype3->setType("none");
    ui->pktype4->setType("none");
    ui->pktype5->setType("none");
    ui->pktype6->setType("none");
    QPixmap pixmap("C:/Users/nishb/OneDrive/Desktop/Battle/back_sprite/0.png");
    ui->pImage1->setPixmap(pixmap);
    ui->pImage2->setPixmap(pixmap);
    ui->pImage3->setPixmap(pixmap);
    ui->pImage4->setPixmap(pixmap);
    ui->pImage5->setPixmap(pixmap);
    ui->pImage6->setPixmap(pixmap);


    load();
    loadTypes();
    ui->stackedWidget->setCurrentIndex(0);
    if(ui->lineEdit->text().length() > 1)
        ui->hide1->setVisible(false);
    if(ui->lineEdit_9->text().length() > 1)
        ui->hide2->setVisible(false);
    if(ui->lineEdit_22->text().length() > 1)
        ui->hide3->setVisible(false);
    if(ui->lineEdit_30->text().length() > 1)
        ui->hide4->setVisible(false);
    if(ui->lineEdit_38->text().length() > 1)
        ui->hide5->setVisible(false);
    if(ui->lineEdit_46->text().length() > 1)
        ui->hide6->setVisible(false);

}

