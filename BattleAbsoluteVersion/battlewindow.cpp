#include "battlewindow.h"
#include "ui_battlewindow.h"
#include "battlewidget.h""
#include <QtWidgets>
#include <QSqlDatabase>
class Move;
class Pokemon;
class Ability;

#include <string>
#include "Move.h"
#include "Pokemon.h"
#include "Ability.h"
#include "Battle.h"
#include "Team.h"
#include <fstream>
#include "mainwindow.h"

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <pokemon.h>
#include <vector>
#include <string>

#include <QString>


Pokemon hydreigon(
    635, "Hydreigon", 100, "None",
    "Dark", "Dragon", 1.8, 160.0,
    "Levitate", "Genderless", 92,
    105, 90, 125, 90, 98,
    {
        Move(1, "Dragon Pulse", "Dragon", "Special", 85, 10, 100),
        Move(2, "Dark Pulse", "Dark", "Special", 80, 15, 100),
        Move(3, "Flamethrower", "Fire", "Special", 90, 15, 100),
        Move(4, "Earthquake", "Ground", "Physical", 100, 10, 100)
    }
    );
Pokemon volcarona(
    637, "Volcarona", 100, "None",
    "Bug", "Fire", 1.6, 46.0,
    "Flame Body", "Genderless", 85,
    60, 65, 135, 105, 100,
    {
        Move(5, "Bug Buzz", "Bug", "Special", 90, 10, 100),
        Move(6, "Fiery Dance", "Fire", "Special", 80, 15, 100),
        Move(7, "Quiver Dance", "Bug", "Status", 0, 20, 0),
        Move(8, "Giga Drain", "Grass", "Special", 75, 10, 100)
    }
    );

Pokemon blastoise(
    9, "Blastoise", 100, "Blastoisinite", // Assuming Mega Blastoise with Blastoisinite
    "Water", "", 1.6, 85.5, // Blastoise has a single type, so type2 is empty
    "Torrent", "Male", 79, // Base HP: 79
    83, 100, 78, 85, 105, // Base stats: Attack: 83, Defense: 100, Sp. Attack: 78, Sp. Defense: 85, Speed: 105
    {
        Move(9, "Hydro Pump", "Water", "Special", 110, 5, 80),
        Move(10, "Ice Beam", "Ice", "Special", 90, 10, 100),
        Move(11, "Aura Sphere", "Fighting", "Special", 80, 20, 100),
        Move(12, "Dark Pulse", "Dark", "Special", 80, 15, 100)
    }
    );


Pokemon venusaur(
    3, "Venusaur", 100, "Venusaurite", // Assuming Mega Venusaur with Venusaurite
    "Grass", "Poison", 2.0, 100.0,
    "Overgrow", "Male", 80, // Base HP: 80
    82, 83, 100, 100, 80, // Base stats: Attack: 82, Defense: 83, Sp. Attack: 100, Sp. Defense: 100, Speed: 80
    {
        Move(13, "Solar Beam", "Grass", "Special", 120, 10, 100),
        Move(14, "Sludge Bomb", "Poison", "Special", 90, 10, 100),
        Move(15, "Earthquake", "Ground", "Physical", 100, 10, 100),
        Move(16, "Synthesis", "Grass", "Status", 0, 5, 0) // A healing move
    }
    );

Pokemon lugia(
    249, "Lugia", 100, "None",
    "Psychic", "Flying", 5.2, 216.0,
    "Pressure", "Genderless", 106, // Base HP: 106
    90, 130, 110, 154, 110, // Base stats: Attack: 90, Defense: 130, Sp. Attack: 110, Sp. Defense: 154, Speed: 110
    {
        Move(21, "Aeroblast", "Flying", "Special", 100, 5, 95),
        Move(22, "Psychic", "Psychic", "Special", 90, 10, 100),
        Move(23, "Roost", "Flying", "Status", 0, 10, 0), // A healing move
        Move(24, "Dragon Pulse", "Dragon", "Special", 85, 10, 100)
    }
    );

Pokemon tyranitar(
    248, "Tyranitar", 100, "Tyranitarite", // Assuming Mega Tyranitar with Tyranitarite
    "Rock", "Dark", 2.5, 255.0,
    "Sand Stream", "Male", 100, // Base HP: 100
    134, 110, 95, 100, 61, // Base stats: Attack: 134, Defense: 110, Sp. Attack: 95, Sp. Defense: 100, Speed: 61
    {
        Move(25, "Stone Edge", "Rock", "Physical", 100, 5, 80),
        Move(26, "Crunch", "Dark", "Physical", 80, 15, 100),
        Move(27, "Earthquake", "Ground", "Physical", 100, 10, 100),
        Move(28, "Ice Punch", "Ice", "Physical", 75, 15, 100)
    }
    );

Pokemon salamence(
    373, "Salamence", 100, "Salamencite", // Assuming Mega Salamence with Salamencite
    "Dragon", "Flying", 1.5, 102.6,
    "Intimidate", "Male", 95, // Base HP: 95
    135, 80, 110, 110, 120, // Base stats: Attack: 135, Defense: 80, Sp. Attack: 110, Sp. Defense: 110, Speed: 120
    {
        Move(29, "Dragon Claw", "Dragon", "Physical", 80, 15, 100),
        Move(30, "Fire Blast", "Fire", "Special", 110, 5, 85),
        Move(31, "Aerial Ace", "Flying", "Physical", 60, 20, 0), // Always hits
        Move(32, "Earthquake", "Ground", "Physical", 100, 10, 100)
    }
    );

Pokemon metagross(
    376, "Metagross", 100, "Metagrossite", // Assuming Mega Metagross with Metagrossite
    "Steel", "Psychic", 1.6, 550.0,
    "Clear Body", "Genderless", 80, // Base HP: 80
    135, 130, 95, 90, 70, // Base stats: Attack: 135, Defense: 130, Sp. Attack: 95, Sp. Defense: 90, Speed: 70
    {
        Move(33, "Meteor Mash", "Steel", "Physical", 90, 10, 90),
        Move(34, "Psychic", "Psychic", "Special", 90, 10, 100),
        Move(35, "Earthquake", "Ground", "Physical", 100, 10, 100),
        Move(36, "Bullet Punch", "Steel", "Physical", 40, 30, 100)
    }
    );

