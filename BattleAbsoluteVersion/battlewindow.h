#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QMainWindow>
#include <Pokemon.h>
#include<vector>
QT_BEGIN_NAMESPACE
namespace Ui {
class BattleWindow;
}
QT_END_NAMESPACE

class BattleWindow : public QMainWindow
{
    Q_OBJECT

public:
    BattleWindow(QWidget *parent = nullptr);
    ~BattleWindow();
     void loadTeam(std::vector<Pokemon> &v);
    void loadTeam2(std::vector<Pokemon> &v);
    QString returnMoveName(int moveid);
    QString returnPokeName(int pid);
     int returnPokeId(QString name);
    int getTrainerSelected();
     void setTrainerSelected(int t);
    int getTeamSelected();
    void setTeamSelected(int t);
    void loadTeam2again();

private slots:
    void on_pushButton_clicked();

    void openMenu();

    void closeMenu();

    void openFight();

    void closeFight();

    void openPokemon();

    void closePokemon();

    void openFainted();

    void closeFainted();

    void updatePokemon();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_15_clicked();




    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::BattleWindow *ui;
    int trainerSelected;
    int teamSelected;
};
#endif // MAINWINDOW_H
