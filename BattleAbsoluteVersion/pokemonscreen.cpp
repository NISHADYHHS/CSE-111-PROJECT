#include "pokemonscreen.h"
#include "ui_pokemonscreen.h"
#include "createteam.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <QPixmap>
PokemonScreen::PokemonScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PokemonScreen)
{
    ui->setupUi(this);
    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");
    if(pokemondb.open())
        qDebug() << "Open";
    else
        qDebug() << "Closed";
   // p = new Pokemon();
}

void PokemonScreen::setType1(QString type1){
    //ui->label->setText(name);
    //std::string s = type1.toStdString();
    //p->setPType1(s);
    //qDebug() << name.toStdString();
    ui->lineEdit_2->setText(type1);
    ui->widget->setType(ui->lineEdit_2->text());
}

void PokemonScreen::setPokemon(QString name){

    ui->lineEdit->setText(name);
   // QString s = "one";
   // ui->move_1->addItem(s);
}

void PokemonScreen::setPokemonID(QString id){

    ui->lineEdit_16->setText(id);
    loadPImage(stoi(id.toStdString()));
}

void PokemonScreen::addMovesToBox(std::vector<QString> moves){

    for(QString move: moves){
        ui->move_1->addItem(move);
        ui->move_2->addItem(move);
        ui->move_3->addItem(move);
        ui->move_4->addItem(move);
    }


}

void PokemonScreen::addSinguarMoveAsOption(QString movename){

    ui->move_1->addItem(movename);
     ui->move_2->addItem(movename);
     ui->move_3->addItem(movename);
      ui->move_4->addItem(movename);
}

void PokemonScreen::addItemOption(QString item){

    ui->itemselect->addItem(item);
}

void PokemonScreen::setPokemonAtt(QString attack){

    ui->lineEdit_4->setText(attack);
    ui->lineEdit_4->setReadOnly(true);
}
void PokemonScreen::setPokemonDef(QString defense){

    //qDebug() << name.toStdString();
    ui->lineEdit_12->setText(defense);
    ui->lineEdit_12->setReadOnly(true);
}
void PokemonScreen::setPokemonHp(QString hp){

    ui->lineEdit_11->setText(hp);
    ui->lineEdit_11->setReadOnly(true);

}
void PokemonScreen::setPokemonSpAtt(QString spattack){

    ui->lineEdit_9->setText(spattack);
    ui->lineEdit_9->setReadOnly(true);

}
void PokemonScreen::setPokemonSpDef(QString spdef){

    ui->lineEdit_10->setText(spdef);
    ui->lineEdit_10->setReadOnly(true);

}


void PokemonScreen::setType2(QString type2){

    ui->lineEdit_3->setText(type2);
    ui->lineEdit_3->setReadOnly(true);

}

void PokemonScreen::setSpeed(QString speed){

    ui->lineEdit_13->setText(speed);
    ui->lineEdit_13->setReadOnly(true);

}


PokemonScreen::~PokemonScreen()
{
    delete p;
    //delete mwindow;
    delete ui;
}

void PokemonScreen::on_move_4_activated(int index)
{
    ui->lineEdit_8->setText(ui->move_4->currentText());
    ui->lineEdit_8->setReadOnly(true);

}


void PokemonScreen::on_move_3_activated(int index)
{
    ui->lineEdit_7->setText(ui->move_3->currentText());
    ui->lineEdit_7->setReadOnly(true);

}


void PokemonScreen::on_move_2_activated(int index)
{
    ui->lineEdit_6->setText(ui->move_2->currentText());
    ui->lineEdit_6->setReadOnly(true);

}


void PokemonScreen::on_move_1_activated(int index)
{
    ui->lineEdit_5->setText(ui->move_1->currentText());
    ui->lineEdit_5->setReadOnly(true);

}


void PokemonScreen::on_itemselect_activated(int index)
{

    ui->lineEdit_14->setText(ui->itemselect->currentText());
    ui->lineEdit_14->setReadOnly(true);
}

int returnMoveID(QString movename){
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
            qDebug() << (id);
        }

    }
    std::string s = id.toStdString();

    return stoi(s);

}

void PokemonScreen::loadPImage(int pokemonID){

    std::string myText = "L";
    std::ifstream MyReadFile("C:/Users/nishb/OneDrive/Desktop/Battle/frontsprites.txt");

    // Use a while loop together with the getline() function to read the file line by line
    std::vector<QString> imageNames;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        imageNames.push_back(QString::fromStdString(myText));
    }
    QString defaultpath = "C:/Users/nishb/OneDrive/Desktop/Battle/front_sprites/";
    QString pathpt2 = imageNames[pokemonID - 1] + ".png";
    QString path = defaultpath+pathpt2;
    qDebug() << defaultpath+pathpt2;
    QPixmap pkman(path);
    ui->pImage->setPixmap(pkman);
    ui->pImage->setScaledContents(true);
}



void PokemonScreen::on_saveButton_clicked()
{
    int moveid1 = returnMoveID(ui->lineEdit_5->text());
    int moveid2 = returnMoveID(ui->lineEdit_6->text());
    int moveid3 = returnMoveID(ui->lineEdit_7->text());
    int moveid4 = returnMoveID(ui->lineEdit_8->text());
    qDebug() << moveid1;
    qDebug() << moveid2;
    qDebug() << moveid3;
    qDebug() << moveid4;


    QSqlQuery findnoofpokemon("SELECT * FROM TrainerPokemon WHERE p_trainerID = 1000");
    //QString number = findnoofpokemon.value(0).toString();
    int count = 0;
    while(findnoofpokemon.next()){
        count++;
    }
    qDebug() << count;
    int t_id = -100;
    if(count >= 6)
        t_id = -100;

    QSqlQuery getAbility;
    getAbility.prepare("SELECT p_ability1 FROM Pokemon WHERE p_id = (:p_id)");
    getAbility.bindValue(":p_id",stoi((ui->lineEdit_16->text()).toStdString()));
    QString gettheability;
    if (getAbility.exec())
    {
        while (getAbility.next())
        {
            gettheability = getAbility.value(0).toString();
        }
    }

    QSqlQuery query;
    query.prepare("INSERT INTO TrainerPokemon (p_id, p_ability, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName,tp_level) "
                  "VALUES (:p_id, :p_ability, :p_trainerID, :p_move1ID, :p_move2ID, :p_move3ID, :p_move4ID, :tp_itemName,:tp_level)");
    query.bindValue(":p_id", stoi((ui->lineEdit_16->text()).toStdString()));
    query.bindValue(":p_ability", gettheability);
    query.bindValue(":p_trainerID", t_id);
    query.bindValue(":p_move1ID", moveid1);
    query.bindValue(":p_move2ID", moveid2);
    query.bindValue(":p_move3ID", moveid3);
    query.bindValue(":p_move4ID", moveid4);
    query.bindValue(":tp_itemName", (ui->lineEdit_14->text()));
    query.bindValue(":tp_level", stoi((ui->lineEdit_15->text()).toStdString()));
    query.exec();
}


void PokemonScreen::on_doneButton_clicked()
{
    this->close();
    createteam *c = new createteam(this);

    c->show();
}