Pokemon garchomp(
    445, "Garchomp", 100, "Garchompite", // Assuming Mega Garchomp with Garchompite
    "Dragon", "Ground", 1.9, 95.0,
    "Sand Veil", "Male", 108, // Base HP: 108
    130, 95, 85, 80, 102, // Base stats: Attack: 130, Defense: 95, Sp. Attack: 85, Sp. Defense: 80, Speed: 102
    {
        Move(37, "Dragon Claw", "Dragon", "Physical", 80, 15, 100),
        Move(38, "Earthquake", "Ground", "Physical", 100, 10, 100),
        Move(39, "Stone Edge", "Rock", "Physical", 100, 5, 80),
        Move(40, "Fire Fang", "Fire", "Physical", 65, 15, 95)
    }
    );

Pokemon gengar(
    94, "Gengar", 100, "Gengarite", // Assuming Mega Gengar with Gengarite
    "Ghost", "Poison", 1.5, 40.5,
    "Levitate", "Male", 60, // Base HP: 60
    65, 60, 130, 75, 110, // Base stats: Attack: 65, Defense: 60, Sp. Attack: 130, Sp. Defense: 75, Speed: 110
    {
        Move(41, "Shadow Ball", "Ghost", "Special", 80, 15, 100),
        Move(42, "Sludge Bomb", "Poison", "Special", 90, 10, 100),
        Move(43, "Focus Blast", "Fighting", "Special", 120, 5, 70),
        Move(44, "Thunderbolt", "Electric", "Special", 90, 15, 100)
    }
    );

Pokemon lucario(
    448, "Lucario", 100, "Lucarionite", // Assuming Mega Lucario with Lucarionite
    "Fighting", "Steel", 1.2, 57.5,
    "Steadfast", "Male", 70, // Base HP: 70
    145, 88, 140, 70, 112, // Base stats: Attack: 145, Defense: 88, Sp. Attack: 140, Sp. Defense: 70, Speed: 112
    {
        Move(45, "Close Combat", "Fighting", "Physical", 120, 5, 100),
        Move(46, "Flash Cannon", "Steel", "Special", 80, 10, 100),
        Move(47, "Aura Sphere", "Fighting", "Special", 80, 20, 100),
        Move(48, "Extreme Speed", "Normal", "Physical", 80, 5, 100)
    }
    );

Pokemon sceptile(
    254, "Sceptile", 100, "Sceptilite", // Assuming Mega Sceptile with Sceptilite
    "Grass", "Dragon", 1.7, 52.2,
    "Overgrow", "Male", 70, // Base HP: 70
    85, 65, 135, 85, 120, // Base stats: Attack: 85, Defense: 65, Sp. Attack: 135, Sp. Defense: 85, Speed: 120
    {
        Move(49, "Leaf Blade", "Grass", "Physical", 90, 15, 100),
        Move(50, "Dragon Pulse", "Dragon", "Special", 85, 10, 100),
        Move(51, "Focus Blast", "Fighting", "Special", 120, 5, 70),
        Move(52, "Energy Ball", "Grass", "Special", 90, 10, 100)
    }
    );

Pokemon magikarp(
    129, "Magikarp", 100, "None",
    "Water", "", 0.9, 10.0,
    "Swift Swim", "Male", 20, // Base HP: 20
    10, 55, 15, 20, 80, // Base stats: Attack: 10, Defense: 55, Sp. Attack: 15, Sp. Defense: 20, Speed: 80
    {
        Move(53, "Splash", "Normal", "Status", 0, 40, 0), // A non-damaging move
        Move(54, "Tackle", "Normal", "Physical", 40, 35, 100),
        Move(55, "Flail", "Normal", "Physical", 0, 15, 100), // Power depends on HP
        Move(56, "Bounce", "Flying", "Physical", 85, 5, 85)
    }
    );

Pokemon feebas(
    349, "Feebas", 100, "Prism Scale",
    "Water", "", 0.6, 7.4,
    "Swift Swim", "Female", 20, // Base HP: 20
    15, 20, 10, 55, 80, // Base stats: Attack: 15, Defense: 20, Sp. Attack: 10, Sp. Defense: 55, Speed: 80
    {
        Move(57, "Splash", "Normal", "Status", 0, 40, 0), // A non-damaging move
        Move(58, "Tackle", "Normal", "Physical", 40, 35, 100),
        Move(59, "Captivate", "Normal", "Status", 0, 20, 100), // Lowers opponent's Sp. Attack
        Move(60, "Water Pulse", "Water", "Special", 60, 20, 100)
    }
    );


Move dp(2, "Dark Pulse", "Dark", "Special", 80, 15, 100);

// ... and so on for 10 more PokÃ©mon objects with their respective moves
// Feel free to replace these placeholders with actual PokÃ©mon and moves as needed.

Team *team;
Team *team2;

Battle *bat;

std::vector<Pokemon> v;
std::vector<Pokemon> v2;
BattleWindow::BattleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BattleWindow)
{
    ui->setupUi(this);

    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");

    if(pokemondb.open())
        qDebug() << "Open";
    else
        qDebug() << "Closed";

    setTrainerSelected(524);
    setTeamSelected(1000);
    ui->potionPage->hide();
    ui->widget->hide();


}

int BattleWindow::getTrainerSelected(){
    return trainerSelected;
}

void BattleWindow::setTrainerSelected(int t){
    trainerSelected = t;
}

int BattleWindow::getTeamSelected(){
    return teamSelected;
}

void BattleWindow::setTeamSelected(int t){
    teamSelected = t;
}

