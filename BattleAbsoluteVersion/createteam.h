#ifndef CREATETEAM_H
#define CREATETEAM_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "pokemonscreen.h"
namespace Ui {
class createteam;
}

class createteam : public QDialog
{
    Q_OBJECT

public:
    explicit createteam(QWidget *parent = nullptr);
    ~createteam();

private slots:
    void on_pushButton_clicked();

    void on_back_clicked();

    void on_pokemon1_clicked();

private:
    Ui::createteam *ui;
    PokemonScreen *p1;

};

#endif // CREATETEAM_H
