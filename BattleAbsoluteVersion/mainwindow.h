#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "createteam.h"
#include "battlewindow.h"
#include "viewpokemonwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_createTeamButton_clicked();

    void on_battleWindowButton_clicked();
    void on_pushButton_3_clicked();



    void on_teamsDrop_activated(int index);

public slots:
    void on_pushButton_clicked();
    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    createteam *c;
    BattleWindow *battlewindow;
    ViewPokemonWindow *vp;
};
#endif // MAINWINDOW_H