QString BattleWindow::returnMoveName(int moveid){
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

QString BattleWindow::returnPokeName(int pid){
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



void BattleWindow::loadTeam(std::vector<Pokemon> &v){

    QSqlQuery pokemons;
    pokemons.prepare("SELECT * FROM TrainerPokemon WHERE p_trainerID = (:tid)");
    pokemons.bindValue(":tid", getTeamSelected());
    pokemons.exec();
    int pname = pokemons.record().indexOf("p_id");
    int plevel = pokemons.record().indexOf("tp_level");
    int pmove1 = pokemons.record().indexOf("p_move1ID");
    int pmove2 = pokemons.record().indexOf("p_move2ID");
    int pmove3 = pokemons.record().indexOf("p_move3ID");
    int pmove4 = pokemons.record().indexOf("p_move4ID");
    int item = pokemons.record().indexOf("tp_itemName");
    int pability = pokemons.record().indexOf("p_ability");
    std::vector<Pokemon> mons;
    while(pokemons.next()){


        QString n =  pokemons.value(pname).toString();
        QString pm1 = pokemons.value(pmove1).toString();
        QString pm2 = pokemons.value(pmove2).toString();
        QString pm3 = pokemons.value(pmove3).toString();
        QString pm4 = pokemons.value(pmove4).toString();
        QString ite = pokemons.value(item).toString();
        QString lev = pokemons.value(plevel).toString();
        QString ab = pokemons.value(pability).toString();


        std::vector<int> fakemoves;
        fakemoves.push_back((stoi(pm1.toStdString())));
        fakemoves.push_back((stoi(pm2.toStdString())));
        fakemoves.push_back((stoi(pm3.toStdString())));
        fakemoves.push_back((stoi(pm4.toStdString())));

        std::vector<Move> realmoves;
        for(int m_id : fakemoves){
            Move move;

            QSqlQuery movesquery;
            movesquery.prepare("SELECT * FROM Moves WHERE m_id = (:mid)");
            movesquery.bindValue(":mid",m_id);

            if(movesquery.exec()){

                while(movesquery.next()){
                    // qDebug() << "DEATHNOTE()";
                    QString mid = movesquery.value(0).toString();
                    move.setID(stoi(mid.toStdString()));
                    QString mname = movesquery.value(1).toString();
                    move.setName(mname.toStdString());
                    QString type = movesquery.value(2).toString();
                    move.setType(type.toStdString());
                    QString category = movesquery.value(3).toString();
                    move.setCategory(category.toStdString());
                    QString pp = movesquery.value(4).toString();
                    //qDebug() << pp;
                    move.setPP(stoi(pp.toStdString()));
                   // qDebug() << move.getPP();


                    QString power = movesquery.value(5).toString();
                    //qDebug() << power;
                    //std::cout << power.toStdString();
                    if(power.length() < 2){
                        move.setPower(0);
                    }
                    else{
                        //qDebug() << "the actual fuck are u" << power;
                        move.setPower(stoi(power.toStdString()));
                    }
                    //qDebug() << move.getPower();
                    QString acc = movesquery.value(6).toString();
                    if(acc.length() < 3)
                        move.setAccuracy((100));
                    else{
                        QString accc = QString::fromStdString(acc.toStdString().substr(0, acc.toStdString().length() - 1));
                        move.setAccuracy(stoi(accc.toStdString()));
                    }

                }

                realmoves.push_back(move);
                //for(Move e: realmoves){
                   // qDebug() << e.getName() << e.getPower();
                //}
            }

        }
        Pokemon p;
        QSqlQuery pkz;



        pkz.prepare("SELECT * FROM Pokemon WHERE p_id = (:pid)");

        pkz.bindValue(":pid", stoi(n.toStdString()));

        if(pkz.exec()){

            while(pkz.next()){
                p.setPLevel(stoi(lev.toStdString()));

                QString name = pkz.value(1).toString();
                p.setPName((name.toStdString()));
                QString type1 = pkz.value(5).toString();
                p.setPType1(type1.toStdString());
                QString type2 = pkz.value(6).toString();
                p.setPType2(type2.toStdString());
                QString attack = pkz.value(15).toString();
                p.setPAttack(stoi(attack.toStdString()));
                QString defense = pkz.value(16).toString();
                p.setPDefense(stoi(defense.toStdString()));
                QString spattack = pkz.value(17).toString();
                p.setPSpecialAttack(stoi(spattack.toStdString()));
                QString spdefense = pkz.value(18).toString();
                p.setPSpecialDefense(stoi(spdefense.toStdString()));
                QString hp = pkz.value(14).toString();
                p.setPHP(stoi(hp.toStdString()));
                QString speed = pkz.value(19).toString();
                p.setPSpeed(stoi(speed.toStdString()));
                p.setPHeight(0);
                p.setPWeight(0);
                p.setPGender("male");
                p.setPId(stoi(n.toStdString()));
                p.setPItem(ite.toStdString());
                p.setPAbility(ab.toStdString());
                p.setMoves(realmoves);


            }
        }


        mons.push_back(p);



    }

    for(Pokemon p: mons){
       // qDebug() << "POKEMON IN PARTY" << p.getPName();
        v.push_back(p);
    }
    //return mons;


}

void BattleWindow::loadTeam2again(){

    loadTeam(v);
    loadTeam2(v2);
    ui->pokemonhpbar_2->setMaximum(v[0].getPRHP());
    ui->pokemonhpbar_2->setValue(v[0].getPRHP());
    ui->enemyhpbar->setMaximum(v2[0].getPRHP());
    ui->enemyhpbar->setValue(v2[0].getPRHP());
    team = new Team(v[0], v[1], v[2], v[3], v[4], v[5]);
    team2 = new Team(v2[0], v2[1], v2[2], v2[3], v2[4], v2[5]);
    bat = new Battle(*team, *team2);
    // bat->enemyMove(team2->getPokemon1().getMovesZZZ()[0]);
    bat->dmgPlayer();
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->pushButton_11->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->pushButton_14->setVisible(false);

    ui->pushButton_15->setVisible(false);
    ui->pushButton_16->setVisible(false);
    ui->pushButton_17->setVisible(false);
    ui->pushButton_18->setVisible(false);
    ui->pushButton_19->setVisible(false);
    ui->pushButton_20->setVisible(false);

    std::string myText = "L";
    std::ifstream MyReadFile("C:/Users/nishb/OneDrive/Desktop/Battle/frontsprites.txt");
    std::vector<QString> imageNames;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        imageNames.push_back(QString::fromStdString(myText));
    }
    QString defaultpath = "C:/Users/nishb/OneDrive/Desktop/Battle/back_sprite/";
    QString defaultpathE = "C:/Users/nishb/OneDrive/Desktop/Battle/front_sprites/";
    QString pathpt2 = imageNames[returnPokeId(QString::fromStdString(bat->getPlayerPokemon1())) - 1] + ".png";
    QString pathpte2 = imageNames[returnPokeId(QString::fromStdString(bat->getEnemyPokemon())) - 1] + ".png";
    QString path = defaultpath + pathpt2;
    QString pathe = defaultpathE + pathpte2;
    QPixmap pkman(path);
    QPixmap eman(pathe);
    // v[0].print();
    ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
    ui->playerPic->setPixmap(pkman);
    ui->playerPic->setScaledContents(true);
    ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
    ui->enemyPic->setPixmap(eman);
    ui->enemyPic->setScaledContents(true);
    ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
    ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));

}

