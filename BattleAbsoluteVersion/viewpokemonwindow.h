#ifndef VIEWPOKEMONWINDOW_H
#define VIEWPOKEMONWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "pokemon.h"
#include <vector>
#include "qstring.h"


namespace Ui {
class ViewPokemonWindow;
}

class ViewPokemonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewPokemonWindow(QWidget *parent = nullptr);
    ~ViewPokemonWindow();
    void load();
    void display();
    QString returnMoveName(int moveid);
    QString returnPokeName(int pid);
    void loadInPokemon(int position,std::vector<QString> &stats);
    void addButton();
    void removeButton();
    std::vector<QString> returnStats(int id);
    int returnPokeID(QString pname);
    int returnMoveIDD(QString mname);
    void loadTypes();
    void loadingImage(std::vector<QString> ids);
    void removeLabel();
    void setTrainerId(int i);
    int getTrainerId();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_send1_clicked();

    void on_send2_clicked();

    void on_send3_clicked();

    void on_send4_clicked();

    void on_send5_clicked();

    void on_send6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


private:
    Ui::ViewPokemonWindow *ui;
    std::vector<Pokemon> team;
    int trainerId;
};

#endif // VIEWPOKEMONWINDOW_H
