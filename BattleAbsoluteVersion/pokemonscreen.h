#ifndef POKEMONSCREEN_H
#define POKEMONSCREEN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <pokemon.h>
namespace Ui {
class PokemonScreen;
}

class PokemonScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PokemonScreen(QWidget *parent = nullptr);
    PokemonScreen();
    ~PokemonScreen();

    void setPokemon(QString name);
    void setPokemonID(QString id);
    void setPokemonAtt(QString attack);
    void setPokemonDef(QString defense);
    void setPokemonHp(QString hp);
    void setPokemonSpAtt(QString spattack);
    void setPokemonSpDef(QString spdef);
    void setType1(QString type1);
    void setType2(QString type2);
    void addMovesToBox(std::vector<QString> moves);
    void addSinguarMoveAsOption(QString move);
    void addItemOption(QString move);
    QString getType1();
    void setSpeed(QString speed);
    void loadPImage(int pokemonID);
private slots:
    void on_move_4_activated(int index);

    void on_move_3_activated(int index);

    void on_move_2_activated(int index);

    void on_move_1_activated(int index);

    void on_itemselect_activated(int index);

    void on_saveButton_clicked();

    void on_doneButton_clicked();

private:
    Ui::PokemonScreen *ui;
    Pokemon *p;
    //MainWindow *mwindow;
};

#endif // POKEMONSCREEN_H