void BattleWindow::loadTeam2(std::vector<Pokemon> &v){

    v.clear();
    QSqlQuery pokemons;
    pokemons.prepare("SELECT * FROM TrainerPokemon WHERE p_trainerID = (:trainerid)");
    pokemons.bindValue(":trainerid", (getTrainerSelected()));
    pokemons.exec();
    int pname = pokemons.record().indexOf("p_id");
    int plevel = pokemons.record().indexOf("tp_level");
    int pmove1 = pokemons.record().indexOf("p_move1ID");
    int pmove2 = pokemons.record().indexOf("p_move2ID");
    int pmove3 = pokemons.record().indexOf("p_move3ID");
    int pmove4 = pokemons.record().indexOf("p_move4ID");
    int item = pokemons.record().indexOf("tp_itemName");
    int pability = pokemons.record().indexOf("p_ability");
    std::vector<Pokemon> mons;
    while(pokemons.next()){


        QString n = pokemons.value(pname).toString();
        //qDebug() << "n" << n;
        QString pm1 = pokemons.value(pmove1).toString();
        QString pm2 = pokemons.value(pmove2).toString();
        QString pm3 = pokemons.value(pmove3).toString();
        QString pm4 = pokemons.value(pmove4).toString();
        QString ite = pokemons.value(item).toString();
        QString lev = pokemons.value(plevel).toString();
        QString ab = pokemons.value(pability).toString();


        std::vector<int> fakemoves; //should be fake moves

        fakemoves.push_back((stoi(pm1.toStdString())));
        fakemoves.push_back((stoi(pm2.toStdString())));
        fakemoves.push_back((stoi(pm3.toStdString())));
        fakemoves.push_back((stoi(pm4.toStdString())));

        std::vector<Move> realmoves;
        for(int m_id : fakemoves){
            Move move;

            QSqlQuery movesquery;
            movesquery.prepare("SELECT * FROM Moves WHERE m_id = (:mid)");
            movesquery.bindValue(":mid",m_id);

            if(movesquery.exec()){

                while(movesquery.next()){
                    // qDebug() << "DEATHNOTE()";
                    QString mid = movesquery.value(0).toString();
                    move.setID(stoi(mid.toStdString()));
                    QString mname = movesquery.value(1).toString();
                    move.setName(mname.toStdString());
                    QString type = movesquery.value(2).toString();
                    move.setType(type.toStdString());
                    QString category = movesquery.value(3).toString();
                    move.setCategory(category.toStdString());
                    QString pp = movesquery.value(4).toString();
                    //qDebug() << pp;
                    move.setPP(stoi(pp.toStdString()));
                    // qDebug() << move.getPP();


                    QString power = movesquery.value(5).toString();
                    //qDebug() << power;
                    //std::cout << power.toStdString();
                    if(power.length() < 2){
                        move.setPower(0);
                    }
                    else{
                        //qDebug() << "the actual fuck are u" << power;
                        move.setPower(stoi(power.toStdString()));
                    }
                    //qDebug() << move.getPower();
                    QString acc = movesquery.value(6).toString();
                    if(acc.length() < 3)
                        move.setAccuracy((100));
                    else{
                        QString accc = QString::fromStdString(acc.toStdString().substr(0, acc.toStdString().length() - 1));
                        move.setAccuracy(stoi(accc.toStdString()));
                    }

                }

                realmoves.push_back(move);
                //for(Move e: realmoves){
                // qDebug() << e.getName() << e.getPower();
                //}
            }

        }
        Pokemon p;
        QSqlQuery pkz;


  //  qDebug() << "loading first half worked";
        pkz.prepare("SELECT * FROM Pokemon WHERE p_id = (:pid)");

        pkz.bindValue(":pid", stoi(n.toStdString()));
      //  qDebug() << "loading first half worked";
        if(pkz.exec()){

            while(pkz.next()){
                p.setPLevel(stoi(lev.toStdString()));

                QString name = pkz.value(1).toString();
                p.setPName((name.toStdString()));
                QString type1 = pkz.value(5).toString();
                p.setPType1(type1.toStdString());
                QString type2 = pkz.value(6).toString();
                p.setPType2(type2.toStdString());
                QString attack = pkz.value(15).toString();
                p.setPAttack(stoi(attack.toStdString()));
                QString defense = pkz.value(16).toString();
                p.setPDefense(stoi(defense.toStdString()));
                QString spattack = pkz.value(17).toString();
                p.setPSpecialAttack(stoi(spattack.toStdString()));
                QString spdefense = pkz.value(18).toString();
                p.setPSpecialDefense(stoi(spdefense.toStdString()));
                QString hp = pkz.value(14).toString();
                p.setPHP(stoi(hp.toStdString()));
                QString speed = pkz.value(19).toString();
                p.setPSpeed(stoi(speed.toStdString()));
                p.setPHeight(0);
                p.setPWeight(0);
                p.setPGender("male");
                p.setPId(stoi(n.toStdString()));
                p.setPItem(ite.toStdString());
                p.setPAbility(ab.toStdString());
               // qDebug()<< p.getPName();

                p.setMoves(realmoves);


            }
        }


        mons.push_back(p);



    }

    for(Pokemon p: mons){
        // qDebug() << "POKEMON IN PARTY" << p.getPName();
        v.push_back(p);
    }
    //return mons;


}
int checkIfpFainted() {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        if (bat->getpnHP(i) <= 0) {
            cnt += 1;
        }
    }
    if (cnt == 6) {
        return 1;
    }
    else {
        return 0;
    }
}

int checkIfeFainted() {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        if (bat->getenHP(i) <= 0) {
            cnt += 1;
        }
    }
    if (cnt == 6) {
        return 1;
    }
    else {
        return 0;
    }
}


BattleWindow::~BattleWindow()
{
    delete bat;
    delete team;
    delete team2;
    delete ui;
}

void BattleWindow::openMenu() {
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    if ((bat->getPlayer().getPRHP() < 0.33 * bat->getPlayer().getPHP())) {
        ui->battleText->setText(QString::fromStdString((bat->getPlayer().getPType1()) + " Type Moves Powered Up"));
    }
    ui->widget_2->setVisible(true);
    ui->widget_3->setVisible(true);
    ui->widget_4->setVisible(true);
    ui->widget_5->setVisible(true);
    ui->widget_6->setVisible(true);
    ui->playerHP->setVisible(true);
    ui->playerPic->setVisible(true);
    ui->playerPokemon->setVisible(true);
    ui->pokemonhpbar_2->setVisible(true);
    ui->enemyPokemon->setVisible(true);
    ui->enemyHP->setVisible(true);
    ui->enemyPic->setVisible(true);
    ui->enemyhpbar->setVisible(true);
}

void BattleWindow::closeMenu() {
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
   ui->widget_2->setVisible(false);
    ui->widget_3->setVisible(false);
    ui->widget_4->setVisible(false);
    ui->widget_5->setVisible(false);
    ui->widget_6->setVisible(false);
    ui->playerHP->setVisible(false);
    ui->playerPic->setVisible(false);
    ui->playerPokemon->setVisible(false);
    ui->pokemonhpbar_2->setVisible(false);
    ui->enemyPokemon->setVisible(false);
    ui->enemyHP->setVisible(false);
    ui->enemyPic->setVisible(false);
    ui->enemyhpbar->setVisible(false);

}

void BattleWindow::openFight() {
    ui->pushButton_5->setText(QString::fromStdString(bat->getMoves()[0].getName()));
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setText(QString::fromStdString(bat->getMoves()[1].getName()));
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setText(QString::fromStdString(bat->getMoves()[2].getName()));
    ui->pushButton_7->setVisible(true);
    ui->pushButton_8->setText(QString::fromStdString(bat->getMoves()[3].getName()));
    ui->pushButton_8->setVisible(true);
    ui->widget_2->setVisible(true);
    ui->widget_3->setVisible(true);
    ui->widget_4->setVisible(true);
    ui->widget_5->setVisible(true);
    ui->widget_6->setVisible(true);
    ui->playerHP->setVisible(true);
    ui->playerPic->setVisible(true);
    ui->playerPokemon->setVisible(true);
    ui->pokemonhpbar_2->setVisible(true);
    ui->enemyPokemon->setVisible(true);
    ui->enemyHP->setVisible(true);
    ui->enemyPic->setVisible(true);
    ui->enemyhpbar->setVisible(true);
}

void BattleWindow::closeFight() {
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
}

void BattleWindow::openPokemon() {
    ui->pushButton_9->setText(QString::fromStdString(bat->getPlayerPokemon1()));
    ui->pushButton_10->setText(QString::fromStdString(bat->getPlayerPokemon2()));
    ui->pushButton_11->setText(QString::fromStdString(bat->getPlayerPokemon3()));
    ui->pushButton_12->setText(QString::fromStdString(bat->getPlayerPokemon4()));
    ui->pushButton_13->setText(QString::fromStdString(bat->getPlayerPokemon5()));
    ui->pushButton_14->setText(QString::fromStdString(bat->getPlayerPokemon6()));
    ui->pushButton_9->setVisible(true);
    ui->pushButton_10->setVisible(true);
    ui->pushButton_11->setVisible(true);
    ui->pushButton_12->setVisible(true);
    ui->pushButton_13->setVisible(true);
    ui->pushButton_14->setVisible(true);
}

void BattleWindow::closePokemon() {
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->pushButton_11->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->pushButton_14->setVisible(false);
}

void BattleWindow::openFainted() {
    QTimer::singleShot(5000, [=](){
    bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getPlayerPokemon1()) + " Has fainted"+"\n-----------------\n ");
    ui->moveLog->setText(bat->getmovedone());
    ui->pushButton_19->setText(QString::fromStdString(bat->getPlayerPokemon1()));
    ui->pushButton_17->setText(QString::fromStdString(bat->getPlayerPokemon2()));
    ui->pushButton_18->setText(QString::fromStdString(bat->getPlayerPokemon3()));
    ui->pushButton_16->setText(QString::fromStdString(bat->getPlayerPokemon4()));
    ui->pushButton_20->setText(QString::fromStdString(bat->getPlayerPokemon5()));
    ui->pushButton_15->setText(QString::fromStdString(bat->getPlayerPokemon6()));
    ui->pushButton_19->setVisible(true);
    ui->pushButton_17->setVisible(true);
    ui->pushButton_18->setVisible(true);
    ui->pushButton_16->setVisible(true);
    ui->pushButton_20->setVisible(true);
    ui->pushButton_15->setVisible(true);
    });
}

void BattleWindow::closeFainted() {
    ui->pushButton_19->setVisible(false);
    ui->pushButton_17->setVisible(false);
    ui->pushButton_18->setVisible(false);
    ui->pushButton_16->setVisible(false);
    ui->pushButton_20->setVisible(false);
    ui->pushButton_15->setVisible(false);
}

void BattleWindow::updatePokemon() {




    std::string myText = "L";
    std::ifstream MyReadFile("C:/Users/nishb/OneDrive/Desktop/Battle/frontsprites.txt");
    std::vector<QString> imageNames;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        imageNames.push_back(QString::fromStdString(myText));
    }
    QString defaultpath = "C:/Users/nishb/OneDrive/Desktop/Battle/back_sprite/";
    QString defaultpathE = "C:/Users/nishb/OneDrive/Desktop/Battle/front_sprites/";
    QString pathpt2 = imageNames[returnPokeId(QString::fromStdString(bat->getPlayerPokemon1())) - 1] + ".png";
    QString pathpte2 = imageNames[returnPokeId(QString::fromStdString(bat->getEnemyPokemon())) - 1] + ".png";
    QString path = defaultpath + pathpt2;
    QString pathe = defaultpathE + pathpte2;
    QPixmap pkman(path);
    QPixmap eman(pathe);

    QString playerstuff;
    QString enemystuff;
    qDebug() <<"switchprio = " <<  bat->getswitchprio() ;
    if(bat->getWhoWentFirst() == 1){
        if(bat->getswitchprio() == 3){// u didnt faint and they didnt either
            QTimer::singleShot(1000, [=]() {
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->hide();
                ui->widget_2->show();
                ui->widget_2->startit();
                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));


            });
            QTimer::singleShot(3000, [=]() {
                ui->widget_2->hide();
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->show();
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                 ui->enemyhpbar->setValue(bat->geteHP());
                bat->addToreturnthing(bat->getmovedoneP());
                ui->moveLog->setText(bat->getmovedone());
                bat->addToreturnthing(bat->getmovedoneE());
            });
            QTimer::singleShot(4000, [=]() {
                 ui->widget_5->startit();
            });
            QTimer::singleShot(6000, [=]() {

                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                 ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->moveLog->setText(bat->getmovedone());


            });
            ui->playerPic->setPixmap(pkman);
            ui->enemyPic->setPixmap(eman);
            qDebug() << "You first, no one fainted";

        }
        else if(bat->getswitchprio() == -1){// they fainted
            QTimer::singleShot(1000, [=]() {
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->hide();
                ui->widget_2->show();
                ui->widget_2->startit();
                bat->addToreturnthing(bat->getmovedoneP());
                ui->moveLog->setText(bat->getmovedone());
                });
            QTimer::singleShot(2800, [=](){

                ui->enemyhpbar->setValue(0);
            });
            QTimer::singleShot(3000, [=]() {
                ui->enemyhpbar->setMaximum(bat->geteHP());
                ui->enemyhpbar->setValue(bat->geteHP());

                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                 ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->moveLog->setText(bat->getmovedone());
                ui->enemyPic->setPixmap(eman);
                ui->playerPic->setPixmap(pkman);

            });
            qDebug() << "You first, they fainted";

        }
        else if(bat->getswitchprio() == 1){// u fainted but went first

            QTimer::singleShot(1000, [=]() {
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->hide();
                ui->widget_2->show();
                ui->widget_2->startit();
                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));

                bat->addToreturnthing(bat->getmovedoneP());
               // ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));

            });
            QTimer::singleShot(3000, [=]() {
                ui->widget_2->hide();
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->show();
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                ui->enemyhpbar->setValue(bat->geteHP());
                ui->moveLog->setText(bat->getmovedone());
                bat->addToreturnthing(bat->getmovedoneE());

            });
            QTimer::singleShot(4000, [=]() {
                ui->widget_5->startit();
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));


            });
            QTimer::singleShot(6000, [=]() {

                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->pokemonhpbar_2->setValue(0);
                ui->moveLog->setText(bat->getmovedone());


            });
            qDebug() << "You first, u fainted";
            ui->playerPic->setPixmap(pkman);
            ui->enemyPic->setPixmap(eman);
        }
        else if(bat->getswitchprio() == 0){// u switched


            QTimer::singleShot(1000, [=]() {

                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                bat->addToreturnthing(bat->getmovedoneP());
                ui->moveLog->setText(bat->getmovedone());
                bat->addToreturnthing(bat->getmovedoneE());
                ui->widget_2->hide();
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->show();
                ui->playerPic->setPixmap(pkman);
                ui->enemyPic->setPixmap(eman);
                ui->enemyhpbar->setValue(bat->geteHP());

            });
            QTimer::singleShot(2000, [=]() {
                ui->widget_5->startit();

            });
            QTimer::singleShot(4000, [=]() {

                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->pokemonhpbar_2->setValue(bat->getpHP());

                ui->moveLog->setText(bat->getmovedone());



            });
            qDebug() << "switch";
        }
        else if(bat->getswitchprio() == 4){// u switched after u fainted
            QTimer::singleShot(1000, [=]() {
                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->pokemonhpbar_2->setMaximum(bat->getpHP());
                ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->playerPic->setPixmap(pkman);
            });
            qDebug() << "switched after death";
        }
    }
    else{
        if(bat->getswitchprio() == 3){// no one fainted
            ui->widget_2->hide();
            ui->widget_3->hide();
            ui->widget_4->hide();
            ui->widget_5->show();
            QTimer::singleShot(1000, [=]() {
                 ui->widget_5->startit();
                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));



            });
            QTimer::singleShot(3000, [=]() {
                ui->widget_2->show();
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->hide();
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                bat->addToreturnthing(bat->getmovedoneE());
                 ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->moveLog->setText(bat->getmovedone());
                bat->addToreturnthing(bat->getmovedoneP());
            });
            QTimer::singleShot(4000, [=]() {
                ui->widget_2->startit();

            });
            QTimer::singleShot(6000, [=]() {

                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                ui->enemyhpbar->setValue(bat->geteHP());
                ui->moveLog->setText(bat->getmovedone());

            });
            qDebug() << "They first, no one fainted" << bat->getmovedoneP();
            ui->enemyPic->setPixmap(eman);
            ui->playerPic->setPixmap(pkman);
        }
        else if(bat->getswitchprio() == -1){// they fainted but went first
            ui->widget_2->hide();
            ui->widget_3->hide();
            ui->widget_4->hide();
            ui->widget_5->show();
            QTimer::singleShot(1000, [=]() {
                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));

                ui->widget_5->startit();
                bat->addToreturnthing(bat->getmovedoneE());
            });
            QTimer::singleShot(3000, [=]() {
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                 ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->moveLog->setText(bat->getmovedone());
                bat->addToreturnthing(bat->getmovedoneP());
                ui->widget_2->show();
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->hide();

            });
            QTimer::singleShot(4000, [=]() {
               ui->widget_2->startit();
            });
            QTimer::singleShot(5000, [=]() {
                 ui->enemyhpbar->setValue(bat->geteHP());
            });
            QTimer::singleShot(6000, [=]() {
                ui->enemyhpbar->setMaximum(bat->geteHP());
                ui->enemyhpbar->setValue(bat->geteHP());
                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                ui->moveLog->setText(bat->getmovedone());
                ui->enemyPic->setPixmap(eman);
                ui->playerPic->setPixmap(pkman);
            });

            qDebug() << "They first, they fainted";
        }
        else if(bat->getswitchprio() == 0){// u switched


            QTimer::singleShot(1000, [=]() {

                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->pokemonhpbar_2->setValue(bat->getpHP());
                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));
                bat->addToreturnthing(bat->getmovedoneP());
                ui->moveLog->setText(bat->getmovedone());
                bat->addToreturnthing(bat->getmovedoneE());
                ui->widget_2->hide();
                ui->widget_3->hide();
                ui->widget_4->hide();
                ui->widget_5->show();
                ui->playerPic->setPixmap(pkman);
                ui->enemyPic->setPixmap(eman);

            });
            QTimer::singleShot(2000, [=]() {
                ui->widget_5->startit();

            });
            QTimer::singleShot(4000, [=]() {

                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->pokemonhpbar_2->setValue(bat->getpHP());

                ui->moveLog->setText(bat->getmovedone());



            });
            qDebug() << "switch";
        }
        else if (bat->getswitchprio() == 1){// u fainted
            ui->widget_2->hide();
            ui->widget_3->hide();
            ui->widget_4->hide();
            ui->widget_5->show();
            QTimer::singleShot(1000, [=]() {
                ui->widget_5->startit();
                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                 ui->pokemonhpbar_2->setValue(bat->getpHP());
                qDebug() << "Enemy went first";
                bat->addToreturnthing(bat->getmovedoneE());

                ui->moveLog->setText(bat->getmovedone());
               // bat->addToreturnthing(bat->getmovedoneP());
                ui->enemyPokemon->setText(QString::fromStdString(bat->getEnemyPokemon()));
                ui->enemyHP->setText(QString::fromStdString(std::to_string(bat->geteHP())));

            });

            QTimer::singleShot(3000, [=]() {
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                 ui->pokemonhpbar_2->setValue(0);
                 ui->moveLog->setText(bat->getmovedone());


            });
            ui->enemyPic->setPixmap(eman);
            ui->playerPic->setPixmap(pkman);

            qDebug() << "They first, u fainted";
            }
        else if(bat->getswitchprio() == 4){// u switched after u fainted
            QTimer::singleShot(1000, [=]() {
                ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
                ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
                ui->enemyPic->setPixmap(eman);
                ui->playerPic->setPixmap(pkman);
                ui->pokemonhpbar_2->setMaximum(bat->getpHP());
                ui->pokemonhpbar_2->setValue(bat->getpHP());

            });
            qDebug() << "switched after death";
        }

    }
   // ui->moveLog->setText(bat->getmovedone());




   //connect(timer, SIGNAL(timeout()),this,SLOT(MySlot()));

   //qDebug() <<timer->remainingTime();
  // delete timer;

}

void BattleWindow::on_pushButton_clicked()
{
    // Hide all buttons
    closeMenu();
    openFight();
}

void BattleWindow::on_pushButton_2_clicked()
{
    ui->potionPage->show();
    closeMenu();
}


void BattleWindow::on_pushButton_3_clicked()
{
    closeMenu();
    openPokemon();
}


void BattleWindow::on_pushButton_4_clicked()
{
    this->hide();
    MainWindow *bt = new MainWindow();
    bt->show();


}


void BattleWindow::on_pushButton_5_clicked()
{

    bat->turn(bat->getMoves()[0], bat->getEnemyMoves()[rand() % 4]);
    if (bat->geteHP() <= 0) {
        if (checkIfeFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
            bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        }
    }

            updatePokemon();


    closeFight();
    if (bat->getpHP() <= 0) {
        if (checkIfpFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
            openFainted();
        }
    }
    else {
        openMenu();
        ui->widget_2->setVisible(true);
        ui->widget_3->setVisible(true);
        ui->widget_4->setVisible(true);
        ui->widget_5->setVisible(true);
        ui->widget_6->setVisible(true);
    }
}


void BattleWindow::on_pushButton_7_clicked()
{

    bat->turn(bat->getMoves()[2], bat->getEnemyMoves()[rand() % 4]);
    if (bat->geteHP() <= 0) {
        if (checkIfeFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        };
    }
    updatePokemon();
    closeFight();
    if (bat->getpHP() <= 0) {
        if (checkIfpFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
            openFainted();
        }
    }
    else {
        openMenu();
        ui->widget_2->setVisible(true);
        ui->widget_3->setVisible(true);
        ui->widget_4->setVisible(true);
        ui->widget_5->setVisible(true);
        ui->widget_6->setVisible(true);
    }
}


void BattleWindow::on_pushButton_6_clicked()
{

    bat->turn(bat->getMoves()[1], bat->getEnemyMoves()[rand() % 4]);
    if (bat->geteHP() <= 0) {
        if (checkIfeFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();

        }
    }
    updatePokemon();
    closeFight();
    if (bat->getpHP() <= 0) {
        if (checkIfpFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
            openFainted();
        }
    }
    else {
        openMenu();

    }
}


void BattleWindow::on_pushButton_8_clicked()
{

    bat->turn(bat->getMoves()[3], bat->getEnemyMoves()[rand() % 4]);
    if (bat->geteHP() <= 0) {
        if (checkIfeFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
            bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        }
    }
    updatePokemon();
    closeFight();
    if (bat->getpHP() <= 0) {
        if (checkIfpFainted()) {
            this->hide();
            MainWindow *mw = new MainWindow();
            mw->show();
        }
        else {
            openFainted();
        };
    }
    else {
        openMenu();
    }
}


void BattleWindow::on_pushButton_9_clicked()
{
    if (bat->getpHP() <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");

    }
    else {
        ui->battleText->setText("This Pokemon is Already Out");
        closePokemon();
        openMenu();
    }
}



void BattleWindow::on_pushButton_10_clicked()
{
    if (bat->getpnHP(2) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
        bat->addToreturnthing("This Pokemon is Fainted");    }
    else {
        bat->switchPokemon2();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
         bat->addToreturnthing(("You sent out " + bat->getPlayerPokemon1()).c_str());
        bat->turn(bat->getEnemyMoves()[0]);
        updatePokemon();
        if (bat->geteHP() <= 0) {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        }
        closePokemon();
        if (bat->getpHP() <= 0) {
            if (checkIfpFainted()) {

            }
            else {
                bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getPlayerPokemon1()) + " Has fainted"+"\n-----------------\n ");

                openFainted();
            }
        }
        else {
            openMenu();
        }
    }
}


void BattleWindow::on_pushButton_11_clicked()
{
    if (bat->getpnHP(3) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
        bat->addToreturnthing("This Pokemon is Fainted");    }
    else {
        bat->switchPokemon3();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
         bat->addToreturnthing(("You sent out " + bat->getPlayerPokemon1()).c_str());
        bat->turn(bat->getEnemyMoves()[0]);
        updatePokemon();
        if (bat->geteHP() <= 0) {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        }
        closePokemon();
        if (bat->getpHP() <= 0) {
            if (checkIfpFainted()) {

            }
            else {
                bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getPlayerPokemon1()) + " Has fainted"+"\n-----------------\n ");

                openFainted();
            }
        }
        else {
            openMenu();
        }
    }
}




void BattleWindow::on_pushButton_12_clicked()
{
    if (bat->getpnHP(4) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
        bat->addToreturnthing("This Pokemon is Fainted");

    }
    else {
        bat->switchPokemon4();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        bat->addToreturnthing(("You sent out " + bat->getPlayerPokemon1()).c_str());

        bat->turn(bat->getEnemyMoves()[0]);
        updatePokemon();
        if (bat->geteHP() <= 0) {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        }
        closePokemon();
        if (bat->getpHP() <= 0) {
            if (checkIfpFainted()) {

            }
            else {
                bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getPlayerPokemon1()) + " Has fainted"+"\n-----------------\n ");

                openFainted();
            }
        }
        else {
            openMenu();
        }
    }
}




void BattleWindow::on_pushButton_13_clicked()
{
    if (bat->getpnHP(5) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
        bat->addToreturnthing("This Pokemon is Fainted");

    }
    else {
        bat->switchPokemon5();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        bat->addToreturnthing(("You sent out " + bat->getPlayerPokemon1()).c_str());

        bat->turn(bat->getEnemyMoves()[0]);
        updatePokemon();
        if (bat->geteHP() <= 0) {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");

            bat->eswitchPokemon();
        }
        closePokemon();
        if (bat->getpHP() <= 0) {
            if (checkIfpFainted()) {

            }
            else {
                openFainted();
                  bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getPlayerPokemon1()) + " Has fainted"+"\n-----------------\n ");
            }
        }
        else {
            openMenu();
        }
    }
}


void BattleWindow::on_pushButton_14_clicked()
{
    if (bat->getpnHP(6) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
        bat->addToreturnthing("This Pokemon is Fainted");
    }
    else {
        bat->switchPokemon6();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        bat->addToreturnthing(("You sent out " + bat->getPlayerPokemon1()).c_str());
        bat->turn(bat->getEnemyMoves()[0]);
        updatePokemon();
        if (bat->geteHP() <= 0) {
             bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getEnemyPokemon()) + " Has fainted"+"\n-----------------\n ");
            bat->eswitchPokemon();
        }
        closePokemon();
        if (bat->getpHP() <= 0) {
            if (checkIfpFainted()) {

            }
            else {
                openFainted();
                 bat->addToreturnthing("----------------- \n" + QString::fromStdString(bat->getPlayerPokemon1()) + " Has fainted"+"\n-----------------\n ");
            }
        }
        else {
            openMenu();
        }
    }
}


void BattleWindow::on_pushButton_19_clicked()
{
    if (bat->getpHP() <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
    }
    else {
        ui->battleText->setText("This Pokemon is Already Out");
        closeFainted();
        openMenu();
    }
}


void BattleWindow::on_pushButton_17_clicked()
{
    if (bat->getpnHP(2) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
    }
    else {
        bat->switchPokemon2();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        updatePokemon();
        closeFainted();
        openMenu();
    }
}


void BattleWindow::on_pushButton_18_clicked()
{
    if (bat->getpnHP(3) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
    }
    else {
        bat->switchPokemon3();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        updatePokemon();
        closeFainted();
        openMenu();
    }
}


void BattleWindow::on_pushButton_16_clicked()
{
    if (bat->getpnHP(4) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
    }
    else {
        bat->switchPokemon4();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        updatePokemon();
        closeFainted();
        openMenu();
    }
}


void BattleWindow::on_pushButton_20_clicked()
{
    if (bat->getpnHP(5) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
    }
    else {
        bat->switchPokemon5();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        updatePokemon();
        closeFainted();
        openMenu();
    }
}


void BattleWindow::on_pushButton_15_clicked()
{
    if (bat->getpnHP(6) <= 0) {
        ui->battleText->setText("This Pokemon is Fainted");
    }
    else {
        bat->switchPokemon6();
        ui->battleText->setText(("You sent out " + bat->getPlayerPokemon1()).c_str());
        updatePokemon();
        closeFainted();
        openMenu();
    }
}

int BattleWindow::returnPokeId(QString pname){
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

void BattleWindow::on_pushButton_21_clicked()
{
    openMenu();
    ui->potionPage->hide();
}


void BattleWindow::on_pushButton_22_clicked()
{
    HPBasedItem pot = HPBasedItem("potion", 20);
    bat->useIt(pot);
    ui->playerPokemon->setText(QString::fromStdString(bat->getPlayerPokemon1()));
    ui->playerHP->setText(QString::fromStdString(std::to_string(bat->getpHP())));
    ui->pokemonhpbar_2->setValue(bat->getpHP());
}

